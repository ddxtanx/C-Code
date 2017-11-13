#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../helperLibs/arrayFuncs.h"
#include "../helperLibs/memoryManage.h"
#include "../dataStructures/linkedList.h"

int main(){
  srand(time(NULL));
  llNode* head;
  int size;
  printf("Size? ");
  scanf("%d", &size);
  int maxNum;
  printf("Max Number? ");
  scanf("%d", &maxNum);
  double* arr = randomArray(size, maxNum);
  printArray(arr, size);
  head = llFromArray(arr, size);
  printLL(head);
  double* arrCPY = arrayFromLL(head);
  double* arrSorted = sortWithLL(arrCPY, size);
  double* decendingSort = reverseArray(arrSorted, size);
  printArray(arrCPY, size);
  printArray(arrSorted, size);
  printArray(decendingSort, size);
  freeWrapper(arr);
  freeWrapper(arrCPY);
  freeWrapper(arrSorted);
  freeWrapper(decendingSort);
  freeLL(head);
  ensureMallocs();
}