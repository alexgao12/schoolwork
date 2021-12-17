#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(string, char);
// Place charCnt prototype (declaration) here


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

int charCnt(string file, char ch){
   ifstream ifs;
   char c;
   int n = 0;
   ifs.open(file);
   if(!ifs.is_open()){
      cout << "Error opening " << file << endl;
      exit(1);
   }
   while(ifs.get(c)){
      if(c == ch){
         ++n;
      }
   }

   return n;
}