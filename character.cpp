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

    virtual void Character::validateRange(const int distance) const
    {
        if (distance > range)
        {
            // OutOfRange
        }
    }


    virtual void Character::validateTarget(std::shared_ptr<Character> target) const
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

    void Character::isAlive() const
    {
        if(health == 0)
        {
            return false;
        }
        return true:
    }

    void Character::basicAttackValidation(GridPoint& src_coordinate, GridPoint& dst_coordinate, BoardCell& cell)
    {
        // IllegalCell  <-- Do on game?

        // CellEmpty

        // OutOfRange

        // OutOfAmmo

        return
    }
}