#include "character.h"

namespace mtm
{
    character::character(int health, int ammo, int attack_range, int power,
                  int moving_range, int reload_amount, char ascii_representation)
    {
        this->health               = health;
        this->ammo                 = ammo;
        this->attack_range         = attack_range;
        this->power                = power;

        this->moving_range         = moving_range;
        this->reload_amount        = reload_amount;
        this->ascii_representation = ascii_representation;
    }
    

    void character::reload()
    {
        ammo += reload_amount;
    }
}