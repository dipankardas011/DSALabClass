typedef struct node {
  void* data;
  struct node* next;
}Stack;

void push(Stack** top, void* ele) {
  Stack* temp = (Stack*)malloc(sizeof(Stack));
  temp->next = 0;
  temp->data = ele;
  if (!(*top)) {
    (*top) = temp;
  } else {
    temp->next = (*top);
    (*top) = temp;
  }
}

int isEmpty(Stack** top){
  return *top == NULL ? 1 : 0;
}

void pop(Stack** top){
  if(!(*top)){
    printf("UnderFlow");
  } else {
    Stack *ff = *top;
    (*top) = (*top)->next;
    free(ff);
  }
}

void* peek(Stack** top){
  if(!(*top)){
    return NULL;
  }
  return (*top)->data;
}