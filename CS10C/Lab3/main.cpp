#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <time.h>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    T temp = vals.at(index);
    unsigned returnValue = index;
    for(unsigned i = index; i < vals.size(); ++i){
        if(vals.at(i) < temp){
            temp = vals.at(i);
            returnValue = i;
        }
    }return returnValue;
}

template<typename T>
void selection_sort(vector<T> &vals){
    unsigned min;
    T temp;
    for(unsigned i = 0; i < vals.size(); ++i){
        min = min_index(vals, i);
        //cout << min << endl;
        temp = vals.at(i);
        vals.at(i) = vals.at(min);
        vals.at(min) = temp;
        //cout << "Swapping " << vals.at(i) << " with " << vals.at(min) << endl;
    }
}

template<typename T>
T getElement(vector<T> vals, int index){
    try{
        if((unsigned)index > vals.size() || index < 0){
            throw out_of_range("out of range exception occured");
        }
        return vals.at(index);
    }catch(out_of_range& e){
        cout << "out of range exception occured" << endl;
        return 0;
    }
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        cout << c << " ";
        c++;
    }
    cout << endl;
    return vals;
}

int main(){

    //Part B
    //  srand(time(0));
    //  vector<char> vals = createVector();
    //  char curChar;
    //  int index;
    //  int numOfRuns = 10;
    //  while(--numOfRuns >= 0){
    //      cout << "Enter a number: " << endl;
    //      cin >> index;
    //      curChar = getElement(vals,index);
    //      cout << "Element located at " << index << ": is " << curChar << endl;
    // }


    vector<string> vals = {"string4", "string1", "string2", "string5"};
    cout << min_index(vals, 1) << endl;
    //vector<string> vals = {"string1", "string2", "string4", "string3", "string4"};
    selection_sort(vals);
    cout << getElement(vals, 5) << endl;
    for(unsigned i = 0; i < vals.size(); ++i){
        cout << getElement(vals, i) << " ";
    }
    cout << endl;
    return 0;
}