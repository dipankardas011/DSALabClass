/*WAP to implement a stack which will support three additional operations in addition to push and pop by modifying LA 1.
    - peekLowestElement - return the lowest element in the stack without removing it from the stack
    - peekHighestElement - return the highest element in the stack without removing it from the stack
    - peekMiddleElement - return the (size/2+1)th lowest element in the stack without removing it from the stack.*/
#include <stdio.h>
#define LEN 20
#define INV -999

typedef struct node
{
    int top;
    int arr[LEN];
    int size;
} Stack;

void push(Stack *stk, int d)
{
    if (stk->top < LEN - 1)
    {
        stk->arr[++(stk->top)] = d;
        stk->size++;
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
        stk->size--;
        return stk->arr[(stk->top)--];
    }
    return INV;
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

int peek(Stack *s)
{
    if (s->top == -1)
        return INV;
    return s->arr[s->top];
}

int isEmpty(Stack *s)
{
    return (s->top == -1) ? 1 : 0;
}

int peekLowest(Stack *s)
{
    return (!isEmpty(s)) ? peek(s) : INV;
}

int peekMiddle(Stack *s)
{
    if (isEmpty(s))
        return INV;
    int count = (s->size / 2) + 1;
    Stack tmp;
    tmp.size = 0;
    tmp.top = -1;
    while (count > tmp.size + 1)
    {
        push(&tmp, pop(s));
    }
    int res = peek(s);
    while (!isEmpty(&tmp))
    {
        push(s, pop(&tmp));
    }
    return res;
}

int peekHighest(Stack *s)
{
    // to get the bottom
    if (isEmpty(s))
        return INV;
    Stack temp;
    temp.top = -1;
    temp.size = 0;
    while (!isEmpty(s))
    {
        push(&temp, pop(s));
    }
    int highest = peek(&temp);
    while (!isEmpty(&temp))
    {
        push(s, pop(&temp));
    }
    return highest;
}

void pushMin(Stack *s, int data)
{
    if (s->top == -1)
    {
        push(s, data);
        return;
    }
    // it the incomming data is min then insert it after pop till empty or get min than ddata
    if (data > peek(s))
    {
        Stack temp;
        temp.top = -1;
        temp.size = 0;
        while (s->top != -1 && peek(s) < data)
        {
            push(&temp, pop(s));
        }
        if (s->top == -1)
        {
            push(s, data);
            while (temp.top != -1)
            {
                push(s, pop(&temp));
            }
            return;
        }
        if (peek(s) >= data)
        {
            push(s, data);
            while (temp.top != -1)
            {
                push(s, pop(&temp));
            }
            return;
        }
    }
    else
    {
        push(s, data);
        return;
    }
}

int main(int argc, char const *argv[])
{
    int ch;
    Stack stk;
    stk.size = 0;
    stk.top = -1;
    do
    {
        printf("Enter 1 -> display\n");
        printf("Enter 2 -> push\n");
        printf("Enter 3 -> pop\n");
        printf("Enter 4 -> peekMin\n");
        printf("Enter 5 -> peekMax\n");
        printf("Enter 6 -> peekMiddle\n");
        printf("Enter 0 -> exit\n");
        // printf("Enter 4 -> \n");
        printf("-> ");
        scanf("%d", &ch);
        int k = 0;

        switch (ch)
        {
        case 1:
            display(stk);
            break;

        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &k);
            pushMin(&stk, k);
            break;

        case 3:
            k = pop(&stk);
            (k != INV) ? printf("Popped: %d\n", k) : printf("Already Empty!\n");
            break;

        case 4:
            k = peekLowest(&stk);
            (k != INV) ? printf("Lowest: %d\n", k) : printf("Already Empty!\n");
            break;

        case 5:
            k = peekHighest(&stk);
            (k != INV) ? printf("Highest: %d\n", k) : printf("Already Empty!\n");
            break;

        case 6:
            k = peekMiddle(&stk);
            (k != INV) ? printf("Middle: %d\n", k) : printf("Already Empty!\n");
            break;
        }
    } while (ch);
    remove(argv[0]);
    return 0;
}
