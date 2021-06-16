#ifndef HW2_GAME_H
#define HW2_GAME_h

#include "Auxiliaries.h"
#include "Board.h"

namespace mtm
{
    class Game
    {
    
    public:
        Game(int height, int width);
        //~Game() = default;                // default?
        //Game(const Game& game) = default; // default?
    private:
        Board board;
    };

    
}


#endif // HW2_GAME_H