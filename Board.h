#ifndef HW2_BOARD_H
#define HW2_BOARD_H

#include "Character.h"   // Only character? what about Sniper/Medic/Soldier?
#include <memory>
#include <vector>


using std::vector;

namespace mtm
{
    class Character; // Forward declaration of Character
    
    class Board
    {
    public:
        Board(int rows, int cols);
        ~Board() = default;
        Board(const Board& board) = default;

        bool isCellInBoard(GridPoint& coordinates);
        bool isCellOccupied(GridPoint& coordinate);
        std::shared_ptr<Character> getCharacter(GridPoint& coordinate);
        void removeCharacter(GridPoint& coordinate);
        void putCharacter(GridPoint& coordinate, std::shared_ptr<Character> character);


    private:
        class BoardCell;
        static const int INVALID_COORDINATE = -1;

        int rows;
        int cols;
        
        vector<vector<BoardCell>> cells;
        
    };


    class Board::BoardCell
    {
    public:
        BoardCell();
        BoardCell(GridPoint coordinate);
        BoardCell(const BoardCell& cell) = default;
        ~BoardCell() = default;

        bool isCellOccupied();
        std::shared_ptr<Character> getCharacter();
        void removeCharacter();
        void putCharacter(std::shared_ptr<Character> character);

    private:
        GridPoint coordinate;
        std::shared_ptr<Character> character;
    };
}

#endif // HW2_BOARD_H