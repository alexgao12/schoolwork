#include "IntList.h"

int main(){

    IntList list = IntList();

    // test.push_front(3);
    // test.push_front(4);
    // test.pop_back();
    // test.pop_front();
    // test.pop_back();
    // cout << test.empty() << endl;
    // test.pop_front();
    // test.push_back(2);
    // test.push_front(4);
    // test.push_front(-1);
    // cout << test.empty() << endl;
    list.push_front(7);
    list.push_back(5);
    cout<<list<<endl;
    list.push_back(1);
    list.push_front(6);
    list.pop_back();
    cout<<list<<endl;
    list.printReverse();

    // cout << test << endl;
    // test.printReverse();
    // cout << endl;
    return 0;   
}