/*WAP to reverse the sequence elements in a double linked list.*/
#include <stdio.h>
#include <stdlib.h>
#include "../Lab04/DLL.h"

void reverse(struct Node **head)
{
    struct Node *temp = NULL;
    struct Node *curr = *head;
     
    if(!(*head))
        return;
    
    if((*head)->next==0){
        return;
    }
    while (curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;            
        curr = curr->prev;
    }
    // printf("temp: %d\n",temp->data);
    (*head) = temp->prev;
}

int main(int argc, char const *argv[])
{
    struct Node* head=0;
    head=insertUsr(head, 23);
    head=insertUsr(head, 2);
    head=insertUsr(head, 3);
    head=insertUsr(head, 13);
    head=insertUsr(head, 53);

    display(head);
    reverse(&head);
    display(head);
    
    deleteNode(head);
    remove(argv[0]);
    return 0;
}
