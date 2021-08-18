/*WAP to print mth node from the last of a linked list of n nodes.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int d)
{
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=d;
    t->next=NULL;

    return t;
}

void deleteLL(struct Node* head)
{
    struct Node *temp=NULL;
    while(head)
    {
        temp = head;
        temp=temp->next;
        free(head);
        head = temp;
    }
    free(temp);
}


void printInReverse(struct Node* head, int m){
    if(head){
        static int pos=0;
        printInReverse(head->next, m);
        pos++;
        if(pos == m)
        {
            printf("%d\n",head->data);
            return ;
        }
    }
}

void traversal(struct Node* h)
{
    if(!h)
    {
        printf("^~~~ Empty!\n");
        return;
    }
    
    struct Node* t=h;
    do{
        printf("%d",t->data);
        t=t->next;
    }while(t && printf("->"));
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Node* head=NULL;
    head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);

    traversal(head);
    printf("Enter the value of m.. ");
    int m;
    scanf("%d",&m);
    printInReverse(head,m);

    deleteLL(head);
    remove(argv[0]);
    return 0;
}
