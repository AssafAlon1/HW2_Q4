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

        bool isCellInBoard(const GridPoint& coordinates) const;
        bool isCellOccupied(const GridPoint& coordinates) const;
        std::shared_ptr<Character> getCharacter(const GridPoint& coordinates) const;

        void removeCharacter(const GridPoint& coordinates);
        void putCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);

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
        BoardCell(GridPoint coordinates);
        BoardCell(const BoardCell& cell) = default;
        ~BoardCell() = default;

        bool isCellOccupied() const;
        std::shared_ptr<Character> getCharacter() const;
        
        void removeCharacter();
        void putCharacter(std::shared_ptr<Character> character);

    private:
        GridPoint coordinates;
        std::shared_ptr<Character> character;
    };
}

#endif // HW2_BOARD_H