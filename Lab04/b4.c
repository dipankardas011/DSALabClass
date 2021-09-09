/*WAP to convert a given singly linked list to a circular list.*/
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

void display(struct Node *head, int ch)
{
    if (ch)
    { // if 1 is passed means for Singly LL
        do
        {
            printf("%d", head->data);
            head = head->next;
        } while (head && printf("->"));
        printf("\ntail->next = %p\n", head);
        return;
    }
    struct Node* t=head;
    do
    {
        printf("%d", t->data);
        t = t->next;
    } while (t!=head && printf("->"));
    printf("\ntail->next = %p\n", t);
}

struct Node *insertAtBack(struct Node *h, int data)
{
    if (!h)
    {
        return createNode(data);
    }

    struct Node *t = h;
    while (t->next)
        t = t->next;
    t->next = createNode(data);
    // t=NULL;
    return h;
}

void freeHeap(struct Node *h)
{
    struct Node *temp = NULL;
    while (temp)
    {
        temp = h;
        h = h->next;
        free(temp);
        temp=h;
    }
    free(h);
}

void ConvertToCircularLL(struct Node **head)
{
    struct Node *t = *head;
    while (t->next)
        t = t->next;
    t->next = *head;
    return;
}

int main(int argc, char const *argv[])
{
    struct Node *head = 0;
    head = insertAtBack(head, 1);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 4);
    head = insertAtBack(head, 3);
    display(head,1);

    ConvertToCircularLL(&head);
    display(head,0);

    freeHeap(head);
    // system("clear");
    remove(argv[0]);
    return 0;
}
