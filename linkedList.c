#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
#include <math.h>
#include "memoryManage.c"
typedef struct node{
    struct node* previous;
    double value;
    struct node* next;
} node;


node* freeLL(node* head){
    node* cursor = head;
    while(cursor != NULL){
      node* cpy = cursor -> next;
      freeWrapper(cursor);
      cursor = cpy;
    }
    return head;
}

double* freeArray(double* arr){
    freeWrapper(arr);
    return arr;
}
void print(node* node, int counter){
  printf("Element %d of the LL is %f\n",counter, node -> value);
}
node* create(double data, node* next, node* previous)
{
    node* new_node = (node*)mallocWrapper(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->value = data;
    new_node->next = next;
    new_node->previous = previous;

    return new_node;
}

node* createHead(){
  return create(NAN, NULL, NULL);
}

node* prepend(node* head, double value){
  node* newNode = create(value, head, NULL);
  head = newNode;
  return head;
}

node* append(node* head, double data)
{
    /* go to the last node */
    node *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;

    /* create a new node */
    node* new_node =  create(data,NULL, cursor);
    cursor->next = new_node;

    return head;
}
int count(node *head)
{
    node *cursor = head;
    int c = 0;
    while(cursor != NULL)
    {
        c++;
        cursor = cursor->next;
    }
    return c;
}
node* getElementByIndex(node* head, int index){
  int length = count(head);
  if(index<0 || index>=length){
    printf("Index must fall in linked list.\n");
    printf("\t You asked for element %d when there are only %d elements in the list.\n", index+1, length);
    return 0;
  }
  node* cursor = head;
  int counter = 0;
  while(counter != index){
    cursor = cursor -> next;
    counter++;
  }
  return cursor;
}

node* insertInAscendingOrder(node* head, double value){
  node* insertedNode = create(value, NULL, NULL);
  node* cursor = head;
  while((cursor -> next != NULL) && (cursor -> next -> value < value)){
    cursor = cursor -> next;
  }
  insertedNode -> next = cursor -> next;
  cursor -> next = insertedNode;

  return head;
}
void traverseList(node* head, void (*cb)(node* node, int counter)){
  node* cursor = head;
  int counter = 0;
  while(cursor != NULL){
    cb(cursor, counter);
    cursor = cursor -> next;
    counter++;
  }
}

double* sortWithLL(double arr[], int size){
  double* returnedArray = mallocWrapper(sizeof(double)*size);
  node* head = create(-DBL_MAX, NULL, NULL);
  for(int x = 0; x<size; x++){
    head = insertInAscendingOrder(head, arr[x]);
  }
  node* cursor = head;
  int counter = 0;
  while(cursor -> next != NULL){
    cursor = cursor -> next;
    returnedArray[counter] = cursor -> value;
    counter++;
  }
  head = freeLL(head);
  return returnedArray;
}
double* initArray(int size){
  double* arr = mallocWrapper(sizeof(double)*size);
  for(int x = 0; x<size; x++){
    printf("arr[%d] = ", x);
    scanf("%lf", &arr[x]);
  }

  return arr;
}

void printArray(double arr[], int size){
    printf("[");
    char comma;
    for(int x = 0; x<size; x++){
        comma = (x!=size-1)?',':']';
        printf("%f%c ", arr[x], comma);
    }
    printf("\n");
}
void printLL(node* head){
    node* cursor = head;
    char* arrow;
    while(cursor != NULL){
        arrow = (cursor -> next != NULL)?"->":"";
        printf("%f%s", cursor -> value, arrow);
        cursor = cursor -> next;
    }
    printf("\n");
}
double* randomArray(int size){
  double* arr = mallocWrapper(sizeof(double)*size);
  for(int x = 0; x<size; x++){
    arr[x] = rand() % 500;
  }

  return arr;
}

node* randomLinkedList(node* head, int size){
  node* cursor = head;
  for(int x = 0; x<size; x++){
    append(cursor, rand()%100);
  }
  return cursor;
}
node* initLinkedList(node* head, int size){
  node* cursor = head;
  for(int x = 0; x<size; x++){
    printf("Element %d = ", x);
    double val;
    scanf("%lf", &val);
    cursor = append(cursor, val);
  }

  return cursor;
}
node* removeNode(node* head, double value){
  node* cursor = head;

  while(cursor != NULL){
    if(cursor -> value == value){
      node* previous = cursor -> previous;
      node* next = cursor -> next;
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
node* llFromArray(double arr[], int size){
  node* head = create(arr[0], NULL, NULL);
  for(int x = 1; x<size; x++){
    head = append(head, arr[x]);
  }

  return head;
}
double* arrayFromLL(node* head){
  int size = count(head);
  node* cursor = head;
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
  node* head;
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
