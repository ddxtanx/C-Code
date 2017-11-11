#include <stdio.h>
#include <stdlib.h>
#include "memoryManage.h"
#define mallocs mallocs
int mallocs = 0;

void* mallocWrapper(int size){
  mallocs++;
  return malloc(size);
}

void freeWrapper(void* memory){
  mallocs--;
  free(memory);
}

void ensureMallocs(){
  printf("Mallocs not free'd %d\n", mallocs);
}
