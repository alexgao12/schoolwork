#include "AVLTree.h"

AVLTree::AVLTree(){
  root = nullptr;
}
AVLTree::~AVLTree(){
  del(root);
}
void AVLTree::del(Node* n){
  if(n == nullptr)
    return;
  del(n->left());
  del(n->right());
  delete n;
}
void AVLTree::insert(const string &newString){
  if(search(newString)){
    Node* tempNode = returnNode(newString);
    tempNode->increment();
  }else if(root == nullptr){
    //cout << "test" << endl;
    root = new Node(newString);
    cout << root->data() << endl;
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
    //printBalanceFactors();
    rebalance();
  }
}
void AVLTree::remove(const string &key){
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
    rebalance();
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
  rebalance();
}
bool AVLTree::search(const string &key) const{
  return (returnNode(key) != nullptr) ? true : false;
}
string AVLTree::largest() const{
  if(root != nullptr){
    Node* currNode = root;
    while(currNode->right() != nullptr){
      currNode = currNode->right();
    }return currNode->data();
  }
  return "";
}
string AVLTree::smallest() const{
  if(root != nullptr){
    Node* currNode = root;
    while(currNode->left() != nullptr){
      currNode = currNode->left();
    }return currNode->data();
  }
  return "";
}
int AVLTree::height(const string& s) const{
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
    return height;
  }
  
}
void AVLTree::preOrder() const{
  preOrder(root);
}
void AVLTree::postOrder() const{
  postOrder(root);
}
void AVLTree::inOrder() const{
  inOrder(root);
}
void AVLTree::preOrder(Node* n)const{
  if(n == nullptr){
    return;
  }
  cout << n->data() << "(" << n->count() << ") ";
  preOrder(n->left());
  preOrder(n->right());
}
void AVLTree::inOrder(Node* n)const{
  if(n == nullptr){
    return;
  }
  inOrder(n->left());
  cout << n->data() << "(" << n->count() << ") ";
  inOrder(n->right());
}
void AVLTree::postOrder(Node* n)const{
  if(n == nullptr){
    return;
  }
  postOrder(n->left());
  postOrder(n->right());
  cout << n->data() << "(" << n->count() << ") ";
}
Node* AVLTree::returnNode(const string& s)const{
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

Node* AVLTree::successor(Node* n) const{
  Node* currNode = n;
  currNode = currNode->right();
  while(currNode->left() != nullptr){
    currNode = currNode->left();
  }
  return currNode;
}

void AVLTree::rebalance(){ //rebalances entire tree
  rebalance(root);
}

void AVLTree::rebalance(Node* n){
  //cout << "?" << endl;
  if(n == nullptr){
    return;
  }
  
  rebalance(n->left());
  rebalance(n->right());
  //cout << "test20" << endl;
  int leftbf = balanceFactor(n->left());
  int rightbf = balanceFactor(n->right());
  int bf = balanceFactor(n);
  //cout << "test1" << endl;
  if(bf == -2){
    if(rightbf == 1){
      rotateRight(n->right());
    }
    return rotateLeft(n);
  }
  else if(bf == 2){
    if(leftbf == -1){
      rotateLeft(n->left());
    }
    return rotateRight(n);
  }

  return;
    
}

void AVLTree::rotateRight(Node * n){
  Node* leftRightchild = n->left()->right();
  if(n->parent() != nullptr){
    if(n->parent()->left() == n){
      n->parent()->setLeft(n->left());
      n->left()->setParent(n->parent());
    }else{
      n->parent()->setRight(n->left());
      n->left()->setParent(n->parent());
    }
  }
  else{
    root = n->left();
    root->setParent(nullptr);
  }
  n->setParent(n->left());
  n->left()->setRight(n);
  n->setLeft(leftRightchild);
  if(leftRightchild != nullptr){
    leftRightchild->setParent(n);
  }

 
}

void AVLTree::rotateLeft(Node * n){
  //cout << "test4" << endl;
  Node* rightLeftchild = n->right()->left();
  if(n->parent() != nullptr){
    if(n->parent()->left() == n){
      n->parent()->setLeft(n->right());
      n->right()->setParent(n->parent());
    }else{
      //cout << "test3" << endl;
      n->parent()->setRight(n->right());
      n->right()->setParent(n->parent());
    }
  }
  else{
    root = n->right();
    root->setParent(nullptr);
  }
  n->setParent(n->right());
  n->right()->setLeft(n);
  n->setRight(rightLeftchild);
  if(rightLeftchild != nullptr){
    //cout << "test2" << endl;
    rightLeftchild->setParent(n);
  }
}

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left()){
            visualizeTree(outFS,n->left());
            outFS<<n->data() <<" -> " <<n->left()->data()<<";"<<endl;    
        }

        if(n->right()){
            visualizeTree(outFS,n->right());
            outFS<<n->data() <<" -> " <<n->right()->data()<<";"<<endl;    
        }
    }
}
int AVLTree::balanceFactor(Node* n){
  // if(n != nullptr){
  //   Node* currNode = n;
  //   Node* tempNodeLeft;
  //   Node* tempNodeRight;
  //   if(n->left() != nullptr){
  //     while(currNode->left() != nullptr || currNode->right() != nullptr){//goes to bottom
  //       //currNode = currNode->left();
  //       // if(currNode->left() != nullptr){
  //       //   currNode = currNode->left();  
  //       // }else if(currNode->right() != nullptr){
  //       //   currNode = currNode->right();
  //       // }
  //       if(left > right){
  //         curr = curr->left
  //       }
  //     }
    
  //   }
  //   tempNodeLeft = currNode;
  //   currNode = n;
  //   if(n->right() != nullptr){
  //     while(currNode->right() != nullptr || currNode->left() != nullptr){
  //       //currNode = currNode->right();
  //       if(currNode->right() != nullptr){
  //         currNode = currNode->right();
  //       }else if(currNode->left() != nullptr){
  //         currNode = currNode->left();  
  //       }
  //     }
  //   }
  //   tempNodeRight = currNode;
  //   return height(tempNodeLeft->data()) - height(tempNodeRight->data());
  // }
  // return -1;
  if(n == nullptr){
    return -1;
  }
  return findHeight(n->left()) - findHeight(n->right());
}
int AVLTree::findHeight(Node* n) const{
  if(n == nullptr){
    return 0;
  }
  int left = findHeight(n->left()), right = findHeight(n->right());
  return (left > right) ? left + 1 : right + 1;
}
void AVLTree::printBalanceFactors(){
  printBalanceFactors(root);
}
void AVLTree::printBalanceFactors(Node* n){
  if(n == nullptr){
    return;
  }
  printBalanceFactors(n->left());
  cout << n->data() << "(" << balanceFactor(n) << "), ";
  printBalanceFactors(n->right());
}