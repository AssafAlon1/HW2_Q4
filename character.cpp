#include "Character.h"

namespace mtm
{
    Character::Character(int health, int ammo, int attack_range, int power, Team team,
                  int moving_range, int reload_amount, char ascii_representation)
    {
        this->health        = health;
        this->ammo          = ammo;
        this->attack_range  = attack_range;
        this->power         = power;

        this->moving_range  = moving_range;
        this->attack_cost   = attack_cost;
        this->reload_amount = reload_amount;
        this->team          = team;
    }
    

    void Character::reload()
    {
        ammo += reload_amount;
    }
}