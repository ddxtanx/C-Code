typedef struct llNode{
    struct llNode* previous;
    double value;
    struct llNode* next;
} llNode;

llNode* freeLL(llNode* head);

llNode* createLLNode(double data, llNode* next, llNode* previous);

llNode* createLLHead();

llNode* prependToLL(llNode* head, double value);

llNode* appendToLL(llNode* head, double data);

int countLL(llNode *head);

llNode* getLLElementByIndex(llNode* head, int index);

llNode* llInsertInAscendingOrder(llNode* head, double value);

void traverseLL(llNode* head, void (*cb)(llNode* llNode, int counter));

double* sortWithLL(double arr[], int size);

void printLL(llNode* head);

llNode* randomLinkedList(llNode* head, int size);

llNode* initLinkedList(llNode* head, int size);

llNode* removeLLNode(llNode* head, double value);

llNode* llFromArray(double arr[], int size);

double* arrayFromLL(llNode* head);