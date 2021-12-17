#include "IntVector.h"
#include <iostream>

#include <vector>

int main(){
    //vector<int> first;
    IntVector ints = IntVector();
    IntVector ints2 = IntVector(2, 3);

    //cout << first.front() << endl;
    //cout << ints.front() << endl;
    //cout << ints.back() << endl;
    //ints2.front() = 4;
    //cout << ints2.front() << endl;
    //cout << ints2.back() << endl;
    //cout << ints2.empty() << endl;
    //cout << ints.empty() << endl;
    //cout << ints2.at(1) << endl;
    //cout << ints.at(1) << endl;
    //ints.resize(2);
    
    //ints.assign(3, 2);
    //ints.insert(0,1);
    ints.erase(0);
    cout << ints.size() << endl;
    cout << ints.at(0) << endl;
    

    ints.~IntVector();
    ints2.~IntVector();
}