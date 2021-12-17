//include any standard libraries needed
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   ifstream ifs;
   double n;
   int size = 0;
   int index;
   // verify file name provided on command line
   ifs.open(argv[1]);
   // open file and verify it opened
   if(!ifs.is_open()){
      cout << "Error Opening" << argv[1] << endl;
      return 1;
   }
   // Declare an array of doubles of size ARR_CAP.
   double doubles[ARR_CAP];
   
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   while (ifs >> n){
      doubles[size] = n;
      ++size;
   }
   // Call the mean function passing it this array and output the 
   // value returned.

   cout << "Mean: " << mean(doubles, size) << endl << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   cout << "Enter index of value to be removed (0 to "<< size - 1 << "): " ;
   cin >> index;
   cout << endl << endl;
	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(doubles, size);
   cout << endl << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(doubles, size, index);
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(doubles, size);
   cout << endl << endl;
   
   // Call the mean function again to get the new mean
   cout << "Mean: " << mean(doubles, size) << endl;
   
	return 0;
}

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize){
   double total = 0;
   for(int i = 0; i < arraySize; ++i){
      total += array[i];
   }
   return total / arraySize;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){
   int newIndex = 0;
   double newArray[arraySize - 1];
   for(int i = 0; i < arraySize; ++i){
      if(i != index){
         newArray[newIndex] = array[i];
         ++newIndex;
      }
   }
   --arraySize;
   for(int i = 0; i < arraySize; ++i){
      array[i] = newArray[i];
   }
}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
   for(int i = 0; i + 1 < arraySize; ++i){
      cout << array[i] << ", ";
   }
   cout << array[arraySize - 1];
}
