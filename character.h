#ifndef HW2_CHARACTER_H
#define HW2_CHARACTER_H

#include "Auxiliaries.h"
#include "Board.h"

namespace mtm
{
    class Character
    {    
    public:
        Character(int health, int ammo, int attack_range, int power, Team team,
                  int moving_range, int attack_cost, int reload_amount);
        virtual ~Character() = default;
        Character(const Character& existing_Character) = default;

        // assignemnt operator ???
        // 
        virtual std::shared_ptr<Character> clone() = 0;
        virtual void attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates) = 0;
        virtual char getAscii() const = 0;

        virtual void validateRange(const int distance) const;
        virtual void validateTarget(std::shared_ptr<Character> target) const;

        void reload();
        void takeDamage(const int damage_amount);
        bool isAlive() const;
        void basicAttackValidation(const GridPoint& src_coordinate, const GridPoint& dst_coordinate);



    protected:   // PRIVATIZE WHATEVER WE CAN / FIND ALTERNATIVES
        int health;
        int ammo;
        int attack_range;
        int power;
        Team team;
        
        int moving_range;
        int attack_cost;
        int reload_amount;
    };
}

#endif // HW2_CHARACTER_H