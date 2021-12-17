#include "WordLadder.h"
    /* Passes in the name of a file that contains a dictionary of 5-letter words.
       Fills the list (dict) with the words within this file. 
       If the file does not open for any reason or if any word within the file
       does not have exactly 5 characters, this function should output an
       error message and return.
    */
WordLadder::WordLadder(const string & fileName){
  ifstream inFS(fileName);
  if(!inFS.is_open()){
    cout << "File couldn't open" << endl;
    return;
  }
  string word;
  while(inFS >> word){
    if(word.length() != 5){
      cout << "Error Occurred" << endl;
      cout << word << " is not 5 characters" << endl;
      return;
    }
    //cout << word << endl;
    dict.push_back(word);
  }

  inFS.close();
}



    /* Passes in two 5-letter words and the name of an output file.
       Outputs to this file a word ladder that starts from the first word passed in
       and ends with the second word passed in.
       If either word passed in does not exist in the dictionary (dict),
       this function should output an error message and return.
       Otherwise, this function outputs to the file the word ladder it finds or outputs
       to the file, the message, "No Word Ladder Found."
    */
void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile){
//If statement to check if dictionary contains the words
//Create stack
  ofstream outFS(outputFile);
  
  if(!outFS.is_open()){
    cout << "Error opening " << outputFile << endl;
    return;
  }
  if(start == end){
    cout << "Error when ladder should just be one word." << endl;
    outFS.close();
    return;
  }
  
  
  bool startExist = false;
  bool endExist = false;
  string currentWord;
    
  for (auto i: dict){ //found on stack overflow
    if(i == start){
      startExist = true;
    }
    if(i == end){
      endExist = true;
    }
  }
  if(!startExist || !endExist){
    cout << "One of the words doesn't exist" << endl;
    return;
  }
  
  stack<string> first;
  first.push(start);
  queue<stack<string>> stacks;
  stacks.push(first);
  while(!stacks.empty()){
    string word = stacks.front().top();
    for(string j : dict){
      int off = 0;
      for(int y = 0; y < 5; ++y){
        if(word.at(y) != j.at(y)){
          ++off;
        }
      }

      if(off == 1){
        stack<string> copy(stacks.front());
        copy.push(j);
        if(j == end){
          outputStack(copy, outFS);
          outFS.close();
          return;
        }
        stacks.push(copy);
        dict.remove(word);
      }
    }
    stacks.pop();
  }
  cout << "Word Ladder not Found" << endl;
}
void WordLadder::outputStack(stack<string>& s, ofstream& outFS){
  if(s.empty()){
    return;
  }
  string value = s.top();
  s.pop();
  outputStack(s, outFS);
  outFS << value << " ";
}
/*create a Stack containing just the first word in the ladder
enqueue this Stack on to a Queue of Stacks
while this Queue of Stacks is not empty
get the word on top of the front Stack of this Queue
for each word in the dictionary
if the word is off by just one letter from the top word
create a new Stack that is a copy of the front Stack and push on this off-by-one word found
if this off-by-one word is the end word of the ladder, this new Stack contains the entire word ladder. You are done!
otherwise, enqueue this new Stack and remove this word from the dictionary
dequeue this front stack
if the Queue is empty and you didn't find the word ladder, a word ladder does not exist for these 2 words*/