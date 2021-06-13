


namespace mtm
{
    class Character
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
        Character(int health, int ammo, int attack_range, int power,
                  int moving_range, int reload_amount, char ascii_representation);
        virtual ~Character() = default;
        Character(const Character& existing_Character) = default;

        // assignemnt operator ???
        // 
        virtual Character* clone() = 0;
        virtual void attack() = 0;
        void reload();

        // void takeDamage(int damage_amount);
        // {
        //     health -= damage_amount;
        // }


    };
}