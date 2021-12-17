#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <iostream>
#include <cstdlib>
#include <vector>


using namespace std;

struct Node{
  string token;
  int code;
  int frequency;
};

class HashTable {

 private:
  //WordEntry* hashTable;

	vector<Node*> *hashTable;
  //WordEntry* hashTable[];
	int size;

 public:
	HashTable(int);
	bool contains(const string &s);
	void put(Node*);
  int getCode(const string s);
 

	int computeHash(Node*);
  int computeHash(const string s);
};

#endif
