/*Write a menu driven program to implement Deques (both Input-restricted and Output-restricted) operations such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull using static array.*/
#include <stdio.h>
#define DEF_TERM printf("\033[0m\n")

#define LEN 5

int queue[LEN];
int front = -1,
    rear = -1;

int isEmpty(){
    return (front==-1) ? 1 : 0;
}

int isFull(){
    return (!isEmpty() && rear==LEN-1) ? 1 : 0;
}

void pushRear(int d){
    if(isEmpty()){
        front = rear = 0;
    }
    else if(rear==LEN-1){
        printf("\033[31mFull from Rear\n");
        DEF_TERM;
        return;
    }else{
        rear++;
    }
    queue[rear] = d;
}

void pushFront(int d){
    if(isEmpty() || front == 0){
        printf("\033[31mFull from front\n");
        DEF_TERM;
        return;
    }
    else
        front--;
    queue[front] = d;
}

int popFront(){
    int x;
    if(isEmpty())
        x = -999;
    else if(front==rear){
        x = queue[front];
        front = rear =  -1;
    }
    else
        x = queue[front++];

    return x;
}

int popRear(){
    int x;
    if(isEmpty())
        x = -999;
    else if(rear == front){
        x = queue[rear];
        front = rear =  -1;
    }
    else
        x = queue[rear--];

    return x;
}

int peek(){
    return (isEmpty()) ? -999 : queue[front];
}

void display(){
    if(isEmpty()){
        printf("\033[31mEmpty!\n");
        return;
    }
    printf("\033[33;44m{front} ");
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("{rear}");
    DEF_TERM;
}

int main(int argc, char const *argv[])
{
    int cont;
    do{
        printf("enter 1 -> display\n");
        printf("enter 2 -> pushRear\n");
        printf("enter 3 -> pushFront\n");
        printf("enter 4 -> popFront\n");
        printf("enter 5 -> popRear\n");
        printf("enter 6 -> isEmpty\n");
        printf("enter 7 -> Peek\n");
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
            pushRear(k);
            break;

            case 3:
            printf("Enter element to insert: ");
            scanf("%d",&k);
            pushFront(k);
            break;

            case 4:
            k = popFront();
            (k==-999) ? printf("\033[31mEmpty!\n") : printf("\033[33;44mpopped from front: %d",k);
            DEF_TERM;
            break;

            case 5:
            k = popRear();
            (k==-999) ? printf("\033[31mEmpty!\n") : printf("\033[33;44mpopped from rear: %d",k);
            DEF_TERM;
            break;

            case 6:
            (isEmpty()) ? printf("Empty!\n") : printf("Not empty");
            DEF_TERM;
            break;

            case 7:
            k = peek();
            (k==-999) ? printf("\033[31mEmpty!\n") : printf("\033[33;44mFront element: %d",k);
            DEF_TERM;
            break;
        }

    }while(cont);

    remove(argv[0]);
    return 0;
}
