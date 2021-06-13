#include "Auxiliaries.h"


namespace mtm
{
    class Character
    {
    protected:   // PRIVATIZE WHATEVER WE CAN / FIND ALTERNATIVES
        int health;
        int ammo;
        int attack_range;
        int power;
        Team team;

        int moving_range;
        int attack_cost;
        int reload_amount;
        
        
    public:
        Character(int health, int ammo, int attack_range, int power, Team team,
                  int moving_range, int attack_cost, int reload_amount);
        virtual ~Character() = default;
        Character(const Character& existing_Character) = default;

        // assignemnt operator ???
        // 
        virtual Character* clone() = 0;
        virtual void attack() = 0;
        virtual char getAscii() = 0;
        void reload();

        // void takeDamage(int damage_amount);
        // {
        //     health -= damage_amount;
        // }


    };
}