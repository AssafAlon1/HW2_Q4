#include "Exceptions.h"

namespace mtm
{
    const std::string Exception::MESSAGE_TEMPLATE = "A game related error has occurred: ";

    Exception::Exception(std::string inner_exception_name)
    {
        message = MESSAGE_TEMPLATE + inner_exception_name;
    }

    const char* Exception::what() const noexcept
    {
        // std::string return_string = "A game related error has occured: ";
        // return_string.append(this->exception_name);
        // return return_string.c_str();
        return message.c_str();
    }

    IllegalArgument::IllegalArgument() : Exception(std::string("IllegalArgument"))
    {
    }

    IllegalCell::IllegalCell() : Exception(std::string("IllegalCell"))
    {
    }

    CellEmpty::CellEmpty() : Exception(std::string("CellEmpty"))
    {
    }

    MoveTooFar::MoveTooFar() : Exception(std::string("MoveTooFar"))
    {
    }

    CellOccupied::CellOccupied() : Exception(std::string("CellOccupied"))
    {
    }

    OutOfRange::OutOfRange() : Exception(std::string("OutOfRange"))
    {
    }

    OutOfAmmo::OutOfAmmo() : Exception(std::string("OutOfAmmo"))
    {
    }

    IllegalTarget::IllegalTarget() : Exception(std::string("IllegalTarget"))
    {
    }
}