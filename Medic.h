#ifndef HW2_MEDIC_H
#define HW2_MEDIC_H

#include "Character.h"
#include "Board.h"

namespace mtm
{
    class Medic : public Character
    {
    public:
        Medic(units_t health, units_t ammo, units_t attack_range, units_t power, Team team);
        ~Medic() = default;

        // Inherited functions
        std::shared_ptr<Character> clone() const;
        //void validateRange(const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const;
        void validateTarget(std::shared_ptr<Character> target) const;
        void attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        char getAscii() const;
        

    private:
        static const int MOVING_RANGE        = 5;
        static const int ATTACK_COST         = 1;
        static const int RELOAD_AMOUNT       = 5;
        static const char CROSSFITTERS_ASCII = 'm';
        static const char POWERLIFTERS_ASCII = 'M';
    };
}




#endif // HW2_MEDIC_H