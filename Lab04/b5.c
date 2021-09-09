/*WAP to implement a doubly linked list by using singly linked.*/
#include <stdio.h>
#include <stdlib.h>


typedef struct Node1
{
    int data;
    struct Node1 *prev, *next;
} DNode;

DNode *createNode(int d)
{
    DNode *t = (DNode *)malloc(sizeof(DNode));
    t->data = d;
    t->next = t->prev = 0;
    return t;
}

typedef struct Node
{
    int data;
    struct Node *next;
}SNode;

SNode *createNodeS(int d)
{
    SNode *t = (SNode *)malloc(sizeof(SNode));
    t->data = d;
    t->next = NULL;
    return t;
}

DNode *insertUsr(DNode *head, int k)
{

    if (!head)
    {
        return createNode(k);
    }
    DNode *t = head;
    while (t->next)
        t = t->next;
    t->next = createNode(k);
    t->next->prev = t;

    return head;
}

void deleteNode(DNode *head)
{
    DNode *t = 0;
    while (head)
    {
        t = head;
        head = head->next;
        free(t);
    }
    free(head);
}

void display(SNode *head)
{
    do
    {
        printf("%d", head->data);
        head = head->next;
    } while (head && printf("->"));
    printf("\n");
}

SNode *insertAtBack(SNode *h, int data)
{
    if (!h)
    {
        return createNodeS(data);
    }

    SNode *t = h;
    while (t->next)
        t = t->next;
    t->next = createNodeS(data);
    // t=NULL;
    return h;
}

void displayD(DNode *h)
{
    do
    {
        printf("%d", h->data);
        h = h->next;
    } while (h && printf("<->"));
    printf("\n");
}

void ConvertSinglyToDoublyLL(SNode *head, DNode **dhead)
{
    display(head);
    while (head)
    {
        *dhead = insertUsr(*dhead, head->data);
        head = head->next;
    }

    displayD(*dhead);
}


void freeHeap(SNode *h)
{
    SNode *temp = NULL;
    while (h)
    {
        temp = h;
        temp = temp->next;
        free(h);
        h=temp;
    }
    free(temp);
}
int main(int argc, char const *argv[])
{
    SNode *head = 0;
    head = insertAtBack(head, 1);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 3);
    head = insertAtBack(head, 4);

    DNode *dhead = 0;
    ConvertSinglyToDoublyLL(head, &dhead);

    freeHeap(head);
    deleteNode(dhead);

    remove(argv[0]);
    return 0;
}
