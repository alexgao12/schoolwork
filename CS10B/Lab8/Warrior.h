#include "Character.h"
#include <iostream>

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior : public Character{
    private: 
        string allegiance;
    public:
        Warrior(const string& name, int health, int attack, const string& allegiance);
        void attack(Character& enemy) override;
};

#endif
