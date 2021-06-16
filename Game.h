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
        //Game(const Game& other); // default?
        //Game& operator= (const Game& other);

        void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
        
        void move (const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void attack (const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void reload (const GridPoint& coordinates);
        bool isOver (Team* winningTeam=NULL) const;

        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                            units_t health, units_t ammo, units_t range, units_t power);

        friend std::ostream& operator<<(std::ostream& out_stream, const Game& game);

    private:
        Board board;
    };

    
}


#endif // HW2_GAME_H