/*WAP Write a menu driven program to perform the following operations of a stack using linked list by using suitable user defined functions for each case.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}stack;

stack *top=NULL;

int isEmpty(){
    if(!top){
        return 1;
    }
    return 0;
}

void push(int d){
    stack *new = (stack*)malloc(sizeof(stack));
    new->data = d;
    new->next=0;
    if(isEmpty()){
        top = new;
        return;
    }

    new->next = top;
    top = new;
    return ;
}

int pop(){
    int x=-999;
    if(isEmpty()){
        return x;
    }
    x = top->data;
    stack *ff = top;
    top = top->next;
    free(ff);
    return x;
}

void display(){
    if(!top){
        fprintf(stderr, "Empty!\n");
        return;
    }
    stack *t= top;

    while(t){
        printf("|%3d|\n",t->data);
        t=t->next;
    }
    printf("+---+\n");
}

int main(int argc, char const *argv[])
{
    int ch;
    do{
        printf("Enter 1 -> isEmpty\n");
        printf("Enter 2 -> display\n");
        printf("Enter 3 -> push\n");
        printf("Enter 4 -> pop\n");
        printf("Enter 5 -> exit\n");
        printf("-> ");
        scanf("%d",&ch);
        int k=0;
        switch(ch){
            case 1: (isEmpty())?printf("Empty!\n"):printf("Not Empty!\n");
            break;

            case 2:
            display();
            break;

            case 3:
            printf("Enter element to insert: ");
            scanf("%d",&k);
            push(k);
            break;

            case 4:
            k = pop();
            (k!=-999)?printf("Popped: %d\n",k) : printf("Already Empty!\n");
        }
    }while(ch!=5);
    remove(argv[0]);
    return 0;
}
