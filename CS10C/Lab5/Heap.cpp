#include <iostream>
#include "Heap.h"

using namespace std;

  /*Initializes an empty heap.*/
Heap::Heap(){
  numItems = 0;
}

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
void Heap::enqueue ( PrintJob* pj){
  if(numItems < MAX_HEAP_SIZE){
    int i = numItems;
    arr[numItems] = pj;
    if(numItems != 0){
      while(pj->getPriority() > arr[(i - 1)/2]->getPriority()){
        PrintJob* temp = arr[(i-1)/2];
        arr[(i-1)/2] = pj;
        arr[i] = temp;
        i = (i - 1)/2;
        
        if(i == 0 ){
          ++numItems;
          // for(int j = 0; j < numItems; ++j){
          //   cout << arr[j]->getPriority() << endl;
          // }
          return;
        } 
      }
    }
    ++numItems;
    // for(int j = 0; j < numItems; ++j){
    //   cout << arr[j]->getPriority() << endl;
    // }

  }

  
}

  /*Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
void Heap::dequeue (){
  try{
    if(numItems == 0){
      throw out_of_range("Empty Queue");
    }
    int i = 0;
    arr[0] = arr[numItems - 1];
    --numItems;
    if(numItems != 1){
      if(numItems == 2){
        if(arr[0]->getPriority() < arr[1]->getPriority()){
          PrintJob* temp = arr[0];
          arr[0] = arr[1];
          arr[1] = temp;
          return;
        }else{
          return;
        }
      }
      while((i* 2) + 2 < numItems){
        int bigger = i;
        if(arr[i]->getPriority() > arr[(i* 2) + 1]->getPriority() && arr[i]->getPriority() > arr[(i* 2) + 2]->getPriority()){
          return;
        }
        if(arr[(i* 2) + 1]->getPriority() >= arr[(i* 2) + 2]->getPriority()){
          bigger = (i*2) + 1;
        }
        else{
          bigger = (i*2)+2;
        }
        
        PrintJob* temp2 = arr[i];
        arr[i] = arr[bigger];
        arr[bigger] = temp2;
        i = bigger;
      }
    }
  }
  catch(out_of_range& e){
    cout << e.what() << endl;
  }
}

  /*Returns the node with highest priority.*/
PrintJob* Heap::highest(){
  try{
    if(numItems == 0){
      throw out_of_range("Empty Queue");
    }
    else{
      return arr[0];
    }
  }
  catch(out_of_range& e){
    cout << e.what() << endl;
    return arr[0];
  }
}

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
void Heap::print ( ){
  // for(int i = 0; i < numItems; ++i){
  //   cout << arr[i]->getPriority() << endl;
  // }
  if(numItems != 0){
    cout << "Priority: " << highest()->getPriority() << ", Job Number: " << highest()->getJobNumber() << ", Number of Pages: " << 
      highest()->getPages() << endl;
  }else{
    cout << "Empty Queue" << endl;
  }
}