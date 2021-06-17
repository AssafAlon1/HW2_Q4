#include "Board.h"
#include "Exceptions.h"
#include "assert.h"

namespace mtm
{

    //=========================================
    //========== Board implementation =========
    //=========================================

    // Board constructor
    Board::Board(int rows, int cols)
    {
        if (rows <= 0 || cols <= 0)
        {
            throw IllegalArgument();
        }
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

    // Checks if given coordinates are within the board
    bool Board::isCellInBoard(const GridPoint& coordinates) const
    {
        return (coordinates.col >= 0 && coordinates.col < cols &&
                coordinates.row >= 0 && coordinates.row < rows);
    }

    // Checks if a character is stored within a specific cell
    bool Board::isCellOccupied(const GridPoint& coordinates) const
    {
        return this->cells[coordinates.row][coordinates.col].isCellOccupied();
    }

    // Returns a shared pointer to a character from a coordinate
    std::shared_ptr<Character> Board::getCharacter(const GridPoint& coordinates) const
    {
        return this->cells[coordinates.row][coordinates.col].getCharacter();
    }

    // Removes a character from a given coordinates 
    void Board::removeCharacter(const GridPoint& coordinates)
    {

        return this->cells[coordinates.row][coordinates.col].removeCharacter();
    }
    
    // Puts a given character in a given coordinates
    void Board::putCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character)
    {
        assert(this->isCellInBoard(coordinates));
        assert(!(this->isCellOccupied(coordinates)));
        
        return this->cells[coordinates.row][coordinates.col].putCharacter(character);
    }
    
    int Board::getWidth() const
    {
        return cols;
    }

    //=========================================
    //======== BoardCell implementation =======
    //=========================================

    // BoardCell default constructor
    Board::BoardCell::BoardCell() : coordinates(GridPoint(INVALID_COORDINATE, INVALID_COORDINATE)), character(nullptr)
    {
    }
    
    // BoardCell constructor
    Board::BoardCell::BoardCell(GridPoint coordinates) : coordinates(coordinates), character(nullptr)
    {
    }

    // Checks if the cell contains a character
    bool Board::BoardCell::isCellOccupied() const
    {
        if(this->character != nullptr)
        {
            return true;
        }
        return false;
    }

    // Gets a character from a cell
    std::shared_ptr<Character> Board::BoardCell::getCharacter() const
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





    Board::Iterator::Iterator(const Board* board, int row, int col) : board(board), row(row), col(col)
    {
    }

    // Moves the iterator forwards
    Board::Iterator& Board::Iterator::operator++()
    {
        // Reached the last cell
        if (col >= board->cols - 1 && row >= board->rows - 1)
        {
            throw std::out_of_range("Out of range"); // ???
        }

        // Reached the end of a row
        if (row >= board->rows - 1)
        {
            row = 0;
            col++;
            return *this;
        }

        // Somewhere in the middle
        row++;
        return *this;
    }


    // Moves the iterator forwards
    Board::Iterator Board::Iterator::operator++(int)
    {
        // Reached the last cell
        if (col >= board->cols - 1 && row >= board->rows - 1)
        {
            throw std::out_of_range("Out of range"); // ???
        }

        Board::Iterator result = *this;

        // Reached the end of a row
        if (row >= board->rows - 1)
        {
            row = 0;
            col++;
            return *this;
        }

        // Somewhere in the middle
        row++;
        return result;
    }

    // Compares an iterator with another
    bool Board::Iterator::operator==(Board::Iterator iterator) const
    {
        //assert(iterator.board == board);
        return (row == iterator.row && col == iterator.col);
    }


    const std::shared_ptr<Character> Board::Iterator::operator*() const
    {
        return board->getCharacter(GridPoint(row, col));
    }

    // Returns an iterator to the begining of the board
    Board::Iterator Board::begin() const
    {
        return Board::Iterator(this, 0, 0);
    }

    // Returns an iterator to the end of the board
    Board::Iterator Board::end() const
    {
        return Board::Iterator(this, rows - 1, cols - 1);
    }

}