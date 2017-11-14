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
    printf("Random Array1: \n");
    double* arr = randomArray(size, maxNum);
    printArray(arr, size);

    printf("Reversed Array: \n");
    double* reversedArray = reverseArray(arr, size);
    printArray(reversedArray, size);

    printf("Copied Array: \n");
    double* copiedArray = copyArray(arr, size);
    printArray(copiedArray, size);

    int index = 4;
    printf("Partitioned Array at %f: \n", arr[index]);
    double* partitionedArray = partitionInOrder(arr, size, &index);
    printArray(partitionedArray, size);

    printf("Random Array2: \n");
    double* secondRandomArray = randomArray(size, maxNum);
    printArray(secondRandomArray, size);

    printf("Random1 and Random2 merged: \n");
    double* mergedArrays = merge2Arrays(arr, size, secondRandomArray, size);
    printArray(mergedArrays, 2*size);

    freeWrapper(arr);
    freeWrapper(reversedArray);
    freeWrapper(copiedArray);
    freeWrapper(partitionedArray);
    freeWrapper(mergedArrays);
    freeWrapper(secondRandomArray);
    ensureMallocs();
    return 0;
}