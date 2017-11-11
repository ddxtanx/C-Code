#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayFuncs.h"
#include "memoryManage.h"
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