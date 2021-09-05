/*WAP to remove the duplicates in a sorted double linked list.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next, *prev;
};

struct Node *createNode(int d)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = d;
    t->next = t->prev = 0;
    return t;
}

struct Node *insertAtBack(struct Node *head, int d)
{
    if (!head)
    {
        return createNode(d);
    }
    struct Node *t = head;
    while (t->next)
        t = t->next;

    t->next = createNode(d);
    t->next->prev = t;

    return head;
}

struct Node* removeDuplicates(struct Node* head){
    struct Node* curr = head;
    
    while(curr->next){
        if(curr->data == curr->next->data){
            struct Node* t=curr->next;
            curr->next = curr->next->next;
            free(t);
        }

        else{
            curr = curr->next;
        }
    }
    return head;
}

void display(struct Node* head){
    do{
        printf("%d",head->data);
        head=head->next;
    }while(head && printf("<->"));

    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Node *head = 0;
    head = insertAtBack(head, 10);
    head = insertAtBack(head,10);
    head = insertAtBack(head,20);
    head = insertAtBack(head,30);
    head = insertAtBack(head,30);
    head = insertAtBack(head,50);
    head = insertAtBack(head,60);

    display(head);
    removeDuplicates(head);
    display(head);

    remove(argv[0]);
    return 0;
}
