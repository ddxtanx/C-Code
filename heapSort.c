#include <stdio.h>
#include "memoryManage.h"
typedef struct heapNode{
  double value;
  struct heapNode* leftChild;
  struct heapNode* rightChild;
} heapNode;
heapNode* create(double value, heapNode* leftChild, heapNode* rightChild){
    heapNode* node = (heapNode*)mallocWrapper(sizeof(heapNode));
    if(node == NULL){
        printf("ERROR\n");
        return 0;
    }

    node -> value = value;
    node -> leftChild = leftChild;
    node -> rightChild = rightChild;

    return node;
}

int main(int argv, char** argc){

}
