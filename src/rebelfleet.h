#ifndef STARWARS_2_REBELFLEET_H
#define STARWARS_2_REBELFLEET_H

#include <memory>
#include "helper.h"

class RebelStarship : public virtual Starship {
private:
    Speed speed;
public:
    Speed getSpeed() const;
    
    RebelStarship(ShieldPoints shieldPoints, Speed speed);
};

class Explorer : public RebelStarship {
public:
    Explorer(ShieldPoints shieldPoints, Speed speed);
    
    ~Explorer() override = default;
};

class StarCruiser : public RebelStarship, public Attacking {
public:
    StarCruiser(ShieldPoints shieldPoints, Speed speed, AttackPower attackPower);
    
    ~StarCruiser() override = default;
};

class XWing : public RebelStarship, public Attacking {
public:
    XWing(ShieldPoints shieldPoints, Speed speed, AttackPower attackPower);
    
    ~XWing() override = default;
};

std::shared_ptr<Explorer> createExplorer(ShieldPoints shieldPoints, Speed speed);

std::shared_ptr<XWing> createXWing(ShieldPoints shieldPoints, Speed speed, AttackPower attackPower);

std::shared_ptr<StarCruiser> createStarCruiser(ShieldPoints shieldPoints, Speed speed, AttackPower attackPower);

#endif //STARWARS_2_REBELFLEET_H
