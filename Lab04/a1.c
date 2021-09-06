/*WAP to create a double linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int d){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=d;
    t->next=t->prev=0;
    return t;
}

struct Node* insert(struct Node* head){
    int k;
    printf("Enter data: ");
    scanf("%d",&k);

    if(!head){
        return createNode(k);
    }
    struct Node* t = head;
    while(t->next)  t=t->next;
    t->next = createNode(k);
    t->next->prev = t;

    return head;
}


struct Node* display(struct Node* head){
    do{
        printf("%d",head->data);
        head = head->next;
    }while(head && printf("<->"));
    printf("\n");
}

void deleteNode(struct Node* head){
    struct Node* t=0;
    while(head){
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
