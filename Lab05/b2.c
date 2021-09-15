/*WAP to sort the elements inside a stack using only push and pop operation. Any number of additional stacks may be used.*/
/*
input: [34, 3, 31, 98, 92, 23]

Element taken out: 23
input: [34, 3, 31, 98, 92]
tmpStack: [23]

Element taken out: 92
input: [34, 3, 31, 98]
tmpStack: [23, 92]

Element taken out: 98
input: [34, 3, 31]
tmpStack: [23, 92, 98]

Element taken out: 31
input: [34, 3, 98, 92]
tmpStack: [23, 31]

Element taken out: 92
input: [34, 3, 98]
tmpStack: [23, 31, 92]

Element taken out: 98
input: [34, 3]
tmpStack: [23, 31, 92, 98]

Element taken out: 3
input: [34, 98, 92, 31, 23]
tmpStack: [3]

Element taken out: 23
input: [34, 98, 92, 31]
tmpStack: [3, 23]

Element taken out: 31
input: [34, 98, 92]
tmpStack: [3, 23, 31]

Element taken out: 92
input: [34, 98]
tmpStack: [3, 23, 31, 92]

Element taken out: 98
input: [34]
tmpStack: [3, 23, 31, 92, 98]

Element taken out: 34
input: [98, 92]
tmpStack: [3, 23, 31, 34]

Element taken out: 92
input: [98]
tmpStack: [3, 23, 31, 34, 92]

Element taken out: 98
input: []
tmpStack: [3, 23, 31, 34, 92, 98]

final sorted list: [3, 23, 31, 34, 92, 98]
*/
#include <stdio.h>
#define LEN 20

typedef struct stack
{
    int arr[LEN];
    int top;
} Stack;

void push(Stack *stk, int d)
{
    if (stk->top < LEN - 1)
    {
        stk->arr[++(stk->top)] = d;
    }
    else
    {
        printf("OVERFLOW\n");
    }
}

int pop(Stack *stk)
{
    if (stk->top != -1)
    {
        return stk->arr[(stk->top)--];
    }
    return -999;
}

void display(Stack s)
{
    if (s.top != -1)
    {
        for (int i = s.top; i >= 0; i--)
            printf("|%3d|\n", s.arr[i]);

        printf("+---+\n");
    }
    else
    {
        printf("UNDERFLOW\n");
    }
}

int peek(Stack s)
{
    if (s.top == -1)
        return -999;
    return s.arr[s.top];
}

int isEmpty(Stack s)
{
    return (s.top == -1) ? 1 : 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {34, 3, 31, 98, 92, 23};
    int n = sizeof(arr) / sizeof(int);

    Stack s1;
    s1.top = -1;
    for (int i = 0; i < n; i++)
        push(&s1, arr[i]);

    display(s1);

    Stack s2;
    s2.top = -1;

    while (!isEmpty(s1))
    {
        int t = pop(&s1);
        if (isEmpty(s2))
        {
            // push it
            push(&s2, t);
            continue;
        }
        while (t < peek(s2) && !isEmpty(s2))
        {
            // till then push the element back to the stk1
            push(&s1, pop(&s2));
        }
        if (t > peek(s2) && !isEmpty(s2))
        {
            push(&s2, t);
        }
        else{
            push(&s2,t);
        }
    }

    display(s2);
    for(int i=0;i<n;i++)
        arr[n-1-i] = pop(&s2);

    printf("Res: { ");
    int i=0;
    do
    {
        printf("%d", arr[i]);
        i++;
    } while (i<n && printf(", "));
    printf(" }\n");
    remove(argv[0]);
    return 0;
}
