typedef struct node {
  int data;
  struct node* next;
}Stack;

void push(Stack* top, int ele) {
  Stack* temp = (Stack*)malloc(sizeof(Stack));
  temp->next = 0;
  temp->data = ele;
  if (!top) {
    top = temp;
  } else {
    temp->next = top;
    top = temp;
  }
}

int isEmpty(Stack* top){
  return top == NULL ? 1 : 0;
}

void pop(Stack* top){
  if(!top){
    printf("UnderFlow");
  } else {
    Stack *ff = top;
    top = top->next;
    free(ff);
  }
}

int peek(Stack* top){
  if(!top){
    return -999;
  }
  return top->data;
}