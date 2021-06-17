#include "Sniper.h"
#include "Exceptions.h"

namespace mtm
{
    Sniper::Sniper(units_t health, units_t ammo, units_t attack_range, units_t power, Team team)
    : Character(health, ammo, attack_range, power, team, MOVING_RANGE, ATTACK_COST, RELOAD_AMOUNT)
    {
        attack_counter = 0;
    }
    
    std::shared_ptr<Character> Sniper::clone() const
    {
        return std::shared_ptr<Sniper>(new Sniper(*this));
    }

    void Sniper::validateRange(const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const
    {
        int distance = GridPoint::distance(src_coordinates, dst_coordinates);
        if (distance <= attack_range && distance >= ceil(double(attack_range)/RANGE_DIVIDOR))
        {
            return;
        }

        throw OutOfRange();
    }

    char Sniper::getAscii() const
    {
        if (this->team == POWERLIFTERS)
        {
            return POWERLIFTERS_ASCII;
        }
        return CROSSFITTERS_ASCII;
    }

    void Sniper::attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {
        // Check for OutOfRange , OutOfAmmo , IlegalTarget ...
        this->basicAttackValidation(board ,src_coordinates, dst_coordinates);
        
        // Deals damage 
        if ((this->attack_counter + 1) % 3 == 0)
        {
            board.getCharacter(dst_coordinates)->takeDamage(this->power*POWER_MULTIPLYER);
        }
        else 
        {
            board.getCharacter(dst_coordinates)->takeDamage(this->power);
        }

        // Update info - reduce ammo, update counted
        this->ammo -= -attack_cost;
        this->attack_counter++;

        // Check if the enemy was killed
        if (board.getCharacter(dst_coordinates)->isAlive() != true)
        {
            board.removeCharacter(dst_coordinates);
        }
        
    }
}