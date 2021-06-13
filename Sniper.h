#include "Character.h"
#include "Auxiliaries.h"

namespace mtm
{
    class Sniper : public Character
    {
    private:
        int attack_counter;

        static const int MOVING_RANGE        = 4;
        static const int ATTACK_COST         = 1;
        static const int RELOAD_AMOUNT       = 2;
        static const char CROSSFITTERS_ASCII = 's';
        static const char POWERLIFTERS_ASCII = 'S';

    public:
        Sniper(int health, int ammo, int attack_range, int power, Team team);
        ~Sniper() = default;

        // Inherited functions
        //Character* clone();
        //void attack();
        char getAscii();
    };


    
}