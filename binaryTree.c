#include <stdio.h>
#include <stdlib.h>
#include "memoryManage.c"
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
    node -> children = 0;

    return node;
}

int main(){

}