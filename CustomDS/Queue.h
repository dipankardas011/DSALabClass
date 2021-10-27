#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INV -999;

// linklist implementation
typedef struct {
  int data;
  queue *next;
}queue;

queue *front = NULL;
queue *rear = NULL;

bool isEmpty();

queue *createMemo(int key);

int peek();

void pop();

void push(int key);

void display();

