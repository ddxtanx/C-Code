#include <stdio.h>
#include <math.h>
#include "memoryManage.c"
#include "arrayFuncs.c"
#include "dectobinary.c"
typedef struct binaryTreeNode{
    double value;
    struct binaryTreeNode* left;
    struct binaryTreeNode* right;
} binaryTreeNode;
typedef struct binaryTreeHead{
    binaryTreeNode* head;
    int children;
} binaryTreeHead;

binaryTreeNode* createBinaryTreeNode(double value, binaryTreeNode* left, binaryTreeNode* right){
    binaryTreeNode* node = (binaryTreeNode*)mallocWrapper(sizeof(binaryTreeNode));

    if(node == NULL){
        printf("Memory Error\n");
        return 0;
    }

    node -> value = value;
    node -> left = left;
    node -> right = right;

    return node;
}

binaryTreeHead* createBinaryTreeHead(double value){
    binaryTreeHead* node = (binaryTreeHead*)mallocWrapper(sizeof(binaryTreeHead));

    if(node == NULL){
        printf("Memory Error\n");
        return 0;
    }

    node -> head = createBinaryTreeNode(value, NULL, NULL);
    node -> children = 1; //Node is considered child of itself, works out with math

    return node;
}
binaryTreeHead* appendToBinaryTree(binaryTreeHead* head, double value){
  binaryTreeNode* appended = createBinaryTreeNode(value, NULL, NULL);
  binaryTreeNode* headNode = head -> head;
  binaryTreeNode* cursor = headNode;
  int count = head -> children;
  int layers = floor(log2(count+1));
  while(cursor -> left != NULL && cursor -> right != NULL){
    int powerAverage = (pow(2, layers-1) + pow(2, layers)); //simplified down from (pow(2, layers) - pow(2, layers+1))/2
    if(count < powerAverage-1){ //If empty space is on left side of tree
      cursor = cursor -> left;
      count -= (int)pow(2, layers-1);
    } else{ // If empty space is on right side of tree
      cursor = cursor -> right;
      count -= (int)pow(2, layers);
    }
    layers--;
  }
  if(cursor -> left == NULL){
    cursor -> left = appended;
  } else{
    cursor -> right = appended;
  }
  head -> head = headNode;
  head -> children = head -> children + 1;
  return head;
}
binaryTreeHead* appendToBinaryTreeFromArray(binaryTreeHead* head, double value[], int size){
  for(int x = 0; x<size; x++){
    head = appendToBinaryTree(head, value[x]);
  }

  return head;
}

void printBinaryTree(binaryTreeHead* head){
  binaryTreeNode* headNode = head -> head;
  int children = head -> children;

  printf("%f\n", headNode -> value);

  binaryTreeNode* cursor = headNode;
  long long unsigned counter = 2;
  int layers = floor(log2(counter));
  char* binaryRep = decToBinary(counter);
  while(counter < children){
    if(floor(log2(counter)) > layers){
      printf("\n");//Denotes new layer of binary tree
    }
    freeWrapper(binaryRep);
    binaryRep = decToBinary(counter);
    layers = floor(log2(counter));
    cursor = headNode;
    int size = powDetermine(counter);
    for(int x = 1; x<size; x++){
      if(binaryRep[x]=='0'){
        cursor = cursor -> left;
      } else{
        cursor = cursor -> right;
      }
    }
    printf("%f,", cursor -> value);
    counter++;
  }
}
int main(){
  srand(time(NULL));
  binaryTreeHead* head = createBinaryTreeHead(rand()%60);
  int size = 14;
  double* randArray = randomArray(size);
  head = appendToBinaryTreeFromArray(head, randArray, size);
  printBinaryTree(head);
  printf("%f\n", head -> head -> left -> value);
}
