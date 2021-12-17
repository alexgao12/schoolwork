#include "Elf.h"


Elf::Elf(const string& name, int health, int attack, const string& family_name): Character(ELF, name, health, attack), family_name(family_name){ }


void Elf::attack(Character& enemy){
    if(enemy.getType() == ELF){
        Elf& opp = dynamic_cast<Elf&>(enemy);
        if(this->family_name != opp.family_name){
            enemy.damage(health/MAX_HEALTH * attackStrength);
            cout << "Elf " << getName() << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
            cout << enemy.getName() << " takes " << health/MAX_HEALTH * attackStrength << " damage." << endl;
        }
        else{
            cout << "Elf " << getName() << " does not attack Elf " << enemy.getName() << "." << endl;
            cout << "They are both members of the " << this->family_name << " family." << endl;
        }
    }
    else{
        enemy.damage(health/MAX_HEALTH * attackStrength);
        cout << "Elf " << getName() << " shoots an arrow at " << enemy.getName() << " --- TWANG!!" << endl;
        cout << enemy.getName() << " takes " << health/MAX_HEALTH * attackStrength << " damage." << endl;
    }   
}