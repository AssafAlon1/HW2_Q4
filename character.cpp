#include "Character.h"
#include "Exceptions.h"
namespace mtm
{
    Character::Character(units_t health, units_t ammo, units_t attack_range, units_t power, Team team,
                  units_t moving_range, units_t attack_cost, units_t reload_amount)
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

    void Character::move(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        if (GridPoint::distance(src_coordinates, dst_coordinates) >= moving_range)
        {
            throw MoveTooFar();
        }

        if (board.isCellOccupied(dst_coordinates))
        {
            throw CellOccupied();
        }

        // Put the character in the destination cell and remove it from the source cell
        board.putCharacter(dst_coordinates, board.getCharacter(src_coordinates));
        board.removeCharacter(src_coordinates);
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
        if (target == nullptr)
        {
            // IllegalTarget because cell is empty
        }
        if (target->team != team)
        {
            // IllegalTarget because target is ally
        }
    }


    void Character::takeDamage(const units_t damage_amount)
    {
        health -= damage_amount;
    }

    bool Character::isAlive() const
    {
        return health > 0;
    }

    void Character::basicAttackValidation(const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        // CellEmpty

        // OutOfRange

        // OutOfAmmo

        return;
    }
}