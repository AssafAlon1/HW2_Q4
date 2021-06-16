#include "Medic.h"
#include "Exceptions.h"
namespace mtm
{
    Medic::Medic(units_t health, units_t ammo, units_t attack_range, units_t power, Team team)
    : Character(health, ammo, attack_range, power, team, MOVING_RANGE, ATTACK_COST, RELOAD_AMOUNT) {}

    std::shared_ptr<Character> Medic::clone() const
    {
        return std::shared_ptr<Medic>(new Medic(*this));
    }

    void Medic::validateTarget(std::shared_ptr<Character> target) const
    {
        if (target == nullptr)
        {
            throw IllegalTarget();
        }
    }

    void Medic::attack(Board& board ,const GridPoint& src_coordinates, const GridPoint& dst_coordinates)
    {

    }

    char Medic::getAscii() const
    {
        if (this->team == POWERLIFTERS)
        {
            return POWERLIFTERS_ASCII;
        }
        return CROSSFITTERS_ASCII;
    }



}