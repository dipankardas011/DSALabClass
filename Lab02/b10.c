/*WAP to reverse only even position nodes in a singly linked list.*/
#include <stdio.h>
#include <stdlib.h>
#include "../Lab02/LL.h"

struct Node* reverseEvenPosition(struct Node* head){
    struct Node* evenHead=NULL;
    int i=1;
    struct Node* t=head;
    while(t){
        if(i%2==0)  // we could instead push it to the front so then no need for reverse
            evenHead = insertAtBack(evenHead, t->data);
        i++;
        t=t->next;
    }
    
    i=1;
    t=head;
    evenHead = reverseLL(evenHead);
    while(t){
        if(i%2==0)
        {
            t->data = evenHead->data;
            // deallocate
            struct node *ff = evenHead;
            evenHead = evenHead->next;
            free(ff);
        }
        i++;
        t=t->next;
    }
    t=NULL;
    return head;
}


int main(int argc, char** argv){
    struct Node* head=NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    head->next->next->next->next->next=createNode(6);

    display(head);
    head = reverseEvenPosition(head);
    display(head);

    freeHeap(head);
    return 0;
}