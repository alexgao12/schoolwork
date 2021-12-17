#include "Character.h"
#include <iostream>

#ifndef __Wizard_H__
#define __Wizard_H__

class Wizard : public Character{
    private:
        int rank;
    public:
        Wizard(const string& name, int health, int attack, int rank);
        void attack(Character& enemy) override;
};
#endif