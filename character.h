


namespace mtm
{
    class character
    {
    private:
        int health;
        int ammo;
        int attack_range;
        int power;

        int moving_range;
        int reload_amount;
        char ascii_representation;
        

    public:
        character(int health, int ammo, int attack_range, int power,
                  int moving_range, int reload_amount, char ascii_representation);
        ~character() = default;

        // copy constructor
        // assignemnt operator
        // 
        virtual character* clone() = 0;
        virtual void attack() = 0;
        void reload();

        // void takeDamage(int damage_amount);
        // {
        //     health -= damage_amount;
        // }


    };
}