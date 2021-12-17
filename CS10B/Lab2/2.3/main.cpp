#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   vector <int> averageValues;
   string inputFile;
   string outputFile;
   ifstream ifs; 
   ofstream ofs;
   int n, avg;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];
   // Create input stream and open input csv file.
   ifs.open(inputFile);
   // Verify file opened correctly.
   if(!ifs.is_open()){
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
   // Output error message and return 1 if file stream did not open correctly.
   
   // Read in integers from input file to vector.
   while(ifs >> n){
      averageValues.push_back(n);
      ifs.ignore();
   }
   // Close input stream.
   ifs.close();
   // Get integer average of all values read in.
   avg = averageValues.at(0);
   for(unsigned i = 1; i < averageValues.size(); ++i){
      avg += averageValues.at(i);
   }
   avg /= averageValues.size();
   // Convert each value within vector to be the difference between the original value and the average.
   for(unsigned i = 0; i < averageValues.size(); ++i){
      averageValues.at(i) -= avg;
   }
   // Create output stream and open/create output csv file.
   ofs.open(outputFile);

   // Verify file opened or was created correctly.
   if(!ofs.is_open()){
      cout << "Error opening " << outputFile << endl;
      return 1;
   }
   // Output error message and return 1 if file stream did not open correctly.
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(unsigned i = 0; i < averageValues.size() -1; ++i){
      ofs << averageValues.at(i) << ",";
   }
   ofs << averageValues.at(averageValues.size() - 1);
   ofs.close();
   // Close output stream.
   
   return 0;
}