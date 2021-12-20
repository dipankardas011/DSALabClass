/*WAP to implement a Queue in Linked Lists using Stacks.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Stack;

int isEmpty(Stack* stk){
    return stk==NULL ? 1 : 0;
}

void push(Stack** stk, int d){
    Stack *temp = (Stack *)malloc(sizeof(Stack));
    temp->data=d;
    temp->next = NULL;
    if (isEmpty(*stk)) {
        *stk = temp;
    } else {
        temp->next = *stk;
        *stk = temp;
    }
}

void pop(Stack** stk){
    if(isEmpty(*stk)){
        return;
    }
    Stack *ff = NULL;
    ff = *stk;
    *stk = (*stk)->next;
    free(ff);
}

void displayS(Stack* top){
    while(top!=NULL){
        printf("| %d |\n", top->data);
        top = top->next;
    }
    printf("\n");
}

int peek(Stack* s){
    return isEmpty(s) ? -111 : s->data;
}

void enQueue(Stack** stk, int idata){
    Stack *tstk = NULL;
    while(!isEmpty(*stk)){
        push(&tstk, peek(*stk));
        pop(stk);
    }

    push(&tstk, idata);

    while(!isEmpty(tstk)){
        push(stk, peek(tstk));
        pop(&tstk);
    }
}

void deQueue(Stack** stk){
    int f = (*stk)->data;
    pop(stk);
    printf("Popped: %d\n", f);
}

void display(Stack* stk){
    if(!isEmpty(stk)){
        printf("%d ", stk->data);
        display(stk->next);
    }
}

int main(int argc, char **argv)
{
    Stack *stk = NULL;
    int ch;

    do{
        printf("[ 1 ] to push\n[ 2 ] to pop\n[ 3 ] to display\n[ 0 ] to EXIT\n> ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int k;
                printf("Enter the element to insert: ");
                scanf("%d", &k);
                enQueue(&stk, k);
                break;
            }
            case 2:{
                deQueue(&stk);
                break;
            }
            case 3:{
                printf("| ");
                display(stk);
                printf("|\n");
                break;
            }
        }
    } while (ch);

    remove(argv[0]);
    return EXIT_SUCCESS;
}