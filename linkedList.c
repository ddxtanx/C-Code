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
int main(){
  node* head = create(-DBL_MAX, NULL);
  head = append(head, 5);
  printf("%f\n", head -> next -> value);
  head = insertInAscendingOrder(head, 3);
  printf("%f\n", head -> next -> value);
  head = insertInAscendingOrder(head, 2);
  printf("%f\n", head -> next -> value);
  head = insertInAscendingOrder(head, 7);
  printf("%f\n", head -> next -> value);
  traverseList(head, print);
}
