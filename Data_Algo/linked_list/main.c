#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// linked list struct
// typdef struct node damit der compilere versteht das sich dieser struct selbst
// aufruft sonst fehler

// Node with Int Data and Pointer to next node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Wrapper for node --> for implementing method
typedef struct LinkedList {
    struct node *head;    // start Node of list
    struct node *current; // Current Node
    struct node *tail;    // End Node of list
} linkedList;

//
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// return a Struct with tail , current and head node
linkedList *initLinkedList() {
  linkedList *list = (linkedList *)malloc(sizeof(linkedList));
  list->tail = NULL;
  list->current = NULL;
  list->head = NULL;
  return list;
}

// Insert Element on the Current Node
void insertNode(linkedList *list, int data) {
  Node *temp = list->current->next;
}

// insert Element in the end of the list
void pushElement(linkedList *list, int data) {}

// Delete last node in Liste
void popElement(linkedList *list) {}

// if element found --> safe pointer in Current
void searchElement(linkedList *list) {}

void freeLinkedList(linkedList **list) {
  struct node *tmp = list->* head;
  while (list->head != NULL) {
    tmp = list->head;
    list->head = (list->head)->next;
    free(tmp);
  }
  free(list);
}

//
// void freeLinkedList(struct node **head) {
//   struct node *tmp;
//   while (*head != NULL) {
//     tmp = *head;
//     *head = (*head)->next;
//     free(tmp);
//   }
// }

int main() {
  Node *first = createNode(0);

  Node *temp = first;
  for (int i = 1; i < 10; i++) {
    temp->next = createNode(i);
    temp = temp->next;
  }
  temp = first;
  while (temp) {
    printf("%d \n", temp->data);
    temp = temp->next;
  }
  freeLinkedList(&first);
  return 0;
}
