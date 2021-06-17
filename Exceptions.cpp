#include "Exceptions.h"

namespace mtm
{

    Exception::Exception(std::string name)
    {
        exception_name = name;
    }

    const char* Exception::what() const noexcept
    {
        //std::cout << typeid(*this).name();
        std::string return_string = "A game related error has occured: ";
        return_string.append(this->exception_name);
        return return_string.c_str();
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