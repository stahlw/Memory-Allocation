//Wesley Stahl
//7/31/2017
//TCSS 333 Assignment 6
//Time Spent: About 2hrs 30mins
//Backend code for allocating a certain amount of memory for use by client code

#include "mallok.h"

typedef struct node {
  int size;
  void *start;
  int num;
  struct node *next;
} Node;

static Node *myNode;

/***** Initializes the available memory space in the pool *****/
void create_pool(int size) {
  myNode = malloc(sizeof(Node));
  myNode->size = size;
  myNode->num = 0;
  myNode->start = malloc(size);
  myNode->next = NULL;
}

/***** Sets different blocks of memory aside for use by the client code *****/
void *my_malloc(int size) {
  Node *curr = myNode;
  int isOk = 0;
  while (curr != NULL) {
    if (curr->num == 0 && size <= curr->size) {
      Node *tempNode = malloc(sizeof(Node));
      tempNode->size = curr->size - size;
      curr->size = size;
      curr->num = 1;
      tempNode->num = 0;
      tempNode->next = curr->next;
      curr->next = tempNode;
      tempNode->start = curr->start + size;
      isOk = 1;
      if (tempNode->size == 0) {
        curr->next = NULL;
      }
      return curr->start;
    }
    curr = curr->next;
  }
  if (!isOk) {
    return 0;
  }
}

/***** Frees specific memory blocks in the pool of memory *****/
void my_free(void *nodeBlock) {
  Node *curr = myNode;
  while (curr != NULL) {
    if (curr->start == nodeBlock) {
      curr->num = 0;
    }
    curr = curr->next;
  }
  Node *curr2 = myNode;
  while (curr2 != NULL) {
    if (curr2->next != NULL && curr2->num == 0 && curr2->next->num == 0) {
      Node *tempNode = curr2->next;
      curr2->size += curr2->next->size;
      curr2->next = curr2->next->next;
      free(tempNode);
    }
    curr2 = curr2->next;
  }
}      
      