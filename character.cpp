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

    // Moves a character from source coordinates to destination coordinates
    void Character::move(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        if (GridPoint::distance(src_coordinates, dst_coordinates) > moving_range)
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

    // Validates the range of an attack
    void Character::validateRange(const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const
    {
        int distance = GridPoint::distance(src_coordinates, dst_coordinates);
        if (distance > attack_range || distance < 0)
        {
            throw OutOfRange();
        }
    }

    // Validates the target of an attack
    void Character::validateTarget(const Board& board, const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const
    {
        if (!board.isCellOccupied(dst_coordinates))
        {
            throw IllegalTarget(); // because cell is empty
        }

        std::shared_ptr<Character> target = board.getCharacter(dst_coordinates);
        if (target->team == team)
        {
            throw IllegalTarget(); // because target is ally
        }
    }

    void Character::validateAmmo(const Board& board, const GridPoint& dst_coordinates) const
    {
        if(ammo < attack_cost)
        {
            throw OutOfAmmo();
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

    void Character::basicAttackValidation(const Board& board, const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const
    {
        // OutOfRange
        validateRange(src_coordinates , dst_coordinates);

        // OutOfAmmo
        validateAmmo(board, dst_coordinates);

        // IllegalTarget
        validateTarget(board, src_coordinates, dst_coordinates);

        return;
    }

    Team Character::getTeam() const
    {
        return team;
    }

    // Returns true if the character is a powerlifter - false otherwise
    bool isPowerlifter(const std::shared_ptr<Character> character)
    {
        return character->getTeam() == POWERLIFTERS;
    }

    // Returns true if the character is a crossfitter - false otherwise
    bool isCrossfitter(const std::shared_ptr<Character> character)
    {
        return character->getTeam() == CROSSFITTERS;
    }
}