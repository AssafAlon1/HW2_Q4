#ifndef HW2_EXCEPTIONS_H
#define HW2_EXECPTIONS_H

#include <stdexcept>
#include <typeinfo>
#include <iostream>
//#include <string>

namespace mtm
{
    class Exception : std::exception {
    public:
        virtual const char* what()
        {
            //std::cout << typeid(*this).name();
            std::string return_string = "A game related error has occured: ";
            return_string.append(typeid(*this).name());
            return return_string.c_str();
        }
    };

    class IllegalArgument : public Exception {}; // OVERWRITE WHAT() FUNCTION

    class IllegalCell : public Exception {};

    class CellEmpty : public Exception {};       // OVERWRITE WHAT() FUNCTION

    class MoveTooFar : public Exception {};      

    class CellOccupied : public Exception {};

    class OutOfRange : public Exception {};

    class OutOfAmmo : public Exception {};

    class IllegalTarget : public Exception {};
    
}

#endif // HW2_EXCEPTIONS