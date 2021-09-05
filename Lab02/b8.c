/*WAP to check whether a singly linked list is a palindrome or not.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Lab02/LL.h"

bool isPalindrome(struct Node** head, struct Node* last){
    if(last){
        isPalindrome(head,last->next);

        // ll in reverse order
        // printf("compare: %d ?= %d\n",(*head)->data,last->data);
        if((*head)->data != last->data){
            return false;
        }
        (*head)=(*head)->next;
        return true;
    }
    return true;
}

int main(int argc, char** argv){
    struct Node* head=NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);
    display(head);
    (isPalindrome(&head, head)) ? printf("Palindrome\n") : printf("Not Palindrome\n");
    freeHeap(head);
    remove(argv[0]);
    return 0;
}