/*
Given a singly linked list with nodes L0 -> L1 -> … -> Ln-1 -> Ln. Design the
algorithm/develop pseudocode/write C code to rearrange the nodes in the list so
that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

//............................................................................

struct Node* createNode(int d){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data = d;
    t->next = 0;
    return t;
}

struct Node* insertAtBack(struct Node* head, int d){
    if(!head)
        return createNode(d);

    struct Node* t=head;
    while(t->next)
        t=t->next;
    
    t->next = createNode(d);

    return head;
}
int countNodes(struct Node* head){
    int count=0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

struct Node* head1;

void develop(struct Node* head, struct Node** tail, int c)
{
    if(head){
        develop(head->next, tail, c);
        // reverse
        // printf("%d\t%d\n",head->data, (*tail)->data);
        if(countNodes(head1) < c)
        head1 = insertAtBack(head1, (*tail)->data);
        if(countNodes(head1) < c)
        head1 = insertAtBack(head1, head->data);
        (*tail)=(*tail)->next;
    }
}



//............................................................................



void display(struct Node* head){
    do{
        printf("%d",head->data);

        head = head->next;
    }while(head && printf("->"));
    printf("\n");
}

int main(){
    struct Node* head=0;
    head1=0;
    head = insertAtBack(head, 1);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 3);
    head = insertAtBack(head, 4);
    head = insertAtBack(head, 5);
    head = insertAtBack(head, 6);

    display(head);

    develop(head, &head, countNodes(head));

    display(head1);


    return 0;
}