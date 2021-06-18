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
        //Board(const Board& board) = default;

        bool isCellInBoard(const GridPoint& coordinates) const;
        bool isCellOccupied(const GridPoint& coordinates) const;
        std::shared_ptr<Character> getCharacter(const GridPoint& coordinates) const;

        void removeCharacter(const GridPoint& coordinates);
        void putCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);

        class Iterator;
        Iterator begin() const;
        Iterator end() const;

        int getWidth() const;
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
        BoardCell(const GridPoint& coordinates);
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

    class Board::Iterator
    {
    public:
        Iterator(const Iterator& iterator) = default;
        ~Iterator() = default;
        Iterator& operator=(const Iterator& iterator) = default;
        Iterator& operator++();
        Iterator operator++(int);
        bool operator==(Iterator iterator) const;
        const std::shared_ptr<Character> operator*() const;
    private:
        Iterator(const Board* board, int row, int col);
        const Board* board;
        int row, col;
        friend class Board;
    };


     
}

#endif // HW2_BOARD_H