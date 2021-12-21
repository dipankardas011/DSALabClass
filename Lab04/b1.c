/*WAP to create a double circular double linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev,*next;
};

void insert(struct Node **head)
{
    int k;
    printf("Enter the data: ");
    scanf("%d",&k);
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = temp->prev = NULL;
    if(!(*head)){
        (*head) = temp;
        (*head)->next = (*head)->prev = (*head);
        return;
    }
    struct Node *t = (*head)->prev;

    t->next = temp;
    temp->prev = t;
    temp->next = *head;
    (*head)->prev = temp;
}

void display(struct Node* head){
    struct Node* t=head;
    do{
        printf("%d",t->data);
        t=t->next;
    }while(t!=head && printf("<->"));
    printf("\n");
}

void deleteNode(struct Node **head){
    struct Node* t = *head;
    do{
        *head = (*head)->next;
        free(t);
        t = *head;
    }while(*head != t);
}

int main(int argc, char const *argv[])
{
    struct Node *head=0;
    int ch;
    do{
        insert(&head);
        printf("Enter the 0 to EXIT: ");
        scanf("%d",&ch);
    }while(ch);
    display(head);
    deleteNode(&head);
    remove(argv[0]);
    return 0;
}
