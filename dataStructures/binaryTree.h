int globalLayer;

typedef struct binaryTreeNode{
    double value;
    struct binaryTreeNode* left;
    struct binaryTreeNode* right;
} binaryTreeNode;

binaryTreeNode** nodeArray;

typedef struct binaryTreeHead{
    binaryTreeNode* head;
    int children;
} binaryTreeHead;

binaryTreeNode* createBinaryTreeNode(double value, binaryTreeNode* left, binaryTreeNode* right);

binaryTreeHead* createBinaryTreeHead(double value);

binaryTreeHead* appendToBinaryTree(binaryTreeHead* head, double value);

binaryTreeHead* appendToBinaryTreeFromArray(binaryTreeHead* head, double value[], int size);

void traverseBinaryTree(binaryTreeHead* head, void cb(binaryTreeNode* node, int layer, int counter));

void printBinaryTree(binaryTreeNode* node, int layer, int counter);

void arrayOfBinaryTreeNodes(binaryTreeNode* node, int layer, int counter);

void freeBinaryTree(binaryTreeHead* head);