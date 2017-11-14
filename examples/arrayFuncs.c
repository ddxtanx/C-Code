#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../helperLibs/arrayFuncs.h"
#include "../helperLibs/memoryManage.h"
int main(){
    srand(time(NULL));

    int size;
    printf("Size of array? ");
    scanf("%d", &size);

    int maxNum;
    printf("Max num? ");
    scanf("%d", &maxNum);

    double* arr =randomArray(size, maxNum);
    printArray(arr, size);

    double* reversedArray = reverseArray(arr, size);
    printArray(reversedArray, size);

    double* copiedArray = copyArray(arr, size);
    printArray(copiedArray, size);

    int index = 4;
    double* partitionedArray = partitionInOrder(arr, size, &index);
    printArray(partitionedArray, size);

    double* mergedArrays = merge2Arrays(arr, size, arr, size);
    printArray(mergedArrays, 2*size);

    freeWrapper(arr);
    freeWrapper(reversedArray);
    freeWrapper(copiedArray);
    freeWrapper(partitionedArray);
    freeWrapper(mergedArrays);
    ensureMallocs();
    return 0;
}