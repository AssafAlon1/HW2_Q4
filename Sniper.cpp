#include "Sniper.h"

namespace mtm
{
    Sniper::Sniper(int health, int ammo, int attack_range, int power, Team team)
    : Character(health, ammo, attack_range, power, team, MOVING_RANGE, ATTACK_COST, RELOAD_AMOUNT)
    {
        attack_counter = 0;
    }


    char Sniper::getAscii()
    {
        if (this->team == POWERLIFTERS)
        {
            return POWERLIFTERS_ASCII;
        }

        return CROSSFITTERS_ASCII;
    }


    void Sniper::validateRange(int distance)
    {
        if (distance > attack_range || distance <= attack_range/2)
        {
            // OutOfRange
        }
    }

    void Sniper::attack(Board& board ,GridPoint& src_coordinates, GridPoint& dst_coordinates)
    {
        
        this->validateAttack(board ,src_coordinates, dst_coordinates);

        // IlegalTarget [only enemy]

        // actual attack

        // reduce ammo 
        // do damage [or double]

        //
    }
}