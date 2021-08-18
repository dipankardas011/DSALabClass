/*Write a menu driven program to perform the following operations in a single linked list by using suitable user defined functions for each case.
    a) Traversal of the list.
    b) Check if the list is empty.
    c) Insert a node at the certain position (at beginning/end/any position).
    d) Delete a node at the certain position (at beginning/end/any position).
    e) Delete a node for the given key.
    f) Count the total number of nodes.
    g) Search for an element in the linked list.
Verify & validate each function from main method.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int d)
{
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=d;
    t->next=NULL;

    return t;
}

void deleteLL(struct Node* head)
{
    struct Node *temp=NULL;
    while(head)
    {
        temp = head;
        temp=temp->next;
        free(head);
        head = temp;
    }
    free(temp);
}

bool isEmpty(struct Node* h){
    return !h ? true : false;
}

void traversal(struct Node* h)
{
    if(isEmpty(h))
    {
        printf("^~~~ Empty!\n");
        return;
    }
    
    struct Node* t=h;
    do{
        printf("%d",t->data);
        t=t->next;
    }while(t && printf("->"));
    printf("\n");
}



struct Node* insertAtPos(struct Node* head, int data, int pos)
{
    if(isEmpty(head)){
        return createNode(data);
    }

    if(pos==1){
        //beginning
        struct Node *start = createNode(data);
        start->next = head;
        head=start;
        return head;
    }
    //else
    int currPos=1;
    struct Node* t=head;
    while(t && currPos < pos-1){
        t=t->next;
        currPos++;
    }
    struct Node* tt=createNode(data);
    if(!t->next)//at last
    {
        t->next = tt;
        return head;
    }
    tt->next = t->next;
    t->next = tt;
    return head;
}


struct Node *deleteFromPos(struct Node* head, int pos)
{
    if(isEmpty(head))
    {
        printf("^~~~ empty\n");
        return NULL;
    }
    if(pos==1){
        struct Node* t=head;
        head = head->next;
        free(t);
        return head;
    }
    struct Node* tt=head;
    int currPos=1;
    while(tt && currPos<pos-1){
        tt=tt->next;
        currPos++;
    }
    if(!tt->next){
        printf("^~~~ Invalid position\n");
        return head;
    }
    struct Node* dele = tt->next;
    tt->next = dele->next;
    free(dele);
    return head;
}

int noOfNodes(struct Node* head){
    int count=0;
    struct Node* t=head;
    while(t){
        count++;
        t=t->next;
    }

    return count;
}

int search(struct Node* head, int key){
    int pos=1;
    struct Node *t=head;
    while(t){
        if(t->data == key)
            return pos;

        pos++;
        t=t->next;
    }
    return INT_MAX;
}

struct Node *deleteFromKey(struct Node* head, int key){
    
    if(isEmpty(head))
    {
        printf("^~~~ empty\n");
        return NULL;
    }
    
    int pos = search(head,key);

    return deleteFromPos(head,pos);
}


int main(int argc, char const *argv[])
{
    struct Node* head=NULL;
    int ch;
    do{
        printf("Enter:\n1->traverse\n2->isEmpty\n3->insert\n4->delete\n5->delete from key\n6->no of nodes\n7->search\n: ");
        scanf("%d",&ch);
        int num;
        int position;
        switch(ch)
        {
            case 1: traversal(head);
            break;

            case 2: (isEmpty(head))?printf("[Empty]\n"):printf("[Not Empty]\n");
            break;

            case 3:{
                printf("Enter data to inserted as well as the position for it\n: ");
                scanf("%d %d",&num,&position);

                head = insertAtPos(head,num,position);
            }break;

            case 4:{
                printf("Enter position of node to be deleted\n: ");
                scanf("%d",&position);
                head = deleteFromPos(head,position);
            }
            break;

            case 5:{
                printf("Enter key to be deleted\n: ");
                scanf("%d",&num);
                head = deleteFromKey(head,num);
            }
            break;

            case 6: printf("No of nodes= %d\n",noOfNodes(head));
            break;

            case 7:{
                printf("Enter the key to search\n: ");
                scanf("%d",&num);
                (search(head,num)!=INT_MAX) ? 
                    printf("[Found]\n")  : 
                        printf("[Not found]\n");
            }
            break;
        }
        printf("Enter 0 to exit... ");
        scanf("%d",&ch);
    }while(ch);

    deleteLL(head);

    remove(argv[0]);
    return EXIT_SUCCESS;
}
