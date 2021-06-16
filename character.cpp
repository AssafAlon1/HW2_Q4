#include "Character.h"

namespace mtm
{
    Character::Character(int health, int ammo, int attack_range, int power, Team team,
                  int moving_range, int attack_cost, int reload_amount)
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

    void Character::validateRange(const int distance) const
    {
        if (distance > attack_range)
        {
            // OutOfRange
        }
    }


    void Character::validateTarget(std::shared_ptr<Character> target) const
    {
        if (target->team != team)
        {
            // IllegalTarget
        }
    }


    void Character::takeDamage(const int damage_amount)
    {
        health -= damage_amount;
    }

    bool Character::isAlive() const
    {
        return health > 0;
    }

    void Character::basicAttackValidation(const GridPoint& src_coordinate, const GridPoint& dst_coordinate)
    {
        // IllegalCell  <-- Do on game?

        // CellEmpty

        // OutOfRange

        // OutOfAmmo

        return;
    }
}