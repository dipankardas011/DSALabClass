/* WAP to reverse a stack with using extra stack.*/
#include <stdio.h>
#define LEN 20

typedef struct stack{
    int arr[LEN];
    int top;
}Stack;

void push(Stack *stk, int d)
{
    if(stk->top < LEN-1){
        stk->arr[++(stk->top)] = d;
    }else{
        printf("OVERFLOW\n");
    }
}

int pop(Stack *stk){
    if(stk->top!=-1){
        return stk->arr[(stk->top)--];
    }
    return -999;
}

void display(Stack s){
    if(s.top!=-1){
        for(int i=s.top; i>=0; i--)
            printf("|%3d|\n",s.arr[i]);

        printf("+---+\n");
    }
    else{
        printf("UNDERFLOW\n");
    }
}

int isEmpty(Stack s){
    if(s.top==-1)
        return 1;

    return 0;
}


int main(int argc, char const *argv[])
{
    int arr[]={2,3,6,1,9,7};
    Stack stk1;
    stk1.top = -1;
    int n = sizeof(arr)/sizeof(int);
    for(int i=0; i<n; i++)
        push(&stk1, arr[i]);

    display(stk1);

    Stack stk2;
    stk2.top = -1;

    while(!isEmpty(stk1)){
        push(&stk2, pop(&stk1));
    }
    printf("Final stack O/P:\n");
    display(stk2);

    remove(argv[0]);
    return 0;
}
