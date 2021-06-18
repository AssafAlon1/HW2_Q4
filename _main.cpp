#include <assert.h>
#include <iostream>
#include <fstream>

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
using mtm::Team;


using mtm::Board; // Private

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
    try
    {
        board = Board(-1, 3);
        throw std::exception();
    }
    catch (mtm::IllegalArgument& e) {}

    cout << "[OK]" << endl;
}

void basicTest1()
{
    cout << "Running basicTest1... ";
    std::shared_ptr<Character> sniper1 = Game::makeCharacter(SNIPER, POWERLIFTERS, 1, 4, 4, 4);
    std::shared_ptr<Character> sniper2 = Game::makeCharacter(SNIPER, CROSSFITTERS, 1, 4, 4, 4);
    assert(sniper1 != nullptr && sniper2 != nullptr);
    assert(sniper1->getAscii() == 'N'); // Private
    assert(sniper2->getAscii() == 'n'); // Private


    Game game1 = Game(4, 4);
    GridPoint co = GridPoint(0,0);
    game1.addCharacter(co, sniper1);
    game1.addCharacter(GridPoint(1,3), sniper1);
    game1.addCharacter(GridPoint(0,1), sniper2);
    assert(!(game1.isOver()));
    
    try {
        game1.addCharacter(GridPoint(-1,0), sniper1);

    }
    catch (mtm::IllegalCell& e) {}
    
    try {
        game1.addCharacter(GridPoint(0,0),  sniper1);
        throw;
    }
    catch (mtm::CellOccupied& e) {}

    try {
        game1.move(GridPoint(0,0), GridPoint(3, 3));
        throw;
        }
    catch (mtm::MoveTooFar& e) {}



    cout << "[OK]" << endl;;
}

