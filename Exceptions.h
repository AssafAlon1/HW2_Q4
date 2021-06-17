#ifndef HW2_EXCEPTIONS_H
#define HW2_EXECPTIONS_H

#include <stdexcept>
//#include <typeinfo>
#include <iostream>
//#include <string>

namespace mtm
{
    class Exception : std::exception {
    public:
        Exception(std::string name);
        ~Exception() = default;
        const char* what() const noexcept override;
    private:
        std::string exception_name;
    };

    class IllegalArgument : public Exception 
    {
    public:
        IllegalArgument();
        ~IllegalArgument() = default;
    };

    class IllegalCell : public Exception 
    {
    public:
        IllegalCell();
        ~IllegalCell() = default;
    };

    class CellEmpty : public Exception 
    {
    public:
        CellEmpty();
        ~CellEmpty() = default;
    };     

    class MoveTooFar : public Exception 
    {
    public:
        MoveTooFar();
        ~MoveTooFar() = default;
    };      

    class CellOccupied : public Exception 
    {
    public:
        CellOccupied();
        ~CellOccupied() = default;
    };

    class OutOfRange : public Exception 
    {
    public:
        OutOfRange();
        ~OutOfRange() = default;
    };

    class OutOfAmmo : public Exception 
    {
    public:
        OutOfAmmo();
        ~OutOfAmmo() = default;
    };

    class IllegalTarget : public Exception 
    {
    public:
        IllegalTarget();
        ~IllegalTarget() = default;
    };
    
}

#endif // HW2_EXCEPTIONS