#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    IntNode* currNode;
    IntNode* temp;
    for(currNode = head;currNode != nullptr; currNode = temp){
        temp = currNode->next;
        delete currNode;
    }
}

void IntList::push_front(int value){
    if (head == nullptr){
        head = new IntNode(value);
        tail = head;
    }
    else{
        IntNode* temp = new IntNode(value);
        temp->next = head;
        head = temp;
    }
}

void IntList::pop_front(){
    if(head != nullptr && head != tail){
        IntNode* temp = head->next;
        delete head;
        head = temp;
    }
    else if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
}

bool IntList::empty() const{
    return head == nullptr;
}


const int& IntList::front() const{
    return head->value;
}

const int& IntList::back() const{
    return tail->value;
}

ostream& operator << (ostream& out, const IntList& list){
    if (list.head == nullptr){
        return out;
    }
    IntNode* currNode = list.head;
    out << currNode->value;
    for(currNode = list.head->next;currNode != nullptr; currNode = currNode->next){
        out << " " << currNode->value;
    }
    return out;
}

