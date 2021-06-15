#include "Board.h"

namespace mtm
{
    Board::Board(int rows, int cols)
    {
        board = unordered_map<GridPoint, std::shared_ptr<Character>>();
        this->rows = rows;
        this->cols = cols;
    }
}