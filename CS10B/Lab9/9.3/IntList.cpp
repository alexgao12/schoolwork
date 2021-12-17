#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

bool IntList::exists(int value) const{
   return exists(head, value);
}

bool IntList::exists(IntNode* start, int value) const{
   if(start == nullptr){
      return false;
   }
   if(value == start->value){
      return true;
   }
   if(start->next == nullptr){
      return false;
   }
   
   return exists(start->next, value);
}

ostream& operator <<(ostream& out, const IntList& list){
   out << list.head;
   return out;
}

ostream& operator <<(ostream& out, IntNode* head){
   if(head == nullptr){
      return out;
   }
   if(head->next == nullptr ){
      out << head->value;
   }else{
      out << head->value << " " << head->next;  
   }
   
   return out;
}