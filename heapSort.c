#include <stdio.h>
#define null 0
typedef struct node{
  int value;
  struct node* leftChild;
  struct node* rightChild;
} node;
int main(int argv, char** argc){
  struct node parent, child1, child2;
  parent.value = 5;
  child1.value = 1;
  child1.children[0] = 0;
  child2.value = 5;
  child2.children[0] = 0;
  parent.children[0] = &child1;
  parent.children[1] = &child2;

}
