#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}
BSTree::~BSTree(){
  del(root);
}
void BSTree::del(Node* n){
  if(n == nullptr)
    return;
  del(n->left());
  del(n->right());
  delete n;
}
void BSTree::insert(const string &newString){
  if(search(newString)){
    Node* tempNode = returnNode(newString);
    tempNode->increment();
  }else if(root == nullptr){
    root = new Node(newString);
  }else{
    Node* currNode = root;
    Node* newNode = new Node(newString);
    while(currNode != nullptr){
      if(newString < currNode->data()){
        if(currNode->left() == nullptr){
          currNode->setLeft(newNode);
          newNode->setParent(currNode);
          currNode = nullptr;
        }else{
          currNode = currNode->left();
        } 
      }else{
        if(currNode->right() == nullptr){
          currNode->setRight(newNode);
          newNode->setParent(currNode);
          currNode = nullptr;
        }else{
          currNode = currNode->right();
        }
      }
    }
  }
  
}
void BSTree::remove(const string &key){
  Node* currNode = returnNode(key);
  if(currNode == nullptr){
    return;
  }
  else if(currNode->count() > 1){ //decrements
    currNode->decrement();
    return;
  }
  else if(currNode == root && currNode->left() == nullptr && currNode->right() == nullptr){ //root only tree
    delete currNode;
    root = nullptr;
    return; 
  }
  else if(currNode->left() == nullptr){// 1 or 0 children
    Node* par = currNode->parent();
    if(par == nullptr){ //is root
      root = currNode->right();
      root->setParent(nullptr);
    }
    else if(par->left() == currNode){ // on left
      par->setLeft(currNode->right());
      if(currNode->right() != nullptr){
        currNode->right()->setParent(par); //sets child's parent to currNode parent
      }
    }
    else{ // on right
      par->setRight(currNode->right());
      if(currNode->right() != nullptr){
        currNode->right()->setParent(par); //sets child's parent to currNode parent
      }
    }
  }
  else if(currNode->right() == nullptr){// 1 child
    Node* par = currNode->parent();
    if(par == nullptr){
      root = currNode->left();
      root->setParent(nullptr);
    }
    else if(par->left() == currNode){
      par->setLeft(currNode->left());
      currNode->left()->setParent(par);
    }
    else{
      par->setRight(currNode->left());
      currNode->left()->setParent(par);
    }
  }
  else{ // 2 children
    //cout << "test1" << endl;
    Node* par = currNode->parent();
    Node* succ = successor(currNode);
    //cout << "test2" << endl;
    Node* succpar = succ->parent();
    if(succpar != currNode){
      //cout << "test2a" << endl;
      succpar->setLeft(succ->right());
      if(succ->right() != nullptr){
        succ->right()->setParent(succpar);
      }
    }
    if(par == nullptr){ // is root
      root = succ;
      succ->setParent(nullptr);
      succ->setLeft(currNode->left());
      //cout << "test3" << endl;
      if(succ->left() != nullptr){
        //cout << "test4" << endl;
        succ->left()->setParent(succ);
      }
      if(currNode->right() != succ){
        //cout << "test5" << endl;
        succ->setRight(currNode->right());
      }
      if(succ->right() != nullptr){
        //cout << "test6" << endl;
        succ->right()->setParent(succ);
      }
      //cout << "test7" << endl;
    }
    else if(par->left() == currNode){ // on left
      par->setLeft(succ);
      succ->setParent(par);
      succ->setLeft(currNode->left());
      currNode->left()->setParent(succ);
      if(succ != currNode->right()){
          succ->setRight(currNode->right());
          currNode->right()->setParent(succ);
      }
    }
    else if(par->right() == currNode){// on right
      par->setRight(succ);
      succ->setParent(par);
      succ->setLeft(currNode->left());
      currNode->left()->setParent(succ);
      if(succ != currNode->right()){
          succ->setRight(currNode->right());
          currNode->right()->setParent(succ);
      }
    }
  }
  delete currNode;
}
bool BSTree::search(const string &key) const{
  return (returnNode(key) != nullptr) ? true : false;
}
string BSTree::largest() const{
  if(root != nullptr){
    Node* currNode = root;
    while(currNode->right() != nullptr){
      currNode = currNode->right();
    }return currNode->data();
  }
  return "";
}
string BSTree::smallest() const{
  if(root != nullptr){
    Node* currNode = root;
    while(currNode->left() != nullptr){
      currNode = currNode->left();
    }return currNode->data();
  }
  return "";
}
int BSTree::height(const string& s) const{
  Node* tempNode = returnNode(s);
  unsigned height = 0;
  if(tempNode->data() == ""){
    return -1;
  }else{
    Node* currNode = tempNode; 
    while(currNode->parent() != nullptr){
      currNode = currNode->parent();
      ++height;
    }
  }
  return height;
}
void BSTree::preOrder() const{
  preOrder(root);
}
void BSTree::postOrder() const{
  postOrder(root);
}
void BSTree::inOrder() const{
  inOrder(root);
}
void BSTree::preOrder(Node* n)const{
  if(n == nullptr){
    return;
  }
  cout << n->data() << "(" << n->count() << ") ";
  preOrder(n->left());
  preOrder(n->right());
}
void BSTree::inOrder(Node* n)const{
  if(n == nullptr){
    return;
  }
  inOrder(n->left());
  cout << n->data() << "(" << n->count() << ") ";
  inOrder(n->right());
}
void BSTree::postOrder(Node* n)const{
  if(n == nullptr){
    return;
  }
  postOrder(n->left());
  postOrder(n->right());
  cout << n->data() << "(" << n->count() << ") ";
}
Node* BSTree::returnNode(const string& s)const{
  if(root != nullptr){
    Node* currNode = root;
    while(currNode != nullptr){
      if(s == currNode->data()){
        return currNode;
      }else if(s < currNode->data()){
        currNode = currNode->left();
      }else{
        currNode = currNode->right();
      }
    }
    
  }
  return nullptr;
}

Node* BSTree::successor(Node* n) const{
  Node* currNode = n;
  currNode = currNode->right();
  while(currNode->left() != nullptr){
    currNode = currNode->left();
  }
  return currNode;
}