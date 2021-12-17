#include "HashTable.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/

HashTable::HashTable (int s) {
	size = s;
  hashTable = new vector<Node*>(s, nullptr);
  //cout << HashTable->size() << endl;
  // for(unsigned i = 0; i < size; ++i){
  //   HashTable[i] = nullptr;
  // }
}

/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(Node* s) {
  long long hash = 5381;
  string s1 = s->token;
  for(char c : s1){
    hash = (hash* 3) + c;
  }
  //cout << hash % size << endl;
  return hash % size;
}

int HashTable::computeHash(const string s) {
  long long hash = 5381;
  for(char c : s){
    hash = (hash* 3) + c;
  }
  return hash % size;
}

/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearenc->tokene with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(Node* s) {
  // for(char c: s){
  //   c = tolower(c);
  // }
  int hash = computeHash(s);
  //cout << "test" << endl;
  
    while(hashTable->at(hash) != nullptr){
      ++hash;
      if(hash == size){
        hash = 0;
      }
    }
    hashTable->at(hash) = s;
    //hashTable->at(hash) = new Node(s, score);
}

bool HashTable::contains(const string &s) {
  // for(char c: s){
  //   c = tolower(c);
  // }
  //cout << "test2" << endl;
  int orighash = computeHash(s);
  int hash = orighash;
  //cout << hash << endl;
  //cout << HashTable->size() << endl;
  while(hashTable->at(hash) != nullptr){
     ////cout << "test3" << endl;
     if(hash == size){
       hash = 0;
     }else if(hashTable->at(hash)->token == s){
       return true;
     }
     ++hash;
     if(hash == orighash){
       return false;
     }
   }
   return false;
   
}

int HashTable::getCode(const string s){
  return hashTable->at(computeHash(s))->code;
}

