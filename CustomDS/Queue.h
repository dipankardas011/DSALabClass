#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INV -999;

// linklist implementation
typedef struct {
  void *data;
  queue *next;
}queue;

queue *front = NULL;
queue *rear = NULL;

bool isEmpty();

queue *createMemo(void *);

void* peek();

void pop();

void push(void* );

void display();

