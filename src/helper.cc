#include <cmath>
#include "helper.h"

ShieldPoints StarShip::getShield() const {
    return shieldPoints;
}

void StarShip::takeDamage(AttackPower damage) {
    shieldPoints = std::max(shieldPoints - damage, 0);
}

StarShip::StarShip(ShieldPoints shieldPoints) : shieldPoints(shieldPoints) {}

NumberOfShips StarShip::howManyUndestroyedUnits() {
    if (shieldPoints > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void StarShip::maybeAttack(std::shared_ptr<StarShip> ship) {
    ship->takeDamage(0);
}

AttackPower Attacking::getAttackPower() const {
    return attackPower;
}

void Attacking::maybeAttack(std::shared_ptr<StarShip> ship) {
    ship->takeDamage(attackPower);
}

Attacking::Attacking(ShieldPoints shieldPoints, AttackPower attackPower) : StarShip(shieldPoints),
                                                                           attackPower(attackPower) {}

bool DefaultAttackTime::isItAttackTime(Time t) const {
    return (t % 2 == 0 ||  t % 3 == 0) && (t % 5 != 0);
}

SpaceTime::SpaceTime(Time t0, Time t1) : t0(t0),
                                         t1(t1),
                                         currentTime(t0),
                                         attackTime(std::make_shared<DefaultAttackTime>()){}

SpaceTime::SpaceTime(Time t0, Time t1, std::shared_ptr<AttackTime> attackTime) : t0(t0),
                                                                                 t1(t1),
                                                                                 currentTime(t0),
                                                                                 attackTime(attackTime){}

bool SpaceTime::isItAttackTime() {
    return attackTime->isItAttackTime(currentTime);
}

void SpaceTime::setAttackTime(std::shared_ptr<AttackTime> newAttackTime){
    attackTime = newAttackTime;
}

Time SpaceTime::getT0() const {
    return t0;
}

Time SpaceTime::getT1() const {
    return t1;
}

Time SpaceTime::getCurrentTime() const {
    return currentTime;
}

const std::shared_ptr<AttackTime> &SpaceTime::getAttackTime() const {
    return attackTime;
}

void DefaultSpaceTime::tick(Time t) {
    currentTime += t;
    currentTime %= (t1 + 1);
}


// AttackTime for tests
bool PastAttackTime::isItAttackTime(Time t) const {
    int x = sqrt(t);
    return x * x == t;
}