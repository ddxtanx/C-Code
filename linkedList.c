#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>
typedef struct node{
    struct node* previous;
    double value;
    struct node* next;
} node;
int mallocs = 0;

void* mallocWrapper(int size){
  mallocs++;
  return malloc(size);
}

void freeWrapper(void* malloced){
  mallocs--;
  free(malloced);
}

void ensureMallocs(){
  printf("Amount of mallocs not freed - %d\n", mallocs);
}

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
void print(node* node){
  printf("Value is %f\n", node -> value);
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
void traverseList(node* head, void (*cb)(node* node)){
  node* cursor = head;
  if(cursor -> next != NULL){
    cursor = cursor -> next;
    while(cursor != NULL){
      cb(cursor);
      cursor = cursor -> next;
    }
  }
}

double* sortWithLL(double arr[], int size){
  printf("Sorting...\n");
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
    for(int x = 0; x<size; x++){
        printf("arr[%d] is %f\n", x, arr[x]);
    }
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
      cursor -> previous -> next = cursor -> next;
      cursor -> next -> previous = cursor -> previous;
    }
    cursor = cursor -> next;
  }
  return head;
}
int main(){
  srand(time(NULL));
  node* head = create(-DBL_MAX, NULL, NULL);
  int size;
  printf("Size? ");
  scanf("%d", &size);
  head = initLinkedList(head, size);
  printf("Removing %f\n", getElementByIndex(head, 3) -> value);
  head = removeNode(head, getElementByIndex(head, 3) -> value);

  traverseList(head, print);
  freeLL(head);
  ensureMallocs();
}
