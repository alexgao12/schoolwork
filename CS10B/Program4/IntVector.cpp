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

void IntVector::expand(){
    if(_capacity == 0){
        int* temp = new int[1];
        delete data;
        data = temp;
        _capacity = 1;
    }
    else{
        expand(_capacity*2);
    }
}

void IntVector::expand(unsigned amount){
   int* temp = new int[amount];
    for(unsigned i = 0; i < _size; ++i){
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    _capacity = amount;
}     

void IntVector::clear(){
    _size = 0;
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
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return data[index];
}

const int& IntVector::front() const{
    return data[0];
}

int& IntVector::front(){
    return data[0];
}

const int& IntVector::back() const{
    return data[_size - 1];
}

int& IntVector::back(){
    return data[_size - 1];
}

void IntVector::push_back(int value){
    if(_size + 1 > _capacity){
        expand();
    }
    data[_size] = value;
    ++_size;
}

void IntVector::pop_back(){
    --_size;
}

void IntVector::resize(unsigned size, int value){
    if(size > _capacity){
        if(_capacity * 2 > size){
            expand();
        }
        else{
            expand(size);
        }
    }
    if(size < _size){
        _size = size;
    }
    else{
        for (unsigned i = _size; i < size; ++i){
            data[i] = value;
        }
        _size = size;
    }
}

void IntVector::reserve(unsigned n){
    if(_capacity < n){
        expand(n);
    }
}

void IntVector::assign(unsigned n, int value){
    if(n > _capacity){
        if(_capacity * 2 > n){
            expand();
        }
        else{
            expand(n);
        }
    }
    int* temp = new int[n];
    delete data;
    data = temp;
    for(unsigned i = 0; i < n; ++i){
        data[i] = value;
    }
    _size = n;
}

void IntVector::insert(unsigned index, int value){
    if(index > _size){
        throw out_of_range("IntVector::insert_range_check");
    }
    if(_size + 1 > _capacity){
        expand();
    }
    int* temp = new int[_size + 1];
    for(unsigned i = 0; i < index; ++i){
        temp[i] = data[i];
    }
    temp[index] = value;
    for(unsigned i = index + 1; i <= _size; ++i){
        temp[i] = data[i-1];
    }
    delete[] data;
    data = temp;
    ++_size;
}

void IntVector::erase(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }
    int* temp = new int[_size - 1];
    for(unsigned i = 0; i < index; ++i){
        temp[i] = data[i];
    }
    for(unsigned i = index; i < _size - 1; ++i){
        temp[i] = data[i+1];
    }
    delete[] data;
    data = temp;
    _size -= 1;
}