#include "Character.h"
#include "Exceptions.h"


using std::cout;

void exceptionTest()
{
    try
    {
        throw mtm::IllegalArgument();
    }
    catch(mtm::Exception& e)
    {
        cout << e.what() << '\n';
    }
    
}

int main ()
{
    exceptionTest();
}