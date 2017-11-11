#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

double* randomArray(int size){
  srand(time(NULL));
  double* arr = mallocWrapper(sizeof(double)*size);
  for(int x = 0; x<size; x++){
    srand(time(NULL));
    arr[x] = rand() % 500;
  }

  return arr;
}
