#ifndef HW2_SOLDIER_H
#define HW2_SOLDIER_H

#include "Character.h"
#include "Board.h"

namespace mtm
{
    class Soldier : public Character
    {
    public:
        Soldier(units_t health, units_t ammo, units_t attack_range, units_t power, Team team);
        ~Soldier() = default;

        // Inherited functions
        std::shared_ptr<Character> clone() const;
        void validateRange(const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const;
        void attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        char getAscii() const;

    private:
        static const int MOVING_RANGE        = 3;
        static const int ATTACK_COST         = 1;
        static const int RELOAD_AMOUNT       = 3;
        static const char CROSSFITTERS_ASCII = 's';
        static const char POWERLIFTERS_ASCII = 'S';
    };
}


#endif // HW2_SOLDIER_H