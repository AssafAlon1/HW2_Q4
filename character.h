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

        virtual void validateRange(const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const;
        virtual void validateTarget(const Board& board, const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const;
        virtual void validateAmmo(const Board& board, const GridPoint& dst_coordinates) const;

        void reload();
        void move(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
        void takeDamage(const units_t damage_amount);
        bool isAlive() const;
        void basicAttackValidation(const Board& board, const GridPoint& src_coordinates, const GridPoint& dst_coordinates) const;
        Team getTeam() const;

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

    bool isPowerlifter(const std::shared_ptr<Character> character);
    bool isCrossfitter(const std::shared_ptr<Character> character);
}

#endif // HW2_CHARACTER_H