#include <iostream>
#include <fstream>
#include <vector>
#include <ostream>
#include "HashTable.h"

using namespace std;

int median_of_three(vector<Node*> &n, int low, int high){
  int midpoint = low + ((high - low) / 2);
  int a = n.at(low)->frequency;
  int b = n.at(midpoint)->frequency;
  int c = n.at(high)->frequency;
  if(a < b){ //idea to swap from stack overflow
    swap(n.at(low),n.at(midpoint));
    swap(a,b);
  }
  if(a < c){
    swap(n.at(low),n.at(high));
    swap(a,c);
  }
  if(b < c){
    swap(n.at(midpoint),n.at(high));
    swap(b, c);
  }
  return midpoint;
} 

int Partition_median(vector<Node*> &numbers, int lowIndex, int highIndex) {//adapted from zybooks
   // Find Pivot from median of 3
   //cout << median_of_three(numbers, highIndex + 1) << endl;
  //  for (int i = lowIndex; i < highIndex + 1; ++i){
  //    cout << numbers[i] << " ";
  //  }
  //  cout << endl;
  int midpoint = lowIndex + (highIndex - lowIndex) / 2;
  int pivot = numbers.at(midpoint)->frequency;
   
  // cout << pivot << endl;
 
   bool done = false;
   while (!done) {
    // Increment lowIndex while numbers[lowIndex] < pivot
    while (numbers.at(lowIndex)->frequency > pivot) {
        lowIndex += 1;
    }
  
    // Decrement highIndex while pivot < numbers[highIndex]
    while (pivot > numbers.at(highIndex)->frequency) {
        highIndex -= 1;
    }
  
    // If zero or one elements remain, then all numbers are
    // partitioned. Return highIndex.
    if (lowIndex >= highIndex) {
      //cout << "test" << endl;
        done = true;
    }
    else {
        // Swap numbers[lowIndex] and numbers[highIndex]
        // Node* temp = numbers.at(lowIndex);
        // numbers.at(lowIndex) = numbers.at(highIndex);
        // numbers.at(highIndex) = temp;
        swap(numbers.at(lowIndex),numbers.at(highIndex));
      
        // Update lowIndex and highIndex
        lowIndex += 1;
        highIndex -= 1;
    }
  }
  //cout << lowIndex << endl;
  // cout << highIndex << endl;
  return highIndex;
}

void bubbleSort(vector<Node*> &arr) {  
    int i, j;  
    for (i = 0; i < arr.size(); i++) {    
      
    // Last i elements are already in place  
    for (j = 0; j < arr.size() - 1; j++){ 
        if (arr.at(j)->frequency < arr.at(j+1)->frequency) {
            swap(arr.at(j), arr.at(j+1));  
        }
      }
    }
}  

void Quicksort_medianOfThree(vector<Node*> &numbers, int i, int k){ // broken
  // int size = k - i + 1;
  // if(size <= 3  ){
  //   return;
  // }
  if(i >= k){
    return;
  }
  int t = Partition_median(numbers, i, k);
  // cout << t << endl;
  // Partition_median(numbers, i, t);
  // Partition_median(numbers, t + 1, k);
  Quicksort_medianOfThree(numbers, i, t);
  Quicksort_medianOfThree(numbers, t + 1, k);
}

int main() {
  
  ifstream fin;
  string fileName;
  cout << "File Name: ";
  cin >> fileName;
  cout << endl;
  fin.open(fileName);
  if(!fin.is_open()){
    cout << "file not open" << endl;
    exit(1);
  }
  string input;
  bool contains = false;
  vector<Node*> nodes;
  while(fin >> input){
    //cout << input << endl;
    for(int i = 0; i < nodes.size(); ++i){
      if(nodes.at(i)->token == input){
        contains = true;
        ++nodes.at(i)->frequency;
      }
    }
    if(!contains){
      Node* thing = new Node();
      thing->token = input;
      thing->frequency = 1;
      nodes.push_back(thing);
    }
    contains = false;
  }
  //cout << nodes.size() << endl;
  fin.close();
  fin.open(fileName);

  Quicksort_medianOfThree(nodes, 0 , nodes.size() - 1);
  //bubbleSort(nodes);
  //cout << "test" << endl;
  for(int i = 0; i < nodes.size(); ++i){
    nodes.at(i)->code = i;
    // << nodes.at(i)->code << endl;
  }

  HashTable* ht = new HashTable(nodes.size());
  for(Node* n : nodes){
    cout << "test" << endl;
    ht->put(n);
  }

  //ht->print();

  // for(Node* n : nodes){
  //   cout << n->frequency << endl;
  // }

  ofstream fout;
  fout.open("result.txt");
  int length;
  while(!fin.eof()){
    string s;
    int linelength = s.size();
    getline(fin, s);
    cout << s << endl;
    while(s.size() > 0){//there is no hope [t][h][e][r][e][ ]
      string substr;
      length = s.find(" ");
      cout << length << endl;
      if(length != -1){
        substr = s.substr(0, length);
        //cout << substr << endl;
        s = s.substr(length + 1, s.size());
        //cout << s << endl;
      }else{
        substr = s;
        s = "";
      }
      fout << ht->getCode(substr) << " ";
      
    }
  fout << endl;
  }
}