#include "Board.h"

namespace mtm
{
    bool Board::isCellInBoard(GridPoint& coordinates)
    {
        
    }

    bool Board::isCellOccupied(GridPoint& coordinate)
    {
        
    }

    std::shared_ptr<Character> getCharacter(GridPoint& coordinate)
    {

    }

    void Board::removeCharacter(GridPoint& coordinate)
    {

    }
    
    void Board::putCharacter(GridPoint& coordinate, std::shared_ptr<Character> character)
    {

    }
    
    // Default constructor
    Board::BoardCell::BoardCell() : coordinate(GridPoint(INVALID_COORDINATE, INVALID_COORDINATE)), character(nullptr)
    {
    }
    
    // Constructor
    Board::BoardCell::BoardCell(GridPoint coordinate) : coordinate(coordinate), character(nullptr)
    {
    }
    
    bool Board::BoardCell::isCellOccupied()
    {
        if(this->character != nullptr)
        {
            return true;
        }
        return false;
    }
    std::shared_ptr<Character> Board::BoardCell::getCharacter()
    {
        return this->character;
    }
    void Board::BoardCell::removeCharacter()
    {
        this->character = nullptr;
    }
    void Board::BoardCell::putCharacter(std::shared_ptr<Character> character)
    {
        this->character = character;
    }

    Board::Board(int rows, int cols)
    {
        this->rows  = rows;
        this->cols  = cols;
        this->cells = vector<vector<Board::BoardCell>>(rows, vector<BoardCell>(cols));

        // for ()
        // {

        // }
    }
}