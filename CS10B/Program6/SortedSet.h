#include "IntList.h"

#ifndef __SORTEDSET_H__
#define __SORTEDSET_H__

class SortedSet : public IntList{
    public:
        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();
        bool in(int value);
        void add(int value);
        void push_front(int value);
        void push_back(int value);
        void insert_ordered(int value);
        SortedSet operator |(const SortedSet& rhs);
        SortedSet operator &(const SortedSet& rhs);
        SortedSet& operator |=(const SortedSet& rhs);
        SortedSet& operator &=(const SortedSet& rhs);
    private:
};

#endif