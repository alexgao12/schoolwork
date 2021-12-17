#include "HashTable.h"
#include "WordEntry.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/

HashTable::HashTable (int s) {
	size = s;
  hashTable = new vector<WordEntry*>(s, nullptr);
  //cout << hashTable->size() << endl;
  // for(unsigned i = 0; i < size; ++i){
  //   hashTable[i] = nullptr;
  // }
}

/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
  long sum = 0;
  // string dummy = "";
  // char c;
  // for(unsigned i = 0; i < s.length(); i++){
  //   c = tolower(s[i]);
  //   dummy += c;
  //   sum += c;
  // }
  for(char c : s){
    sum += c;
  }
  return sum % size;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s, int score) {
  // for(char c: s){
  //   c = tolower(c);
  // }
  int hash = computeHash(s);
  //cout << "test" << endl;
  if(this->contains(s)){
    //cout << "test1" << endl;
    while(hashTable->at(hash) != nullptr && hashTable->at(hash)->getWord() != s){
      if(hash == size){
        hash = 0;
      }
      ++hash;
    }
    hashTable->at(hash)->addNewAppearance(score);
  }
  else{
    while(hashTable->at(hash) != nullptr){
      if(hash == size){
        hash = 0;
      }
      ++hash;
    }
    hashTable->at(hash) = new WordEntry(s, score);
  }
	
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(const string &s) {
  // for(char c: s){
  //   c = tolower(c);
  // }
  if(this->contains(s)){
    int hash = computeHash(s);
    while(hashTable->at(hash) != nullptr && hashTable->at(hash)->getWord() != s){
      if(hash == size){
        hash = 0;
      }
      ++hash;
    }
    return hashTable->at(hash)->getAverage();
  }else{
    return 2.0;
  }
}

/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(const string &s) {
  // for(char c: s){
  //   c = tolower(c);
  // }
  //cout << "test2" << endl;
  int orighash = computeHash(s);
  int hash = orighash;
  //cout << hash << endl;
  //cout << hashTable->size() << endl;
  while(hashTable->at(hash) != nullptr){
     ////cout << "test3" << endl;
     if(hash == size){
       hash = 0;
     }else if(hashTable->at(hash)->getWord() == s){
       return true;
     }
     ++hash;
     if(hash == orighash){
       return false;
     }
   }
   return false;
   
}

