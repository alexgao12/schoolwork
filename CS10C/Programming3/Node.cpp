#include "Node.h"

Node::Node(){
  setLeft(nullptr);
  setRight(nullptr);
  setParent(nullptr);
  setData("");
  increment();
}
  
Node::Node(const string& s){
  setLeft(nullptr);
  setRight(nullptr);
  setParent(nullptr);
  setData(s);
  increment();
}