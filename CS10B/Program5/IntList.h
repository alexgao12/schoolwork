#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
	int value;
	IntNode *next;
	IntNode(int value) : value(value), next(nullptr) { }
};

class IntList {
 private:
	IntNode *head;
	IntNode *tail;
 public:
	IntList();
	IntList(const IntList&);	
	~IntList();
	void insert_ordered(int);
	void push_front(int);
	void push_back(int);
	void pop_front();
	void clear();
	void selection_sort();
	void remove_duplicates();
	bool empty() const;
	const int & front() const;
	const int & back() const;
	friend ostream & operator<<(ostream &, const IntList &);
	IntList& operator = (const IntList& rhs);
};

#endif
