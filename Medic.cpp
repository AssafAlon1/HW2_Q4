#include "Medic.h"
#include "Exceptions.h"

namespace mtm
{
    Medic::Medic(units_t health, units_t ammo, units_t attack_range, units_t power, Team team)
    : Character(health, ammo, attack_range, power, team, MOVING_RANGE, ATTACK_COST, RELOAD_AMOUNT) {}

    std::shared_ptr<Character> Medic::clone() const
    {
        return std::shared_ptr<Medic>(new Medic(*this));
    }

    // Validates ammo if the target is an enemy
    void Medic::validateAmmo(const Board& board, const GridPoint& dst_coordinates) const
    {
        if (board.getCharacter(dst_coordinates)->getTeam() != this->getTeam() && ammo < attack_cost)
        {
            throw OutOfAmmo();
        }
    }

    void Medic::validateTarget(const Board& board, const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const
    {
        // Target cell is empty
        if (!board.isCellOccupied(dst_coordinates))
        {
            throw IllegalTarget();
        }

        //Target cell is the medic's cell
        if (GridPoint::distance(src_coordinates, dst_coordinates) == 0)
        {
            throw IllegalTarget();
        }

        // Can target both allies and enemies, no more checks need to be make
    }

    void Medic::attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        // Check for OutOfRange , OutOfAmmo , IlegalTarget ...
        this->basicAttackValidation(board, src_coordinates, dst_coordinates);
        std::shared_ptr<Character> target = board.getCharacter(dst_coordinates);

        // Heal - no ammo reduction, no need to check if target is dead
        if (target->getTeam() == this->getTeam())
        {
            target->takeDamage(HEALING_MULTIPLYER*power);
            return;
        }

        // Deals damage, update ammo
        target->takeDamage(power);
        ammo -= attack_cost;

        // Check if the enemy was killed
        if (!(target->isAlive()))
        {
            board.removeCharacter(dst_coordinates);
        }
    }

    char Medic::getAscii() const
    {
        if (this->team == POWERLIFTERS)
        {
            return POWERLIFTERS_ASCII;
        }
        return CROSSFITTERS_ASCII;
    }



}