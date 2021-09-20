/*Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked list.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Queue;

Queue *front = NULL,
      *rear = NULL;

int isEmpty(){
    return (!front && !rear) ? 1 : 0;
}

void push(int d){
    Queue *t = (Queue*)malloc(sizeof(Queue));
    t->data=d;
    t->next = 0;

    if(isEmpty()){
        front = rear =t;
        return;
    }
    rear->next = t;
    rear = rear->next;
    return;
}

int pop(){
    int x = -999;

    if(isEmpty())
        return x;
    
    Queue *t=0;
    if(front == rear){
        x = front->data;
        t = front;
        front = rear = 0;
        free(t);
        t=0;
        return x;
    }

    x = front->data;
    t = front;
    front=front->next;
    free(t);
    t=0;
    return x;
}

int peek(){
    return (isEmpty()) ? -999 : front->data;
}

void display(){
    if(isEmpty()){
        printf("Empty!\n");
        return;
    }
    Queue *t = front;
    printf("|front| ");
    do{
        printf("%d ",t->data);
        t=t->next;
    }while(t && printf("->"));
    printf(" |rear|\n");
}

int main(int argc, char const *argv[])
{
    int ch;
    do{
        printf("Enter 1 -> display\n");
        printf("Enter 2 -> push\n");
        printf("Enter 3 -> pop\n");
        printf("Enter 4 -> peek\n");
        printf("Enter 5 -> isEmpty\n");
        printf("Enter 0 -> exit\n");
        printf("-> ");
        scanf("%d",&ch);
        int k;
        switch(ch){
            case 1:display();break;

            case 2:
            printf("Enter element to insert: ");
            scanf("%d",&k);
            push(k);
            break;

            case 3:
            k=pop();
            (k == -999)?printf("Empty!\n"):printf("popped: %d\n",k);
            break;

            case 4:
            k=peek();
            (k == -999)?printf("Empty!\n"):printf("front element: %d\n",k);
            break;

            case 5:
            (isEmpty())?printf("Empty!\n"):printf("not empty\n");
            break;

        }
    }while(ch);
    remove(argv[0]);
    return 0;
}
