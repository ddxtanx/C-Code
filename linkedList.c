#include <stdio.h>
#include <float.h>
#include <time.h>
#include <math.h>
#include "memoryManage.c"
#include "arrayFuncs.c"
typedef struct llNode{
    struct llNode* previous;
    double value;
    struct llNode* next;
} llNode;


llNode* freeLL(llNode* head){
    llNode* cursor = head;
    while(cursor != NULL){
      llNode* cpy = cursor -> next;
      freeWrapper(cursor);
      cursor = cpy;
    }
    return head;
}

double* freeArray(double* arr){
    freeWrapper(arr);
    return arr;
}

llNode* createLLNode(double data, llNode* next, llNode* previous)
{
    llNode* new_llNode = (llNode*)mallocWrapper(sizeof(llNode));
    if(new_llNode == NULL)
    {
        printf("Error creating a new llNode.\n");
        exit(0);
    }
    new_llNode->value = data;
    new_llNode->next = next;
    new_llNode->previous = previous;

    return new_llNode;
}

llNode* createLLHead(){
  return createLLNode(NAN, NULL, NULL);
}

llNode* prepend(llNode* head, double value){
  llNode* newNode = createLLNode(value, head, NULL);
  head = newNode;
  return head;
}

llNode* appendToLL(llNode* head, double data)
{
    /* go to the last llNode */
    llNode *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;

    /* create a new llNode */
    llNode* new_llNode =  createLLNode(data,NULL, cursor);
    cursor->next = new_llNode;

    return head;
}
int countLL(llNode *head)
{
    llNode *cursor = head;
    int c = 0;
    while(cursor != NULL)
    {
        c++;
        cursor = cursor->next;
    }
    return c;
}
llNode* getLLElementByIndex(llNode* head, int index){
  int length = countLL(head);
  if(index<0 || index>=length){
    printf("Index must fall in linked list.\n");
    printf("\t You asked for element %d when there are only %d elements in the list.\n", index+1, length);
    return 0;
  }
  llNode* cursor = head;
  int counter = 0;
  while(counter != index){
    cursor = cursor -> next;
    counter++;
  }
  return cursor;
}

llNode* llInsertInAscendingOrder(llNode* head, double value){
  llNode* insertedNode = createLLNode(value, NULL, NULL);
  llNode* cursor = head;
  while((cursor -> next != NULL) && (cursor -> next -> value < value)){
    cursor = cursor -> next;
  }
  insertedNode -> next = cursor -> next;
  cursor -> next = insertedNode;

  return head;
}
void traverseLL(llNode* head, void (*cb)(llNode* llNode, int counter)){
  llNode* cursor = head;
  int counter = 0;
  while(cursor != NULL){
    cb(cursor, counter);
    cursor = cursor -> next;
    counter++;
  }
}

double* sortWithLL(double arr[], int size){
  double* returnedArray = mallocWrapper(sizeof(double)*size);
  llNode* head = createLLNode(-DBL_MAX, NULL, NULL);
  for(int x = 0; x<size; x++){
    head = llInsertInAscendingOrder(head, arr[x]);
  }
  llNode* cursor = head;
  int counter = 0;
  while(cursor -> next != NULL){
    cursor = cursor -> next;
    returnedArray[counter] = cursor -> value;
    counter++;
  }
  head = freeLL(head);
  return returnedArray;
}

void printLL(llNode* head){
    llNode* cursor = head;
    char* arrow;
    while(cursor != NULL){
        arrow = (cursor -> next != NULL)?"->":"";
        printf("%f%s", cursor -> value, arrow);
        cursor = cursor -> next;
    }
    printf("\n");
}


llNode* randomLinkedList(llNode* head, int size){
  llNode* cursor = head;
  for(int x = 0; x<size; x++){
    appendToLL(cursor, rand()%100);
  }
  return cursor;
}
llNode* initLinkedList(llNode* head, int size){
  llNode* cursor = head;
  for(int x = 0; x<size; x++){
    printf("Element %d = ", x);
    double val;
    scanf("%lf", &val);
    cursor = appendToLL(cursor, val);
  }

  return cursor;
}
llNode* removeLLNode(llNode* head, double value){
  llNode* cursor = head;

  while(cursor != NULL){
    if(cursor -> value == value){
      llNode* previous = cursor -> previous;
      llNode* next = cursor -> next;
      freeWrapper(cursor);
      previous -> next = next;
      if(next != NULL){
        next -> previous = previous;
      }
    }
    cursor = cursor -> next;
  }
  return head;
}
llNode* llFromArray(double arr[], int size){
  llNode* head = createLLNode(arr[0], NULL, NULL);
  for(int x = 1; x<size; x++){
    head = appendToLL(head, arr[x]);
  }

  return head;
}
double* arrayFromLL(llNode* head){
  int size = countLL(head);
  llNode* cursor = head;
  double* arr = (double*)(mallocWrapper(sizeof(double)*size));
  int counter = 0;
  if(cursor -> value == NAN && cursor -> next != NULL){
    cursor = cursor -> next;
  }
  while(cursor != NULL){
    arr[counter] = cursor -> value;
    cursor = cursor -> next;
    counter++;
  }

  return arr;
}
int main(){
  srand(time(NULL));
  llNode* head;
  int size;
  printf("Size? ");
  scanf("%d", &size);
  double* arr = initArray(size);
  printArray(arr, size);
  head = llFromArray(arr, size);
  printLL(head);
  double* arrCPY = arrayFromLL(head);
  double* arrSorted = sortWithLL(arrCPY, size);
  printArray(arrCPY, size);
  printArray(arrSorted, size);
  freeWrapper(arr);
  freeWrapper(arrCPY);
  freeWrapper(arrSorted);
  freeLL(head);
  ensureMallocs();
}
