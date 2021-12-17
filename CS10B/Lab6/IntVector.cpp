#include "IntVector.h"

IntVector::IntVector(){
    _size = 0;
    _capacity = 0;
    data = new int[0];
}

IntVector::IntVector(unsigned size, int value){
    _size = size;
    _capacity = size;
    data = new int[size];
    for(unsigned i = 0; i < size; ++i){
        data[i] = value;
    }
}

IntVector::~IntVector(){
    delete[] data;
}

unsigned IntVector::size() const{
    return _size;
}

unsigned IntVector::capacity() const{
    return _capacity;
}

bool IntVector::empty() const{
    if(_size == 0){
        return true;
    }
    return false;
}

const int& IntVector::at(unsigned index) const{
    if(index < _size){
        return data[index];
    }
    throw out_of_range("IntVector::at_range_check");
    
}

int& IntVector::at(unsigned index){
    if(index < _size){
        return data[index];
    }
    throw out_of_range("IntVector::at_range_check");
}

const int& IntVector::front() const{
    return data[0];
}

const int& IntVector::back() const{
    return data[_size - 1];
}