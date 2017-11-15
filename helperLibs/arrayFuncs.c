#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayFuncs.h"
#include "memoryManage.h"
#include "../dataStructures/linkedList.h"
double* initArray(int size){
  double* arr = mallocWrapper(sizeof(double)*size);
  for(int x = 0; x<size; x++){
    printf("arr[%d] = ", x);
    scanf("%lf", &arr[x]);
  }

  return arr;
}

void printArray(double arr[], int size){
    printf("[");
    char comma;
    for(int x = 0; x<size; x++){
        comma = (x!=size-1)?',':']';
        printf("%f%c ", arr[x], comma);
    }
    printf("\n");
}

double* randomArray(int size, int maxNum){
  double* arr = mallocWrapper(sizeof(double)*size);
  for(int x = 0; x<size; x++){
    arr[x] = rand() % maxNum;
  }

  return arr;
}

double* reverseArray(double arr[], int size){
  double* reversedArr = (double*)mallocWrapper(sizeof(double)*size);

  if(reversedArr == NULL){
    printf("Error\n");
    exit(0);
  }
  int y = 0;
  for(int x = size - 1; x>=0; x--){
    reversedArr[y] = arr[x];
    y++;
  }

  return reversedArr;
}

double* copyArray(double arr[], int size){
  double* copiedArray = (double*)mallocWrapper(sizeof(double)*size);

  if(copiedArray == NULL){
    printf("Error\n");
    exit(0);
  }

  for(int x = 0; x<size; x++){
    copiedArray[x] = arr[x];
  }

  return copiedArray;
}

double* partitionInOrder(double arr[], int size, int indexOfPivot){
    llNode* head = createLLNode(arr[indexOfPivot], NULL, NULL);
    int pivot = arr[indexOfPivot];
    for(int x = 0; x<size; x++){
        if(x != indexOfPivot){
            if(arr[x]<pivot){
                head = prependToLL(head, arr[x]);
            } else{
                head = llInsertInAscendingOrder(head, arr[x]);
            }
        }
    }
    double* returnedArray = arrayFromLL(head);
    freeLL(head);
    return returnedArray;
}

double* merge2Arrays(double arr1[], int size1, double arr2[], int size2){
    double* returnedArray = (double*)mallocWrapper(sizeof(double)*(size1+size2));
    for(int x = 0; x<size1+size2; x++){
        returnedArray[x] = (x<size1)?arr1[x]:arr2[x-size1];
    }

    return returnedArray;
}

int sizeOfArray(double arr[]){
    return sizeof(arr)/sizeof(double);
}