/*Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty using linked list.*/
#include <stdio.h>
#include <stdlib.h>
#define DEF_TERM printf("\033[0m\n")

typedef struct node{
    int data;
    struct node *next;
}Queue;

Queue *front=0,
      *rear = 0;

int isEmpty(){
    return (!front) ? 1 : 0;
}

void Enqueue(int data){
    Queue *t = (Queue*)malloc(sizeof(Queue));
    t->data = data;
    t->next = 0;

    if(isEmpty()){
        front = rear = t;
        front->next = front;
        return ;
    }

    rear->next = t;
    rear = rear->next;
    rear->next = front;

    return;
}

int Dequeue(){
    if(isEmpty()){
        return -999;
    }
    int x;
    Queue *ff = 0;
    if(front == rear){
        // last element
        ff = front;
        x = ff->data;
        front = rear = 0;
        free(ff);
        return x;
    }

    ff = front;
    front = front->next;
    rear->next = front;
    x = ff->data;
    free(ff);
    return x;

}

int peek(){
    return (isEmpty()) ? -999 : front->data;
}

void display(){
    if(isEmpty()){
        printf("\033[31mEmpty!\n");
        DEF_TERM;
        return;
    }
    Queue *t = front;
    printf("\033[33;44m{front} (");
    do{
        printf("%d",t->data);
        t=t->next;
    }while(t!=front && printf("->"));
    printf(") {rear}");
    DEF_TERM;
}

int main(int argc, char const *argv[])
{
    int cont;
    do{
        printf("enter 1 -> display\n");
        printf("enter 2 -> enqueue\n");
        printf("enter 3 -> dequeue\n");
        printf("enter 4 -> isEmpty\n");
        printf("enter 5 -> Peek\n");
        printf("enter 0 -> EXIT\n");
        printf("-> ");
        scanf("%d",&cont);
        int k;

        switch(cont){
            case 1: display();
            DEF_TERM;
            break;

            case 2:
            printf("Enter element to insert: ");
            scanf("%d",&k);
            Enqueue(k);
            break;

            case 3:
            k = Dequeue();
            (k==-999) ? printf("\033[31mEmpty!\n") : printf("\033[33;44mpopped from front: %d",k);
            DEF_TERM;
            break;

            case 4:
            (isEmpty()) ? printf("Empty!\n") : printf("Not empty");
            DEF_TERM;
            break;

            case 5:
            k = peek();
            (k==-999) ? printf("\033[31mEmpty!\n") : printf("\033[33;44mFront element: %d",k);
            DEF_TERM;
            break;
        }

    }while(cont);
    remove(argv[0]);
    return 0;
}
