/*WAP Write a menu driven program to perform the following operations of a stack using array by using suitable user defined functions for each case.
a) Check if the stack is empty b) Display the contents of stack c) Push d) Pop*/
#include <stdio.h>
#define LEN 20

int stack[LEN];
int top=-1;

int isEmpty(){
    if(top==-1)
        return 1;
    return 0;
}

void push(int d){
    if(top < LEN-1){
        stack[++top] = d;
    }else{
        printf("OVERFLOW\n");
    }
}

int pop(){
    if(isEmpty()){
        return -999;
    }
    return stack[top--];
}

void display(){
    if(isEmpty()){
        fprintf(stderr, "Empty!\n");
        return;
    }
    for(int i = top; i>=0; i--){
        printf("|%3d|\n",stack[i]);
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
