/*WAP to swap kth node from beginning with kth node from end in a Linked List*/
#include <stdio.h>
#include <stdlib.h>
#include "../Lab02/LL.h"


struct Node* swapK_Node(struct Node* head, int k){
    int count = countNodes(head);
    int pos=1;
    struct Node* left=head,
                * tleft = NULL;
    while(pos++ < k)
        tleft = left,
        left=left->next;

    struct Node* right = head,
                * tright = NULL;
    pos=0;
    while(k != count-pos){
        tright = right;
        right = right->next;
        pos++;
    }
    printf("%d ~~ %d\n",left->data, right->data);
    if(k==1){
        void* t = (struct Node*)left->next;
        left->next = right->next;
        right->next = t;
        tright->next = left;
        head = right;
        return head;

    }
    // 2 pointer to change 
    // 1. is the prev ->next 
    // 2. and the curr->next
    void* t = (struct Node*)tleft->next;
    tleft->next = tright->next;
    tright->next = t;

    t = (struct Node*)left->next;
    left->next = right->next;
    right->next = t;


    return head;
}

int main(int argc, char const *argv[])
{
    struct Node* head=0;
    head = insertAtBack(head, 1);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 3);
    head = insertAtBack(head, 4);
    head = insertAtBack(head, 5);
    head = insertAtBack(head, 6);
    head = insertAtBack(head, 7);
    head = insertAtBack(head, 8);

    display(head);

    int k;
    printf("Enter the val k.. ");
    scanf("%d",&k);
    head = swapK_Node(head, k);
    display(head);
    
    remove(argv[0]);
    return 0;
}
