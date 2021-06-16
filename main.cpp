#include <assert.h>
#include "Character.h"
#include "Exceptions.h"
#include "Auxiliaries.h"
#include "Game.h"

#include "Board.h"

using std::cout;
using std::endl;
using mtm::GridPoint;
using mtm::Character;
using mtm::Game;
using mtm::SNIPER;
using mtm::MEDIC;
using mtm::SOLDIER;
using mtm::POWERLIFTERS;
using mtm::CROSSFITTERS;

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
            assert(board.isCellInBoard(coordinate));
            assert(!board.isCellOccupied(coordinate));
        }
    }

    GridPoint coordinate = GridPoint(1, 2);
    assert(board.getCharacter(coordinate) == nullptr);

    coordinate = GridPoint(5, 2);
    assert(!board.isCellInBoard(coordinate));
    coordinate = GridPoint(-1, 2);
    assert(!board.isCellInBoard(coordinate));
    // try
    // {
        
    // }

    cout << "[OK]" << endl;
}

void basicTest1()
{
    cout << "Running basicTest1... ";
    std::shared_ptr<Character> sniper1 = Game::makeCharacter(SNIPER, POWERLIFTERS, 1, 4, 4, 4);
    std::shared_ptr<Character> sniper2 = Game::makeCharacter(SNIPER, CROSSFITTERS, 1, 4, 4, 4);
    assert(sniper1->getAscii() == 'S');
    assert(sniper2->getAscii() == 's');


    Game game1 = Game(4, 4);
    GridPoint co = GridPoint(0,0);
    game1.addCharacter(co, sniper1);
    game1.addCharacter(GridPoint(1,3), sniper1);
    //assert(game1.isOver());
    game1.addCharacter(GridPoint(0,1), sniper2);
    //assert(!(game1.isOver()));
    
    try { game1.addCharacter(GridPoint(-1,0), sniper1); }
    catch (mtm::IllegalCell& e) {}
    
    try { game1.addCharacter(GridPoint(0,0),  sniper1); }
    catch (mtm::CellOccupied& e) {}

    

    cout << "[OK]" << endl;;
}

int main ()
{
    exceptionTest();
    boardTest1(); // Private
    basicTest1(); // Private
}