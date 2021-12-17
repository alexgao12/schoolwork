#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <iostream>
#include <cstdlib>
#include "WordEntry.h"

using namespace std;

class HashTable {

 private:
  //WordEntry* hashTable;

	vector<WordEntry*> *hashTable;
  //WordEntry* hashTable[];
	int size;

 public:
	HashTable(int);
	bool contains(const string &);
	double getAverage(const string &);
	void put(const string &, int);
 
 private:
	int computeHash(const string &);
};

#endif
