#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string);
// Place fileSum prototype (declaration) here

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

int fileSum(string file){
   ifstream ifs;
   int sum, n;
   ifs.open(file);
   if(!ifs.is_open()){
      cout << "Error opening " << file << endl;
      exit(1);
   }

   while(ifs >> n){
      sum += n;
   }
   return sum;
}