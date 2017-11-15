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
    int foundX = 0; //Going to represent a boolean in the next loop
    int leftPivotIndex;
    int rightPivotIndex;
    for(int x = 0; x<size; x++){
        if(partitioned[x]==pivotValue && foundX == 0){
            foundX = 1;
            leftPivotIndex = x;
        }
        if(foundX == 1 && partitioned[x]!=pivotValue){
            rightPivotIndex = x-1;
            break;
        }
    }
    int leftSize = leftPivotIndex;
    double leftSubArray[leftSize];
    for(int x = 0; x<leftSize; x++){
        leftSubArray[x] = partitioned[x];
    }

    int rightSize = size-leftSize;
    double rightSubArray[rightSize];
    for(int x = 0; x<rightSize; x++){
        rightSubArray[x] = partitioned[x+(rightPivotIndex-1)];
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


