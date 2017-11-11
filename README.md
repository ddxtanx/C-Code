# C-Code

Hello! This is a collection of C code that I've written to learn about various aspects of comp sci and coding. 


I have a bunch of files in here, so I might as well explain my thoughts while coding them, and their purpose

## ArrayFuncs.c/h

* initArray

    * This takes in a size of an array, and prompts the user to fill
    the array with doubles
* printArray

    * This takes in an array and it's size and prints out all the elements in the array in this fashion

        [e1, e2, e3, e4 ... eN]
* randomArray

    * This takes an integer size and a maximum number and returns an array filled with random integers that satisfies 0≤N<maxNum

## binaryTree.c

* binaryTreeNode

    * A struct that represents a node in a binary tree, it has a value, a left child, and a right child

* binaryTreeHead

    * A struct that represents the head of a binary tree, it has a node that represents the head node, and a count of how many children it has

*  createBinaryTreeNode

    * This takes in a value, a left child, and a right child, and returns a pointer to a binary tree node with the given properties

* createBinaryTreeHead

    * Just like createBinaryTreeNode, but for binary tree heads

