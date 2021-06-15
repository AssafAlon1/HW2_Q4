#ifndef HW2_SNIPER_H
#define HW2_SNIPER_H

#include "Character.h"
#include "Board.h"

namespace mtm
{
    class Sniper : public Character
    {
    private:
        int attack_counter;

        static const int MOVING_RANGE        = 4;
        static const int ATTACK_COST         = 1;
        static const int RELOAD_AMOUNT       = 2;
        static const char CROSSFITTERS_ASCII = 's';
        static const char POWERLIFTERS_ASCII = 'S';

    public:
        Sniper(int health, int ammo, int attack_range, int power, Team team);
        ~Sniper() = default;

        // Inherited functions
        std::shared_ptr<Character> clone();
        void validateRange(int distance);
        void attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        char getAscii();


    };   
}


#endif // HW2_SNIPER_H