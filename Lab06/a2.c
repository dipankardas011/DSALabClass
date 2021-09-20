/*Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull using static array.*/
#include <stdio.h>
#include <stdlib.h>
#define LEN 20
int queue[LEN];
int front = -1, 
    rear = -1;


int isEmpty(){
    return (front==-1 && rear==-1) ? 1 : 0;
}

int isFull(){
    return (rear==LEN-1) ? 1 : 0;
}

void push(int d){
    if(isEmpty()){
        front=rear=0;
    }
    else if(!isFull()){
        rear++;
    }
    queue[rear] = d;
}

int pop(){
    int x = -999;
    if(isEmpty()){
        return x;
    }
    else if(front==rear){
        x = queue[front];
        front = rear = -1;
    }
    else{
        x = queue[front++];
    }
    return x;
}

int peek(){
    return (isEmpty()) ? -999 : queue[front];
}

void display(){
    if(isEmpty()){
        printf("Empty!\n");
        return;
    }
    printf("|front| ");
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);

    printf("|rear|\n");
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
        printf("Enter 6 -> isFull\n");
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

            case 6:
            (isFull())?printf("Full!\n"):printf("not full\n");
            break;
        }
    }while(ch);
    remove(argv[0]);
    return 0;
}
