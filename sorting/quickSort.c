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
    if(alreadySorted(arr, size)){
        return copyArray(arr, size);
    }
    int pivotIndex = (rand() % (size));
    double pivotValue = arr[pivotIndex];
    double leftSubArray[size];
    int currentLeftIndex = 0;
    double rightSubArray[size];
    int currentRightIndex = 0;
    for(int x = 0; x<size; x++){
        if(arr[x]<pivotValue){
            leftSubArray[currentLeftIndex] = arr[x];
            currentLeftIndex++;
        } else{
            rightSubArray[currentRightIndex] = arr[x];
            currentRightIndex++;
        }
    }
    double* leftSorted = quickSort(leftSubArray, currentLeftIndex);
    double* rightSorted = quickSort(rightSubArray, currentRightIndex);

    double* returnedArray = merge2Arrays(leftSorted, currentLeftIndex, rightSorted, currentRightIndex);

    freeWrapper(leftSorted);
    freeWrapper(rightSorted);
    return returnedArray;
}


