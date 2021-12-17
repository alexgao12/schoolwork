#include "minFunc.h"
#include <algorithm>
const int * min(const int arr[], int arrSize) {
    if(arrSize == 0){
        return nullptr;
    }
    if(arrSize == 1){
        return &arr[0];
    }
    return &std::min(arr[0], *min(arr + 1, arrSize - 1));
}