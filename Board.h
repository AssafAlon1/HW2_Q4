#ifndef HW2_BOARD_H
#define HW2_BOARD_H


#include <unordered_map>
#include "Auxiliaries.h"
#include "Character.h"   // Only character? what about Sniper/Medic/Soldier?
#include <memory>

using std::unordered_map;

namespace mtm
{
    class Board
    {
    public:
        Board(int rows, int cols);
        ~Board() = default;
        Board(const Board& board) = default;

        // bool isTileInBoard(GridPoint& coordinates);
        // bool isTileOccupied(GridPoint& coordinate);
        // Character& getCharacter(GridPoint& coordinate);
        // void removeCharacter(GridPoint& coordinate);
        // void putCharacter(GridPoint& coordinate);


    private:
        unordered_map<GridPoint, std::shared_ptr<Character>> board;
        int rows;
        int cols;

    };
    
}

#endif // HW2_BOARD_H