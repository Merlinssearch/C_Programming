#include <stdio.h>
#include <stdlib.h>
// linked list struct
// typdef struct node damit der compilere versteht das sich dieser struct selbst
// aufruft sonst fehler
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void freeLinkedList(struct node *head) {
  struct node *tmp;
  while (head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

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
  freeLinkedList(first);
  return 0;
}
