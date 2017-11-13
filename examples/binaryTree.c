#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../helperLibs/memoryManage.h"
#include "../helperLibs/arrayFuncs.h"
#include "../dataStructures/binaryTree.h"
int main(){
  srand(time(NULL));
  binaryTreeHead* head = createBinaryTreeHead(50);
  int size = 14;
  double* randArray = randomArray(size, head -> head -> value);
  head = appendToBinaryTreeFromArray(head, randArray, size);
  traverseBinaryTree(head, printBinaryTree);
  printf("%f\n", head -> head -> left -> value);
  freeBinaryTree(head);
  freeWrapper(randArray);
  freeWrapper(head);
  ensureMallocs();
}