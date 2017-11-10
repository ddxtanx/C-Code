#include <stdio.h>
#include "memoryManage.c"
typedef struct node{
  double value;
  struct node* leftChild;
  struct node* rightChild;
} node;
node* create(double value, node* leftChild, node* rightChild){
    node* node = (node*)mallocWrapper(sizeof(node));
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
