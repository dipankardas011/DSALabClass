/*WAP to create a single circular double linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.*/
/***
 * @bug the question must contain singly circular linklist
 */
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node /**prev,*/ *next;
};

struct Node* createNode(int d){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=d;
    t->next/*=t->prev*/=0;
    return t;
}

struct Node* insert(struct Node* head){
    int k;
    printf("Enter data: ");
    scanf("%d",&k);
    struct Node *temp=createNode(k);
    if(!head){
        /*temp->prev =*/ temp->next = temp;
        head = temp;
        return head;
    }
    struct Node* t = head;
    while(t->next!=head)  t=t->next;
    t->next = temp;
    // temp->prev= t;

    temp->next = head;
    // head->prev = temp;

    return head;
}


struct Node* display(struct Node* head){
    struct Node* hh = head;
    do{
        printf("%d",head->data);
        head = head->next;
    }while(head!=hh && printf("<->"));
    printf("\n");
}

struct Node* deleteNode(struct Node* head){
    struct Node* t=0,
                *hh=head;
    while(head!=hh){
        t=head;
        head = head->next;
        free(t);
    }
    free(head);
}

int main(int argc, char const *argv[])
{
    struct Node* head=0;
    int ch;
    do{
        head = insert(head);
        printf("Enter 0 To STOP input: ");
        scanf("%d",&ch);
    }while(ch);

    display(head);
    deleteNode(head);
    remove(argv[0]);
    return 0;
}
