#include "SortedSet.h"

SortedSet::SortedSet() : IntList() { }

SortedSet::SortedSet(const SortedSet& cpy) : IntList(cpy) { }

SortedSet::SortedSet(const IntList& cpy) : IntList(cpy) { 
    this->remove_duplicates();
    this->selection_sort();
}

SortedSet::~SortedSet(){
    this->~IntList();
}

bool SortedSet::in(int value){
    for(IntNode* currNode = head; currNode != nullptr; currNode = currNode->next){
        if(currNode->value == value){
            return true;
        }
    }
    return false;
}

void SortedSet::add(int value){
    if(head == nullptr){
        IntList::push_front(value);
    }
    else if(head->value > value){
        IntList::push_front(value);
    }
    else{
        for(IntNode* currNode = head; currNode->next != nullptr; currNode = currNode->next){
            if(currNode->value == value){
                return;
            }
            else if(currNode->next->value > value){
                IntNode* temp = currNode->next;
                currNode->next = new IntNode(value);
                currNode->next->next = temp;
                return;
            }
        }
        if(tail->value != value){
            IntList::push_back(value);
        }
    }
    
}

void SortedSet::push_front(int value){
    add(value);
}

void SortedSet::push_back(int value){
    add(value);
}

void SortedSet::insert_ordered(int value){
    add(value);
}

SortedSet SortedSet::operator |(const SortedSet& rhs){
    SortedSet temp = SortedSet();
    IntNode* i = this->head;
    IntNode* j = rhs.head;

    while(i != nullptr && j != nullptr){
        if(i->value < j->value){
            temp.add(i->value);
            i = i->next;
        }
        else if(j->value < i->value){
            temp.add(j->value);
            j = j->next;
        }
        else{
            temp.add(i->value);
            i = i->next;
            j = j->next;
        }
    }
    if(i == nullptr){
        for(j = j; j != nullptr; j = j->next){
            temp.add(j->value);
        }
    }
    else if(j == nullptr){
        for(i = i; i != nullptr; i = i->next){
            temp.add(i->value);
        }
    }

    return temp;
}

SortedSet SortedSet::operator &(const SortedSet& rhs){
    SortedSet temp;
    IntNode* i = this->head;
    IntNode* j = rhs.head;

    while(i != nullptr && j != nullptr){
        if(i->value < j->value){
            i = i->next;
        }
        else if(j->value < i->value){
            j = j->next;
        }
        else{
            temp.add(i->value);
            i = i->next;
            j = j->next;
        }
    }

    return temp;
}

SortedSet& SortedSet::operator |=(const SortedSet& rhs){
    SortedSet* temp = new SortedSet((*this)|rhs);
    this->head = temp->head;
    this->tail = temp->tail;
    return *this;
}
SortedSet& SortedSet::operator &=(const SortedSet& rhs){
    SortedSet* temp = new SortedSet((*this)&rhs);
    this->head = temp->head;
    this->tail = temp->tail;
    return *this;    
}
