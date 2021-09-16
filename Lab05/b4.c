/*In a party of N people, only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. We can only ask questions like “does A know B? “. WAP to find the stranger (celebrity) in minimum number of questions.*/
#include <stdio.h>

// Max # of persons in the party
#define N 8
#define LEN 20

typedef struct stack
{
    int arr[LEN];
    int top;
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
    return (stk->top != -1) ? stk->arr[(stk->top)--], stk->size-- : -999;
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
 
// Person with 2 is celebrity
int MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};
 
 
// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(int n)
{
    // Handle trivial
    // case of size = 2
    Stack s;
    s.top = -1;
    s.size = 0;
 
    // Celebrity
    int C;
 
    // Push everybody to stack
    for (int i = 0; i < n; i++)
        push(&s,i);
 
    display(s);
  
 
    // Find a potential celebrity
    while (s.size > 1)
    {   int A = peek(s);
        pop(&s);
        int B = peek(s);
        pop(&s);
        if (MATRIX[A][B])   // it A knows B == 1 then push back B
        {
          push(&s, B);
        }
        else        // if A dos't know B then push A
        {
          push(&s, A);
        }
        display(s);
    }
    // If there are only two people
    // and there is no
    // potential candicate
    if(isEmpty(s))
        return -1;
   
   
    // Potential candidate?
    C = peek(s);
    pop(&s);
 
    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't
        // know 'C' or 'C' doesn't
        // know any person, return -1
        if ( (i != C) && (MATRIX[C][i] || !MATRIX[i][C]) )
            return -1;
    }
 
    return C;
}
 
// Driver code
int main(int argc, char **argv)
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? printf("No celebrity\n") :
               printf("Celebrity ID %d\n", id);

    remove(argv[0]);
    return 0;
}