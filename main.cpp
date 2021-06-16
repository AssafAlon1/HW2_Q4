#include <assert.h>
#include "Character.h"
#include "Exceptions.h"
//#include "Auxiliaries.h"

#include "Board.h"

using std::cout;
using std::endl;
using mtm::GridPoint;
using mtm::Character;

using mtm::Board; // Private

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

void boardTest1()
{
    cout << "Running boardTest1... ";
    Board board = Board(4, 4);
    
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            GridPoint coordinate = GridPoint(i, j);
            assert(board.isCellOccupied(coordinate) == false);
        }
    }

    GridPoint coordinate = GridPoint(1, 2);
    assert(board.getCharacter(coordinate) == nullptr);

    cout << "[OK]" << endl;
}


int main ()
{
    //exceptionTest();
    boardTest1(); // Private
}