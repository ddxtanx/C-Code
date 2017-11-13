#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"
#include "../helperLibs/arrayFuncs.h"
#include "../dataStructures/linkedList.h"
#include "../helperLibs/memoryManage.h"
#include "insertionSort.h"

double* quickSort(double arr[], int size){
    if(size<=3){
        return
    }
    int pivotIndex = rand() % size;
    double* partitioned = partitionInOrder(arr, size, pivotIndex);


}
double* partitionInOrder(double arr[], int size, int indexOfPivot){
    llNode* head = createLLNode(arr[indexOfPivot], NULL, NULL);
    int pivot = arr[indexOfPivot];
    for(int x = 0; x<size; x++){
        if(x != indexOfPivot){
            if(arr[x]<=pivot){
                head = prepend(head, arr[x]);
            } else{
                head = append(head, arr[x]);
            }
        }
    }
    double* returnedArray = arrayFromLL(head);
    freeLL(head);
    return returnedArray;
}