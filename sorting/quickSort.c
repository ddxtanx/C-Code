#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"
#include "../helperLibs/arrayFuncs.h"
#include "../dataStructures/linkedList.h"
#include "../helperLibs/memoryManage.h"
#include "insertionSort.h"

double* quickSort(double arr[], int size){
    if(size<=3){
        return insertionSort(arr, size);
    }
    int pivotIndex = (rand() % (size-1))+1; //Ensure that pivotIndex is never 0
    double pivotValue = arr[pivotIndex];
    double* partitioned = partitionInOrder(arr, size, pivotIndex);
    for(int x = 0; x<size; x++){
        if(partitioned[x]==pivotValue){
            pivotIndex = x;
        }
    }
    int leftSize = pivotIndex-1;
    double leftSubArray[leftSize];
    for(int x = 0; x<leftSize; x++){
        leftSubArray[x] = partitioned[x];
    }

    int rightSize = size-leftSize;
    double rightSubArray[rightSize];
    for(int x = 0; x<rightSize; x++){
        rightSubArray[x] = partitioned[x+pivotIndex];
    }
    printf("Whole array partitioned at %f: \n", pivotValue);
    printArray(partitioned, size);
    printf("Left subArray: \n");
    printArray(leftSubArray, leftSize);
    printf("Right subArray: \n");
    printArray(rightSubArray, rightSize);
    freeWrapper(partitioned);
    double* leftSorted = quickSort(leftSubArray, leftSize);
    double* rightSorted = quickSort(rightSubArray, rightSize);

    double* returnedArray = merge2Arrays(leftSorted, leftSize, rightSorted, rightSize);
    freeWrapper(leftSorted);
    freeWrapper(rightSorted);

    return returnedArray;
}


