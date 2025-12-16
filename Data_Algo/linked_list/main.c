#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// int data , struct node* next
typedef struct node {
    int data;
    struct node *next;
} Node;

// Wrapper for node --> for implementing method
typedef struct linkedList {
    struct node *head;    // start Node of list
    struct node *current; // Current Node
    struct node *tail;    // End Node of list
} LinkedList;

//
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// return a Struct with tail , current and head node
LinkedList *initLinkedList() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->tail = NULL;
  list->current = NULL;
  list->head = NULL;
  return list;
}

// Insert Element after the Current Node
bool insertNode(LinkedList *list, int data) {
  Node *node = createNode(data);
  if (node == NULL || list == NULL || list->current == NULL)
    return false;

  node->next = list->current->next;
  list->current->next = node;

  if (list->current == list->tail) {
    list->tail = node;
  }
  return true;
}

// insert Element in the end of the list
bool pushElement(LinkedList *list, int data) {
  Node *node = createNode(data);
  if (list == NULL)
    return false;
  if (node == NULL)
    return false;
  if (list->tail == NULL) {
    list->tail = node;
    list->head = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  return true;
}

// Delete last node and return its Data
int popElement(LinkedList *list) {
  int data = list->tail->data;
  if (list->head != NULL) {
    free(list->tail);
  }
  return data;
}

// if element found --> safe pointer in Current
bool searchElement(LinkedList *list) { return true; }

void freeLinkedList(LinkedList **list) {
  struct node *ptrTmp;
  while ((*list)->head != NULL) {
    ptrTmp = (*list)->head;
    (*list)->head = (*list)->head->next;
    free(ptrTmp);
  }
  free(*list);
}

int main() { return 0; }
