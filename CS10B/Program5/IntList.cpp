#include "IntList.h"

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::IntList(const IntList& cpy){
    if(cpy.head != nullptr){
        IntNode* currNode = cpy.head;
        IntNode* temp = new IntNode(currNode->value);
        head = temp;
        if(cpy.head != cpy.tail){
            for(currNode = cpy.head->next;currNode != cpy.tail; currNode = currNode->next){
                temp->next = new IntNode(currNode->value);
                temp = temp->next;
            }
            temp->next = new IntNode(currNode->value);
            tail = temp->next;
        }
        else{
            tail = temp;
        }
    }
    else{
        head = nullptr;
        tail = nullptr;
    }
}

IntList::~IntList(){
    IntNode* currNode;
    IntNode* temp;
    for(currNode = head;currNode != nullptr; currNode = temp){
        temp = currNode->next;
        delete currNode;
    }
    head = nullptr;
    tail = nullptr;
}

IntList& IntList::operator = (const IntList& rhs){
    if (this != &rhs){
        this->~IntList();
        IntList* temp = new IntList(rhs);
        head = temp->head;
        tail = temp->tail;
    }
    return *this;
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

void IntList::push_back(int value){
    if (head == nullptr){
        head = new IntNode(value);
        tail = head;
    }
    else{
        IntNode* temp = new IntNode(value);
        tail->next = temp;
        tail = temp;
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

void IntList::selection_sort(){
    IntNode* temp;
    for(IntNode* currNode = head; currNode != nullptr; currNode = currNode->next){
        int min = currNode->value;
        min = currNode->value;
        temp = currNode;
        for(IntNode* currNode2 = currNode; currNode2 != nullptr; currNode2 = currNode2->next){
            if(currNode2->value < min){
                temp = currNode2;
                min = currNode2->value;
            }
        }
        temp->value = currNode->value;
        currNode->value = min;
    }
}

void IntList::insert_ordered(int value){
    IntNode* temp = new IntNode(value);
    IntNode* prev = head;
    bool complete = false;
    if(head == nullptr || temp->value < prev->value){
        push_front(value);
        delete temp;
    }
    else{
        for(IntNode* currNode = head->next; currNode != nullptr; currNode = currNode->next){
            if(!complete){
                if(currNode->value >= temp->value){
                    temp->next = currNode;
                    prev->next = temp;
                    complete = true;
                }
                prev = prev->next;
            }
        }
        if(!complete){
            push_back(value);
            delete temp;
        }
    }
}

void IntList::remove_duplicates(){
    IntNode* prev = nullptr;
    for(IntNode* currNode = head; currNode != nullptr; currNode = currNode->next){
        prev = currNode;
        for(IntNode* currNode2 = currNode->next; currNode2 != nullptr; currNode2 = prev->next){
            if(currNode2->value == currNode->value){
                if(currNode2 == tail){
                    tail = prev;
                    delete currNode2;
                    prev->next = nullptr;
                }
                else{
                    prev->next = currNode2->next;
                    delete currNode2;
                }
            }
            else{
                prev = prev->next;
            }
        }
    }
}

void IntList::clear(){
    this->~IntList();
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

