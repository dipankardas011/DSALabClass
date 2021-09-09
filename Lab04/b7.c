/*Given a double linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *prev, *next;
}DNode;

void insert(DNode **head, int k){
    DNode *t=(DNode*)malloc(sizeof(DNode));
    t->data = k;
    t->prev = t->next = 0;
    if(!(*head)){
        *head = t;
        return;
    }
    DNode *te = *head;
    while(te->next) te=te->next;

    te->next = t;
    t->prev = te;
}

void display(DNode *h){
    do{
        printf("%d",h->data);
        h=h->next;
    }while(h && printf("<->"));
    printf("\n");
}

void RotateKtimes(DNode *head, int k){
    DNode *part2=head;
    DNode *part1=0;
    int count=1;
    part1 = head;
    while(part1){
        if(count==k)
            break;
        count++;
        part1 = part1->next;
    }
    if(!part1->next){
        // rotated completly
        display(head);
    }
    DNode * t = part1 ;
    part1 = part1->next;
    t->next=0;
    head = part1;
    while(part1->next)
        part1 = part1->next;

    part1->next=part2;
    part2->prev = part1;
    display(head);
}

int main(int argc, char const *argv[])
{
    DNode *head = 0;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    insert(&head, 60);
    display(head);
    RotateKtimes(head,4);

    remove(argv[0]);
    return 0;
}
