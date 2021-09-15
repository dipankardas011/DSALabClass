/*WAP using a function that sort an array of integers using stacks and also uses bubble sort*/
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
    return (stk->top != -1) ? stk->arr[(stk->top)--] : -999;
}

int peek(Stack s)
{
    return (s.top == -1) ? -999 : s.arr[s.top];
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

int isEmpty(Stack s)
{
    return (s.top == -1) ? 1 : 0;
}

void bubbleSortUsingStack(int *a, int n)
{
    Stack s1;
    s1.top = -1;
    for (int i = 0; i < n; i++)
        push(&s1, a[i]);

    Stack s2;
    s2.top = -1;
    for (int i = 0; i < n; i++)
    {
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
            else
            {
                push(&s2, t);
            }
        }
        a[n-1-i] = pop(&s2);
    }
    int i = 0;
    printf("{");
    do
    {
        printf("%d", a[i]);
        i++;
    } while (i < n && printf(", "));
    printf("}\n");
}

int main(int argc, char const *argv[])
{
    int arr[] = {34, 3, 31, 98, 92, 23};
    int n = sizeof(arr) / sizeof(int);

    bubbleSortUsingStack(arr, n);
    remove(argv[0]);
    return 0;
}
