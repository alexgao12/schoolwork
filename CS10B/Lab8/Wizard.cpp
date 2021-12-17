#include "Wizard.h"

Wizard::Wizard(const string& name, int health, int attack, int rank): Character(WIZARD, name, health, attack), rank(rank){ }

void Wizard::attack(Character& enemy){
    cout << "Wizard " << getName() << " attacks " << enemy.getName() << " --- POOF!!" << endl;
    if(enemy.getType() == WIZARD){
        Wizard& opp = dynamic_cast<Wizard&>(enemy);
        enemy.damage((double)rank/opp.rank * attackStrength);
        cout << enemy.getName() << " takes " << (double)rank/(double)opp.rank * attackStrength << " damage." << endl;
    }
    else{
        enemy.damage(attackStrength);
        cout << enemy.getName() << " takes " << attackStrength << " damage." << endl;
    }
}