/*WAP to implement a Queue in Linked Lists using Stacks.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n *next;
} queue;

queue *front = NULL;

queue *rear = NULL;

void insert(int* stk1, int *top)
{

    int *stk2 = (int *)malloc(sizeof(int)*100);
    int top2 = -1;

        
        while(*top!=-1){
            stk2[++top2] = stk1[*top];
            (*top)--;
        }

        queue *temp = (queue *)malloc(sizeof(queue));
        temp->data = stk2[top2];
        temp->next = NULL;
        if(!front){
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = rear->next;
        }

        top2--;

        while(top2!=-1){
            printf("ss %d\n", stk2[top2]);
            stk1[++(*top)] = stk2[top2];
            top2--;
        }

    free(stk2);
}

void pop(){
    queue *ff = 0;
    int x = 0;
    if (front == rear)
    {
        ff = front;
        x = ff->data;
        front = rear = NULL;
        free(ff);
    } else {
        x = front->data;
        ff = front;
        front = front->next;
        free(ff);
    }
    printf("popped: %d\n", x);
}

void display(){
    if(front){
        queue *iter = front;
        printf("| ");
        do
        {
            printf("%d", iter->data);
            iter = iter->next;
        } while (iter && printf(" | "));
        printf(" |\n\n");
    } else {
        printf("Empty\n");
    }
}

int main(int argc, char **argv)
{
    int *stk1 = (int *)malloc(sizeof(int *)*100);
    int top = -1;
    int ch;

    do{
        printf("[ 1 ] to push\n[ 2 ] to pop\n[ 3 ] to display\n[ 0 ] to EXIT\n> ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int k;
                printf("Enter the element to insert: ");
                scanf("%d", &k);
                stk1[++top] = k;
                insert(stk1, &top);
                break;
            }
            case 2:{
                top--;
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
        }
    } while (ch);

    free(stk1);
    remove(argv[0]);
    return EXIT_SUCCESS;
}