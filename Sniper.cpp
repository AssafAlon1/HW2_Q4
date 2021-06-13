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
    }
}