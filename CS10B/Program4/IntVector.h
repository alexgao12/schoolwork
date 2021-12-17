#ifndef INTVECTOR_H
#define INTVECTOR_H

#include<cstdlib>
#include<stdexcept>


using namespace std;

class IntVector{

    private:
        unsigned _size;
        unsigned _capacity;
        int* data = nullptr;
        void expand();
        void expand(unsigned amount);

    public: 
        IntVector();
        IntVector(unsigned size, int value = 0);
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int& at(unsigned index) const;
        int& at(unsigned index);
        const int& front() const;
        int& front();
        const int& back() const;
        int& back();
        void insert(unsigned index, int value);
        void erase(unsigned index);
        void push_back(int value);
        void assign(unsigned n, int value);
        void pop_back();
        void clear();
        void resize(unsigned size, int value = 0);
        void reserve(unsigned n);



};
#endif