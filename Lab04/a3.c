/*Write a menu driven program to perform the following operations in a double linked list by using suitable user defined functions for each case.
a) Traverse the list forward,  
b) Traverse the list backward, 
c) Check if the list is empty
d) Insert a node at the certain position (at beginning/end/any position)
e) Delete a node at the certain position (at beginning/end/any position)
f) Delete a node for the given key, 
g) Count the total number of nodes, 
h) Search for an element in the linked list
Verify & validate each function from main method*/
#include <stdio.h>
#include <stdlib.h>
#include "../Lab04/DLL.h"

int count=0;

struct Node* getLast(struct Node* head){
    while(head->next)
        head = head->next;

    return head;
}

void traverseForward(struct Node* head){
    do{
        printf("%d",head->data);
        head=head->next;
    }while(head && printf("<->"));
    printf("\n");
}

void traverseBackward(struct Node* last){
    do{
        printf("%d",last->data);
        last=last->prev;
    }while(last && printf("<->"));
    printf("\n");
}

void isEmpty(struct Node* head){
    if(!head)
    {
        printf("Empty\n");
    }
    else{
        printf("Not Empty\n");
    }
}

void countNodes(struct Node* head){
    
    while(head){
        count++;
        head = head->next;
    }

}


struct Node* insertAtPos(struct Node* head, struct Node** last, int key, int position)
{
    if(position > count){
        fprintf(stderr, "^~~~ INV position\n");
        return head;
    }
    struct Node* temp = createNode(key);
    if(position==1){
        temp->next = head;
        head->prev = temp;
        head = temp;
        count++;
        return head;
    }
    if(position == count){
        temp->prev = (*last);
        (*last)->next = temp;
        (*last) = temp;
        count++;
        return head;
    }

    // in position
    struct Node* t= head;
    int c=1;
    while(t && c<position){
        t=t->next;
        c++;
    }
    // c==position
    temp->next = t;
    temp->prev = t->prev;
    t->prev->next = temp;
    t->prev = temp;
    count++;
    return head;
}

int searchKey(struct Node* head, int k){
    while(head){
        if(k==head->data){
            return 1;
        }
        head=head->next;
    }
    return 0;
}

struct Node* deleteFromKey(struct Node* head, struct Node** last, int key){
    struct Node* temp=NULL;
    if(!searchKey(head,key)){
        fprintf(stderr,"INV key # not found #\n");
        return head;
    }
    if(head->data == key){
        //beginning
        temp = head;
        head = head->next;
        head->prev=0;
        free(temp);
        count--;
        return head;
    }
    if((*last)->data == key){
        //at end
        temp = (*last);
        (*last)=(*last)->prev;
        (*last)->next=NULL;
        free(temp);
        count--;
        return head;
    }
    free(temp);
    struct Node* t= head;
    while(t && t->data != key){
        t=t->next;
    }
    t->prev->next=t->next;
    t->next->prev = t->prev;
    free(t);
    count--;
    return head;
}

struct Node* deleteAtPos(struct Node* head, struct Node** last, int position)
{
    if(position > count){
        fprintf(stderr, "^~~~ INV position\n");
        return head;
    }
    struct Node* temp = NULL;
    if(position==1){
        temp = head;
        head = head->next;
        head->prev=0;
        free(temp);
        count--;
        return head;
    }
    if(position == count){
        temp = (*last);
        (*last)=(*last)->prev;
        (*last)->next=NULL;
        free(temp);
        count--;
        return head;
    }

    // in position
    struct Node* t= head;
    int c=1;
    while(t && c<position){
        t=t->next;
        c++;
    }
    t->prev->next=t->next;
    t->next->prev = t->prev;
    free(t);
    count--;
    return head;
}




int main(int argc, char const *argv[])
{
    struct Node *head=0,
                *last=0;
    int ch;
    head=insertUsr(head, 23);
    head=insertUsr(head, 2);
    head=insertUsr(head, 3);
    head=insertUsr(head, 13);
    head=insertUsr(head, 53);
    countNodes(head);

    last = getLast(head);
    display(head);
    do{
        printf("Enter 1->traverse forward\n");
        printf("Enter 2->traverse Backward\n");
        printf("Enter 3->is list empty\n");
        printf("Enter 4->insert at pos\n");
        printf("Enter 5->delete at pos\n");
        printf("Enter 6->delete for given key\n");
        printf("Enter 7->number of nodes\n");
        printf("Enter 8->search\n");
        scanf("%d",&ch);
        int pos=0,k=0;
        switch(ch){
            case 1: traverseForward(head);
            break;

            case 2: traverseBackward(last);
            break;

            case 3: isEmpty(head);
            break;

            case 4:
            
            printf("enter position for insertion: ");
            scanf("%d",&pos);
            printf("Enter the data to be entered: ");
            scanf("%d",&k);
            head = insertAtPos(head, &last, k, pos);
            printf("~~~ Display ~~~\n");
            display(head);
            break;

            case 5:
            // int pos=0;
            printf("enter position for deletion: ");
            scanf("%d",&pos);
            head = deleteAtPos(head, &last, pos);
            printf("~~~ Display ~~~\n");
            display(head);
            break;

            case 6:
            // int k=0;
            printf("Enter the data to be deleted: ");
            scanf("%d",&k);
            head = deleteFromKey(head, &last, k);
            printf("~~~ Display ~~~\n");
            display(head);
            break;

            case 7:
            printf("No of nodes: %d\n",count);
            break;

            case 8:
            printf("Enter the data to be searched: ");
            scanf("%d",&k);
            (searchKey(head,k))?printf("Found!\n"):printf("Not Found!\n");
            break;

        }
        
        printf("Enter 0 To STOP input: ");
        scanf("%d",&ch);
    }while(ch);

    // display(head);

    
    deleteNode(head);
    remove(argv[0]);
    return 0;
}
