#ifndef HW2_CHARACTER_H
#define HW2_CHARACTER_H

#include <memory>

#include "Auxiliaries.h"
#include "Board.h"


namespace mtm
{

    class Board; // Forward declaration of Board
    class Character
    {    
    public:
        Character(units_t health, units_t ammo, units_t attack_range, units_t power, Team team,
                  units_t moving_range, units_t attack_cost, units_t reload_amount);
        virtual ~Character() = default;
        Character(const Character& existing_Character) = default;

        // assignemnt operator ???
        // 
        virtual std::shared_ptr<Character> clone() const = 0;
        virtual void attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates) = 0;
        virtual char getAscii() const = 0;

        virtual void validateRange(const int distance) const;
        virtual void validateTarget(std::shared_ptr<Character> target) const;

        void reload();
        void move(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void takeDamage(const units_t damage_amount);
        bool isAlive() const;
        void basicAttackValidation(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);



    protected:   // PRIVATIZE WHATEVER WE CAN / FIND ALTERNATIVES
        units_t health;
        units_t ammo;
        units_t attack_range;
        units_t power;
        Team team;
        
        units_t moving_range;
        units_t attack_cost;
        units_t reload_amount;
    };
}

#endif // HW2_CHARACTER_H