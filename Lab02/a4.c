/*WAP to display the contents of a linked list in reverse order.*/
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


void printInReverse(struct Node* head){
    if(head){
        printInReverse(head->next);
        printf("%d ",head->data);
    }
}

int main(int argc, char const *argv[])
{
    struct Node* head=NULL;
    head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);

    printInReverse(head);

    deleteLL(head);
    remove(argv[0]);
    return 0;
}
