#include "Soldier.h"
#include "Exceptions.h"
#include "math.h"

namespace mtm
{
    Soldier::Soldier(units_t health, units_t ammo, units_t attack_range, units_t power, Team team)
    : Character(health, ammo, attack_range, power, team, MOVING_RANGE, ATTACK_COST, RELOAD_AMOUNT) {}

    std::shared_ptr<Character> Soldier::clone() const
    {
        return std::shared_ptr<Soldier>(new Soldier(*this));
    }

    void Soldier::validateTarget(const Board& board, const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const
    {
        // Verify shoots in straight line
        if (src_coordinates.col != dst_coordinates.col && src_coordinates.row != dst_coordinates.row)
        {
            throw IllegalTarget();
        }
        
        // Can shoot empty cells, can shoot allies, no more checks need to be make
    }


    void Soldier::attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        // Check for OutOfRange , OutOfAmmo , IlegalTarget ...
        this->basicAttackValidation(board ,src_coordinates, dst_coordinates);

        // destination is not in straight line
        this->validateTarget(board , src_coordinates , dst_coordinates);

        // actual attack
        //for (int row = dst_coordinates - attack_range/3)





        // update info - reduce ammo 
        this->ammo -= -attack_cost;

    }

    char Soldier::getAscii() const
    {
        if (this->team == POWERLIFTERS)
        {
            return POWERLIFTERS_ASCII;
        }
        return CROSSFITTERS_ASCII;
    }
}