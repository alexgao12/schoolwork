#include "Distance.h"
using namespace std;

Distance::Distance(){
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned feet, double inches){
    this-> feet = feet;
    this-> inches = inches;
    init();
}

Distance::Distance(double inches){
    feet = 0;
    this-> inches = inches;
    init();
}

unsigned Distance::getFeet() const{
    return feet;
}

double Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const{
    return feet*12 + inches;
}

double Distance::distanceInFeet() const{
    return feet + inches/12;
}

double Distance::distanceInMeters() const{
    return distanceInInches()* 0.0254;
}

Distance Distance::operator + (const Distance& rhs) const{
    return Distance(feet + rhs.feet, inches + rhs.inches);
}
Distance Distance::operator - (const Distance& rhs) const{
    unsigned feettemp;
    double inchestemp;
    if(rhs.feet > feet){
        feettemp = rhs.feet - feet;
        inchestemp = rhs.inches - inches;
    }
    else{
        feettemp = feet - rhs.feet;
        inchestemp = inches - rhs.inches;
    }

    if (inchestemp < 0){
        inchestemp += 12;
        --feettemp;
    }

    return Distance(feettemp, inchestemp);
}

ostream& operator << (ostream& out, const Distance& rhs){
    out << rhs.getFeet() << "' " << rhs.getInches() << '"';
    return out;
}

void Distance::init(){
    if(inches < 0){
        inches *= -1;
    }
    while(inches > 12){
        inches -= 12;
        ++feet;
    }
}
