#include "IntList.h"

IntList::IntList(){
    dummyHead = new IntNode(-1);
    dummyTail = new IntNode(-1);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}

IntList::~IntList(){
    IntNode* temp;
    for(IntNode* currNode = dummyHead; currNode != nullptr; currNode = temp){
        temp = currNode->next;
        delete currNode;
    }
}

void IntList::push_front(int value){
    IntNode* temp = new IntNode(value);
    temp->prev = dummyHead;
    temp->next = dummyHead->next;
    dummyHead->next = temp;
    temp->next->prev = temp;
}

void IntList::pop_front(){
    if(!empty()){
        IntNode* temp = dummyHead->next; 
        dummyHead->next = dummyHead->next->next;
        dummyHead->next->prev = dummyHead;
        delete temp;
    }
}

void IntList::push_back(int value){
    IntNode* temp = new IntNode(value);
    temp->next = dummyTail;
    temp->prev = dummyTail->prev;
    temp->prev->next = temp;
    dummyTail->prev = temp;
    
}

void IntList::pop_back(){
    if(!empty()){
        IntNode* temp = dummyTail->prev;
        dummyTail->prev = dummyTail->prev->prev;
        dummyTail->prev->next = dummyTail;
        delete temp;
    }
}

bool IntList::empty() const{
    return dummyHead->next == dummyTail;
}

void IntList::printReverse() const{
    if(!empty()){
        IntNode* currNode = dummyTail->prev;
        cout << currNode->data;
        for(currNode = currNode->prev; currNode != dummyHead; currNode = currNode->prev){
            cout << " " << currNode->data;
        }
    }
}

ostream& operator << (ostream& out, const IntList &rhs){
    if(!rhs.empty()){
        IntNode* currNode = rhs.dummyHead->next;
        out << currNode->data;
        for(currNode = currNode->next; currNode != rhs.dummyTail; currNode = currNode->next){
            out << " " << currNode->data;
        } 
    }
    return out;
}

