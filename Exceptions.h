#ifndef HW2_EXCEPTIONS_H
#define HW2_EXECPTIONS_H

#include <stdexcept>


namespace mtm
{
    class Exception : std::exception {};         // OVERWRITE WHAT() FUNCTION

    class IllegalArgument : public Exception {}; // OVERWRITE WHAT() FUNCTION

    class CellEmpty : public Exception {};       // OVERWRITE WHAT() FUNCTION

    class MoveTooFar : public Exception {};      

    class CellOccupied : public Exception {};

    class OutOfRange : public Exception {};

    class OutOfAmmo : public Exception {};

    class IllegalTarget : public Exception {};

    
}

#endif // HW2_EXCEPTIONS