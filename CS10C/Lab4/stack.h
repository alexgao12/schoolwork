#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 20;

template<typename T>
class stack{

    private:
        int size;
        T data[MAX_SIZE];
    public:
        stack();
        void push(T val);
        void pop();
        T top();
        bool empty();
};
template<typename T>
stack<T>::stack() : size(0){ }

template<typename T>
void stack<T>::push(T val){
    try{
        if(size == MAX_SIZE){
            throw overflow_error("Called push on full stack.");
        }
        data[size] = val;
        ++size;
    }
    catch(overflow_error& e){
        cout << e.what();
    }
        
}
template<typename T>
void stack<T>::pop(){
    try{
        if(empty()){
            throw out_of_range("Called pop on empty stack.");
        }
        --size;
    }catch(out_of_range& e){
        cout << e.what();
    }
    
}

template<typename T>
T stack<T>::top(){
    try{
        if(empty()){
            throw underflow_error("Called top on empty stack.");
        }
        return data[size - 1];
    }catch(underflow_error& e){
        cout << e.what();
        return *data;
    }
}

template<typename T>
bool stack<T>::empty(){
    return size == 0;
}


#endif