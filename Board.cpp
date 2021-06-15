#include "Board.h"

namespace mtm
{
    // Checks if given coordinates are within the board
    bool Board::isCellInBoard(GridPoint& coordinates)
    {
        return (coordinates.col >= 0 && coordinates.col < cols &&
                coordinates.row >= 0 && coordinates.row < rows);
    }

    // Checks if a character is stored within a specific cell
    bool Board::isCellOccupied(GridPoint& coordinate)
    {
        return this->cells[coordinate.row][coordinate.col].isCellOccupied();
    }

    // Returns a shared pointer to a character from a coordinate
    std::shared_ptr<Character> Board::getCharacter(GridPoint& coordinate)
    {
        return this->cells[coordinate.row][coordinate.col].getCharacter();
    }

    // Removes a character from a given coordinates 
    void Board::removeCharacter(GridPoint& coordinate)
    {
        return this->cells[coordinate.row][coordinate.col].removeCharacter();
    }
    
    // Puts a given character in a given coordinates
    void Board::putCharacter(GridPoint& coordinate, std::shared_ptr<Character> character)
    {
        return this->cells[coordinate.row][coordinate.col].putCharacter(character);
    }
    
    // BoardCell default constructor
    Board::BoardCell::BoardCell() : coordinate(GridPoint(INVALID_COORDINATE, INVALID_COORDINATE)), character(nullptr)
    {
    }
    
    // BoardCell constructor
    Board::BoardCell::BoardCell(GridPoint coordinate) : coordinate(coordinate), character(nullptr)
    {
    }
    
    // Checks if the cell contains a character
    bool Board::BoardCell::isCellOccupied()
    {
        if(this->character != nullptr)
        {
            return true;
        }
        return false;
    }

    // Gets a character from a cell
    std::shared_ptr<Character> Board::BoardCell::getCharacter()
    {
        return this->character;
    }

    // Removes a character from a cell
    void Board::BoardCell::removeCharacter()
    {
        this->character = nullptr;
    }

    // Puts a character in the cell
    void Board::BoardCell::putCharacter(std::shared_ptr<Character> character)
    {
        this->character = character;
    }

    // Board constructor
    Board::Board(int rows, int cols)
    {
        this->rows  = rows;
        this->cols  = cols;
        this->cells = vector<vector<Board::BoardCell>>(rows, vector<BoardCell>(cols));

        for (int row = 0; row < rows ; row++)
        {
            for (int col = 0 ; col < cols ; col++)
            {
                this->cells[row][col] = BoardCell(GridPoint(row, col));
            }
        }
    }
}