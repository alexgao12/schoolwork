#include "IntVector.h"
#include <iostream>

int main(){
    IntVector ints = IntVector();
    IntVector ints2 = IntVector(2, 3);

    //cout << ints.front() << endl;
    //cout << ints.back() << endl;
    cout << ints2.front() << endl;
    cout << ints2.back() << endl;
    cout << ints2.empty() << endl;
    cout << ints.empty() << endl;
    cout << ints2.at(1) << endl;
    cout << ints.at(1) << endl;
    

    ints.~IntVector();
    ints2.~IntVector();
}