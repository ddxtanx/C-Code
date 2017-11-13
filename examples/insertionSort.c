#include <stdio.h>
#include "../sorting/insertionSort.h"
#include "../helperLibs/arrayFuncs.h"
#include "../helperLibs/memoryManage.h"
int main(){
    int size;
    printf("Size of array: ");
    scanf("%d", &size);
    int maxNum;
    printf("Max Num: ");
    scanf("%d", &maxNum);
    double* arr = randomArray(size, maxNum);
    double* sorted = insertionSort(arr, size);
    printArray(arr, size);
    printArray(sorted, size);

    freeWrapper(arr);
    freeWrapper(sorted);
}