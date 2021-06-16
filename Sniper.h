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
        Sniper(units_t health, units_t ammo, units_t attack_range, units_t power, Team team);
        ~Sniper() = default;

        // Inherited functions
        std::shared_ptr<Character> clone() const;
        void validateRange(int distance) const;
        void attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        char getAscii() const;


    };   
}


#endif // HW2_SNIPER_H