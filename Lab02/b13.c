/*Given a singly linked list, rotate the linked list counter-clockwise by k nodes. Where k is a given positive integer. For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.*/
#include <stdio.h>
#include <stdlib.h>
#include "../Lab02/LL.h"

struct Node* rotateKthCC(struct Node* head, int k){
    int count=0;
    struct Node* start = head;
    struct Node *prevStart = NULL;
    while (count++ < k) {
        prevStart = start;
        start = start->next;
    }
    prevStart->next = NULL;
    struct Node *t1 = start;
    while(t1->next){
        t1=t1->next;
    }
    t1->next = head;
    head = start;

    return head;
}

int main(int argc, char const *argv[])
{
    struct Node *head=0;
    head = insertAtBack(head,10);
    head = insertAtBack(head,20);
    head = insertAtBack(head,30);
    head = insertAtBack(head,40);
    head = insertAtBack(head,50);
    head = insertAtBack(head,60);
    display(head);
    head = rotateKthCC(head,4);
    display(head);
    freeHeap(head);
    remove(argv[0]);
    return 0;
}
