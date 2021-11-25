typedef struct node {
  int arr[10000];
  int front, rear;
} Queue;

int isEmpty(Queue* top){
  return (top->front == -1) ? 1 : 0;
}
void push(Queue* q, int ele) {
  if(isEmpty(q)){
    (q->front)++;
    (q->rear)++;
  } else {
    (q->rear)++;
  }
  q->arr[q->rear] = ele;
}

void pop(Queue* top){
  if(isEmpty(top)){
    printf("UnderFlow");
  }
  else if(top->front == top->rear){
    top->front = top->rear = -1;
  }
  else {
    (top->front)++;
  }
}

int peek(Queue* top){
  if(!top){
    return -999;
  }
  return top->arr[top->front];
}