/*Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull using static array.*/
#include <stdio.h>
#define SIZE 5

int cqueue[SIZE];
int front=-1,
    rear=-1;

int isEmpty(){
    return (front == -1 && rear == -1)?1:0;
}

int isFull(){
    return (front == rear)?1:0;
}

void push(int d){
    if(isEmpty()){
        front = rear = 0;
    }
    else if((rear+1)%SIZE != front){
        rear = (rear+1)%SIZE;
    }
    else{
        fprintf(stderr, "Already full!!\n");
        return;
    }
    cqueue[rear] = d;
}

int pop(){
    int x = -999;
    if(isFull() && !isEmpty()){
        //reset the
        x = cqueue[front];
        front = rear = -1; 
    }else if(isEmpty()){
        return x;
    }
    else{
        x = cqueue[front];
        front = (front+1)%SIZE;
    }
    return x;
}

int peek(){
    return (isEmpty()) ? -999 : cqueue[front];
}

void display(){
    if(isEmpty()){
        printf("Empty!\n");
        return;
    }
    int t = front;
    while(t!=rear){
        printf("(%d | [%d]) ",cqueue[t],t);
        t=(t+1)%SIZE;
    }
    printf("(%d | [%d]) \n",cqueue[rear],rear);
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
