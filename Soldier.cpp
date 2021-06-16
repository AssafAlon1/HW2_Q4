#include "Soldier.h"
#include "Exceptions.h"

namespace mtm
{
    Soldier::Soldier(units_t health, units_t ammo, units_t attack_range, units_t power, Team team)
    : Character(health, ammo, attack_range, power, team, MOVING_RANGE, ATTACK_COST, RELOAD_AMOUNT) {}

    std::shared_ptr<Character> Soldier::clone() const
    {
        return std::shared_ptr<Soldier>(new Soldier(*this));
    }

    void Soldier::attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {

    }

    char Soldier::getAscii() const
    {
        if (this->team == POWERLIFTERS)
        {
            return POWERLIFTERS_ASCII;
        }
        return CROSSFITTERS_ASCII;
    }
}