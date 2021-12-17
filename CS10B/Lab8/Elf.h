#include "Character.h"
#include <iostream>

#ifndef __ELF_H__
#define __ELF_H__

class Elf : public Character{
    private:
        string family_name;
    public:
        Elf(const string& name, int health, int attack, const string& family_name);
        void attack(Character&  enemy) override;
};
#endif