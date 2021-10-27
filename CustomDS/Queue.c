#include "../CustomDS/Queue.h"

bool isEmpty() {
  return (!front && !rear)? true : false;
}

queue *createMemo(int key) {
  queue *tmp = (queue *)malloc(sizeof(queue));
  if (!tmp)
  {
    fprintf(stderr, "Error HEAP memory allocation error!!\n");
    return NULL;
  }
  tmp->data = key;
  tmp->next = NULL;
  
  return tmp;
}

int peek () {
  if (isEmpty())
    return INV;

  return front->data;
}

void push(int key) {
  if (isEmpty()) {
    front = rear = createMemo(key);
    return;
  }

  rear->next = createMemo(key);
  rear = rear->next;
}

int pop() {
  if (isEmpty()) {
    return;
  }
  if (front == rear) {
    // last element
    rear = NULL;
    free(front);
    front = NULL;
    return ;
  }

  queue *t = front;
  front = front->next;
  free(t);
  return;
}

void display() {
  if(isEmpty()){
    printf("[]\n");
  } else {
    queue *iter = front;
    printf("[");
    do {
      printf("%d",iter->data);
      iter=iter->next;
    }while (iter!=NULL && printf(", "));
    printf("]\n");
  }
}