void medicTest1()
{
    cout << "Running gameTest1...  ";
    std::ofstream out_file;
    out_file.open("../output/actual1.txt");
    std::shared_ptr<Character> medic1 = Game::makeCharacter(MEDIC, POWERLIFTERS, 4, 4, 4, 4);
    std::shared_ptr<Character> medic2 = Game::makeCharacter(MEDIC, POWERLIFTERS, 4, 4, 4, 4);
    std::shared_ptr<Character> medic3 = Game::makeCharacter(MEDIC, POWERLIFTERS, 4, 4, 4, 4);
    std::shared_ptr<Character> medic4 = Game::makeCharacter(MEDIC, POWERLIFTERS, 4, 4, 4, 4);
    std::shared_ptr<Character> medic5 = Game::makeCharacter(MEDIC, CROSSFITTERS, 4, 4, 4, 4);
    std::shared_ptr<Character> medic6 = Game::makeCharacter(MEDIC, CROSSFITTERS, 4, 4, 4, 4);
    std::shared_ptr<Character> medic7 = Game::makeCharacter(MEDIC, CROSSFITTERS, 4, 4, 4, 4);
    std::shared_ptr<Character> medic8 = Game::makeCharacter(MEDIC, CROSSFITTERS, 4, 4, 4, 4);
    assert(medic1 != nullptr && medic2 != nullptr);
    Team winning_team = POWERLIFTERS;

    // Add medics
    Game game1 = Game(4, 4);
    assert(game1.makeCharacter(SNIPER, POWERLIFTERS, 2, 0, 0, 0) != nullptr);
    assert(!game1.isOver()); // No characters -> no victory
    game1.addCharacter(GridPoint(0,0), medic1);
    assert(game1.isOver()); // 1 character -> victory to powerlifters
    assert(game1.isOver(&winning_team));
    out_file << "Winners: " << winning_team << endl;
    game1.addCharacter(GridPoint(0,1), medic2);
    game1.addCharacter(GridPoint(0,2), medic3);
    game1.addCharacter(GridPoint(0,3), medic4);
    assert(game1.isOver());

    game1.addCharacter(GridPoint(3,0), medic5);
    assert(!game1.isOver());
    game1.addCharacter(GridPoint(3,1), medic6);
    game1.addCharacter(GridPoint(3,2), medic7);
    game1.addCharacter(GridPoint(3,3), medic8);
    assert(!game1.isOver());

    out_file << game1 << endl;

    // Move around
    game1.move(GridPoint(0,0), GridPoint(2,0));
    game1.move(GridPoint(0,1), GridPoint(2,1));
    game1.move(GridPoint(0,2), GridPoint(2,2));
    game1.move(GridPoint(0,3), GridPoint(2,3));

    game1.move(GridPoint(3,0), GridPoint(0,0));
    game1.move(GridPoint(3,1), GridPoint(0,1));
    game1.move(GridPoint(3,2), GridPoint(0,2));
    game1.move(GridPoint(3,3), GridPoint(0,3));

    out_file << game1 << endl;
    
    game1.move(GridPoint(0,0), GridPoint(1,3));
    game1.move(GridPoint(0,1), GridPoint(0,0));
    game1.move(GridPoint(0,2), GridPoint(1,1));
    game1.move(GridPoint(0,3), GridPoint(0,2));

    out_file << game1 << endl;

    try { game1.move(GridPoint(1,3), GridPoint(1,3)); } // Can't heal self
    catch (mtm::CellOccupied& e) { out_file << e.what() << std::endl; }

    try {  game1.move(GridPoint(3,3), GridPoint(1,3));  } // Can't move nothing
    catch (mtm::CellEmpty& e) {  out_file << e.what() << std::endl;  }

    try { game1.move(GridPoint(4,3), GridPoint(1,3)); } // Source cell not in board
    catch (mtm::IllegalCell& e) {  out_file << e.what() << std::endl;  }

    try { game1.makeCharacter(SNIPER, POWERLIFTERS, 0, 1, 1, 1); } // Character parameters are bad
    catch (mtm::IllegalArgument& e) {  out_file << e.what() << std::endl;  }

    try {  game1.attack(GridPoint(1,3), GridPoint(1,3)); } // Destination cell is empty
    catch (mtm::IllegalTarget& e) { out_file << e.what() << std::endl; }

    try {  game1.attack(GridPoint(3,3), GridPoint(1,3));  }
    catch (mtm::CellEmpty& e) {  out_file << e.what() << std::endl;  }

    try { game1.attack(GridPoint(4,3), GridPoint(1,3)); } // Source cell not in board
    catch (mtm::IllegalCell& e) {  out_file << e.what() << std::endl;  }

    game1.attack(GridPoint(2, 1), GridPoint(2, 0)); // 6 heals, no ammo issue
    game1.attack(GridPoint(2, 1), GridPoint(2, 0));
    game1.attack(GridPoint(2, 1), GridPoint(2, 0));
    game1.attack(GridPoint(2, 1), GridPoint(2, 0));
    game1.attack(GridPoint(2, 1), GridPoint(2, 0));
    game1.attack(GridPoint(2, 1), GridPoint(2, 0));
    game1.attack(GridPoint(2, 0), GridPoint(2, 1));
    game1.attack(GridPoint(0, 0), GridPoint(2, 0)); // 4 attacks
    game1.attack(GridPoint(0, 0), GridPoint(2, 0));
    game1.attack(GridPoint(0, 0), GridPoint(2, 0));
    game1.attack(GridPoint(0, 0), GridPoint(2, 0));
    
    try { game1.attack(GridPoint(0, 0), GridPoint(2, 0));  } // Out of ammo
    catch (mtm::OutOfAmmo& e) {  out_file << e.what() << std::endl;  }

    game1.reload(GridPoint(0,0));  // + 5 ammo
    game1.attack(GridPoint(0, 0), GridPoint(2, 0)); // 3 more attacks
    game1.attack(GridPoint(0, 0), GridPoint(2, 0));
    game1.attack(GridPoint(0, 0), GridPoint(2, 0));

    try { game1.attack(GridPoint(0, 0), GridPoint(2, 0)); }  // target died
    catch (mtm::IllegalTarget& e) {  out_file << e.what() << std::endl;  }

    out_file << game1 << endl;

    game1.attack(GridPoint(0, 0), GridPoint(2, 1)); // -2 ammo
    game1.attack(GridPoint(0, 0), GridPoint(2, 1));

    try { game1.attack(GridPoint(0, 0), GridPoint(2, 1));  } // Out of ammo
    catch (mtm::OutOfAmmo& e) {  out_file << e.what() << std::endl;  }

    game1.reload(GridPoint(0,0));  // + 5 ammo
    try { game1.attack(GridPoint(0, 0), GridPoint(2, 1));  } //targed died
    catch (mtm::IllegalTarget& e) {  out_file << e.what() << std::endl;  }

    out_file << game1 << endl;

    assert(!game1.isOver());

    out_file.close();
    cout << "[OK]" << endl;
}

void copyTest() // DO ME?!@!?!@!@!@!!@!
{
    cout << "Running copyTest...   ";
    cout << "[NOT]" << endl;;
}

int main ()
{
    boardTest1(); // Private
    basicTest1(); // Private
    medicTest1();
    copyTest();
}