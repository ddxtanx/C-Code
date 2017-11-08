#include <stdio.h>
#include <stdlib.h>
#include <float.h>

typedef struct node{
    double value;
    struct node* next;
} node;
void print(node* node){
  printf("Value is %f\n", node -> value);
}
node* create(double data,node* next)
{
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->value = data;
    new_node->next = next;

    return new_node;
}

node* prepend(node* head, double value){
  node* newNode = create(value, head);
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
    node* new_node =  create(data,NULL);
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
  node* insertedNode = create(value, NULL);
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
  cursor = cursor -> next;
  while(cursor != NULL){
    cb(cursor);
    cursor = cursor -> next;
  }
}

double* sortWithLL(double arr[], int size){
  printf("Sorting...\n");
  double* returnedArray = malloc(sizeof(double)*size);
  node* head = create(-DBL_MAX, NULL);
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

  return returnedArray;
}
double* initArray(int size){
  double* arr = malloc(sizeof(double)*size);
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
    double* arr = malloc(sizeof(double)*size);
}

node* freeLL(node* head){
    int counter = count(head);
    for(int x = counter-1; x>=0; x--){
        free(getElementByIndex(head, x));
    }
    return head;
}

double* freeArray(double* arr){
    free(arr);
    return arr;
}
int main(){
  node* head = create(-DBL_MAX, NULL);
  printf("Size? ");
  int size;
  scanf("%d", &size);
  double* arr = initArray(size);
  printArray(arr, size);
  arr = sortWithLL(arr, size);
  printArray(arr, size);
  head = freeLL(head);
  arr = free(arr);
}
