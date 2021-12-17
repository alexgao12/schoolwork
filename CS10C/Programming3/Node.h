#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;
class Node{
  public:
    Node();
    Node(const string& s);
    Node* left() const{ return eft;}
    Node* right() const{ return ight;}
    Node* parent() const{ return arent;}
    string data() const{ return ata;}
    void setLeft(Node* n){ eft = n;}
    void setRight(Node* n){ ight = n;}
    void setData(string s){ ata = s;}
    void setParent(Node* n){ arent = n;}
    int count(){ return ount;}
    void increment(){ ++ount;}
    void decrement(){ --ount;}
  private:
    Node *eft;
    Node *ight;
    Node *arent;
    string ata;
    int ount = 0;
};
#endif