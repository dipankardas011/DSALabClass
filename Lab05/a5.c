/*Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or { ) occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and (). A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. WAP to determine whether the input sequence of brackets is balanced or not. If a string is balanced, it print YES on a new line; otherwise, print NO on a new line. 
Example: Input: {[()]} and Output: YES
Input: {[(])} and Output: NO*/
// first sheck if the pair exist
// then use the stack to see the order if 
//            top element is ( opening braket and data to be inserted is also of the same type like ( then push if ) then pop top
// if top is ( opening braket and data to be inserted is differenct type and that to closing ] then error
#include <stdio.h>
#define LEN 30
#define INV -999

typedef struct node{
    char data[LEN];
    int top;
}Stack;

void push(Stack *s, int d){
    (s->top < LEN-1) ? s->data[++(s->top)] = d : printf("OVERFLOW\n");
}

int pop(Stack *s){
    return (s->top==-1)? INV : s->data[(s->top)--];
}

int peek(Stack s){
    return (s.top==-1)? INV : s.data[s.top];
}

int isEmpty(Stack s){
    return (s.top == -1)? 1 : 0;
}

int isopenBracket(char c){
    return (c=='(' || c=='{' || c=='[') ? 1 : 0;
}

int iscloseBracket(char c){
    return (c==')' || c=='}' || c==']') ? 1 : 0;
}

int isSameBracket(char a, char b){
    if(a=='['&& b==']')
        return 1;
    if(a=='{'&& b=='}')
        return 1;
    if(a=='('&& b==')')
        return 1;
    return 0;
}

int isValid(char *exp){

    if(exp[LEN-1] != '\0')  // if the arr has stored over its size
        return 0;


    int curlyNo = 0,
        sqNo = 0,
        bracNo = 0;
    for(int i=0;exp[i]; i++){
        switch(exp[i])
        {
            case '(': bracNo++;break;
            case ')': bracNo--;break;
            case '[': sqNo++;break;
            case ']': sqNo--;break;
            case '{': curlyNo++;break;
            case '}': curlyNo--;break;
        }
    }
    if(curlyNo || sqNo || bracNo)
        return 0;

    Stack stk;
    stk.top = -1;
    for(int i=0;exp[i];i++){
        if(isopenBracket(exp[i]))
            push(&stk, exp[i]);

        if(iscloseBracket(exp[i]))
        {
            if(isEmpty(stk)){
                return 0;
            }
            else{
                // if(!same(stack[top--],a[j]))
                if(!isSameBracket(peek(stk),exp[i])){
                    return 0;
                }
                pop(&stk);
            }
        } 
    }
    if(!isEmpty(stk)){
        return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    char exp[LEN]={0};
    printf("Enter the expression: ");
    scanf("%s",exp);

    isValid(exp)?printf("YES!\n"):printf("NO!\n");
    remove(argv[0]);
    return 0;
}
