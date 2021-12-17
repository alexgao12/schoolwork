#include "Character.h"
#include <iostream>

Character::Character(HeroType type, const string& name, double health, double attack):type(type), name(name), health(health), attackStrength(attack){ }

HeroType Character::getType() const{
    return type;
}

const string& Character::getName() const{
    return name;
}

int Character::getHealth() const{
    return (int)health;
}

bool Character::isAlive() const{
    return health > 0;
}

void Character::damage(double d){
    health -= d;
}