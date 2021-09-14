/*WAP to sort the elements inside a stack using only push and pop operation. Any number of additional stacks may be used.*/
/*
 1-> 2 56 75 35
 2-> X

 1-> 2 56 75
 2-> 35

 1-> 2 56 35
 2-> 75

 1-> 2 56
 2-> 75 35

 1-> 2 35
 2-> 75 56

 1-> X
 2-> 75 56 35 2
*/
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

int peek(Stack s){
    if(s.top==-1)
        return -999;
    return s.arr[s.top];
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 56, 75, 35};
    int n = sizeof(arr)/sizeof(int);

    Stack stk1;
    stk1.top = -1;
    for(int i=0;i<n;i++)
        push(&stk1, arr[i]);

    display(stk1);

    Stack stk2;
    stk2.top = -1;

    while(peek(stk1)!=-999){
        if(peek(stk2)==-999){
            push(&stk2, pop(&stk1));
        }
        else if(peek(stk1) > peek(stk2)){
            int temp = pop(&stk1);
            push(&stk1, pop(&stk2));
            push(&stk2, temp);
        }else{
            push(&stk2, pop(&stk1));
        }
    }
    printf("Res: { ");
    do{
        printf("%d",pop(&stk2));
    }while(peek(stk2)!=-999 && printf(", "));
    printf(" }\n");
    remove(argv[0]);
    return 0;
}
