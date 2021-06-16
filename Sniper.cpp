#include "Sniper.h"
#include "Exceptions.h"

namespace mtm
{
    Sniper::Sniper(units_t health, units_t ammo, units_t attack_range, units_t power, Team team)
    : Character(health, ammo, attack_range, power, team, MOVING_RANGE, ATTACK_COST, RELOAD_AMOUNT)
    {
        attack_counter = 0;
    }
    
    std::shared_ptr<Character> Sniper::clone() const
    {
        return std::shared_ptr<Sniper>(new Sniper(*this));
    }

    void Sniper::validateRange(const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const
    {
        int distance = GridPoint::distance(src_coordinates, dst_coordinates);
        if (distance > attack_range || distance <= attack_range/2)
        {
            throw OutOfRange();
        }
    }

    char Sniper::getAscii() const
    {
        if (this->team == POWERLIFTERS)
        {
            return POWERLIFTERS_ASCII;
        }
        return CROSSFITTERS_ASCII;
    }

    void Sniper::attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        
        //this->basicAttackValidation(src_coordinates, dst_coordinates);

        // IlegalTarget [only enemy]

        // actual attack

        // reduce ammo 
        // do damage [or double damage] & update counter
        // check if killed character
        //
    }
}