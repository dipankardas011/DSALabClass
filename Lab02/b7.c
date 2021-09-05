/*WAP to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int d)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = d;
    t->next = NULL;
    return t;
}

void insertNodes(struct Node **h, struct Node **l, int d)
{
    //insert at back
    if (!*h)
    {
        *h = *l = createNode(d);
        return;
    }

    struct Node *temp = createNode(d);
    (*l)->next = temp;
    (*l) = temp;
    temp = NULL;
    return;
}

void display(struct Node *head)
{
    do
    {
        printf("%d", head->data);
        head = head->next;
    } while (head && printf("->"));
    printf("\n");
}

void freeHeap(struct Node *h)
{
    struct Node *temp = NULL;
    while (h)
    {
        temp = h;
        h = h->next;
        free(temp);
    }
}

struct Node *sortingNodes(struct Node *head)
{
    struct Node* evenHead=NULL;
    struct Node* oddHead=NULL;
    struct Node* evenTail=NULL;
    struct Node* oddTail=NULL;

    while(head){
        if(head->data & 1){
            insertNodes(&oddHead,&oddTail,head->data);
        }else{
            insertNodes(&evenHead,&evenTail,head->data);
        }

        head=head->next;
    }
    freeHeap(head);
    head=NULL;
    evenTail->next = oddHead;
    head = evenHead;
    return head;
}

int main(int argc, char **argv)
{
    struct Node *head = NULL, *last = NULL;
    insertNodes(&head, &last, 33);
    insertNodes(&head, &last, 57);
    insertNodes(&head, &last, 334);
    insertNodes(&head, &last, 24);
    insertNodes(&head, &last, 39);

    printf("Before: ");
    display(head);
    printf("After: ");
    head = sortingNodes(head);
    display(head);
    freeHeap(head);
    remove(argv[0]);
    return EXIT_SUCCESS;
}