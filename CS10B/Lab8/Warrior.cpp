#include "Warrior.h"

Warrior::Warrior(const string& name, int health, int attack, const string& allegiance): Character(WARRIOR, name, health, attack), allegiance(allegiance){ }


void Warrior::attack(Character& enemy){
    if(enemy.getType() == WARRIOR){
        Warrior& opp = dynamic_cast<Warrior&>(enemy);
        if(this->allegiance != opp.allegiance){
            enemy.damage(health/MAX_HEALTH * attackStrength);
            cout << "Warrior " << getName() << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
            cout << enemy.getName() << " takes " << health/MAX_HEALTH * attackStrength << " damage." << endl;
        }
        else{
            cout << "Warrior " << getName() << " does not attack Warrior " << enemy.getName() <<"." << endl;
            cout << "They share an allegiance with " << this->allegiance << "." << endl;
        }
    }
    else{
        enemy.damage(health/MAX_HEALTH * attackStrength);
        cout << "Warrior " << getName() << " attacks " << enemy.getName() << " --- SLASH!!" << endl;
        cout << enemy.getName() << " takes " << health/MAX_HEALTH * attackStrength << " damage." << endl;
    }
}
