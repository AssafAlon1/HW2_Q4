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
        // Input verification
        this->basicAttackValidation(board ,src_coordinates, dst_coordinates);

        // Ammo reduction and deal damage to enemies in range
        this->ammo -= attack_cost;
        int range_radius = ceil(double(attack_range)/AREA_OF_EFFECT_RANGE_DIVIDOR);
        for (int row = dst_coordinates.row - range_radius ; row < dst_coordinates.row + range_radius ; row++)
        {
            for (int col = dst_coordinates.col - range_radius ; col < dst_coordinates.col + range_radius ; col++)
            {
                GridPoint current_coordinates = GridPoint(row, col);
                
                if(!(board.isCellInBoard(current_coordinates)) ||
                   !board.isCellOccupied(current_coordinates)  ||
                   GridPoint::distance(current_coordinates, dst_coordinates) > range_radius)
                {
                    continue;
                }

                // Enemy on target cell
                std::shared_ptr<Character> target = board.getCharacter(current_coordinates);
                if (target->getTeam() != this->team)
                {
                    units_t damage = power;

                    // Area of effect damage
                    if (!(dst_coordinates == current_coordinates))
                    {
                        damage = ceil(double(power)/AREA_OF_EFFECT_POWER_DIVIDOR);
                    }

                    target->takeDamage(damage);
                    if (!(target->isAlive()))
                    {
                        board.removeCharacter(current_coordinates);
                    }
                }
            }
        }
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