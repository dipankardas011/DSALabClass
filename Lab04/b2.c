/*Write a menu driven program to perform the following operations in a single circular linked list by using suitable user defined functions for each case.
    * Traverse the list 
    * Check if the list is empty 
    * Insert a node at the certain position
    * Delete a node at the certain position 
    * Delete a node for the given key
    * Count the total number of nodes 
    * Search for an element in the linked list
Verify & validate each function from main method.*/
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;
int count=0;
Node* tail=0;

Node* createNode(int d){
    Node *t=(Node*)malloc(sizeof(Node));
    t->data=d;
    t->next=NULL;
    return t;
}

void isEmpty(Node* head){
    if(!(head))   printf("Empty!\n");
    else    printf("No Empty!\n");
}
/***
 * @p all the corner cases are covered
 */
void insertAtPos(Node **head, int position)
{
    if(count+1 < position)
    {
        fprintf(stderr, "INV position\n");
        return;
    }
    int k;
    printf("Enter the data: ");
    scanf("%d",&k);
    Node *temp = createNode(k);
    if(position==1){
        if(!(*head)){
            // no head
            temp->next = temp;
            *head = tail = temp;
            count++;
            return;
        }
        temp->next = *head;
        tail->next = temp;
        *head = temp;
        count++;
        return;
    }
    if(count+1 == position){
        //last
        tail->next = temp;
        // temp->prev = tail;
        temp->next = *head;
        tail = temp;
        count++;
        return;
    }
    Node* t = *head;
    int c=0;
    do{
        c++;
        if(c+1==position)
            break;
        t=t->next;
    }while(t!=*head);

    temp->next = t->next;
    t->next = temp;
    count++;
    return ;
}

void deleteAtPos(Node **head, int position){
    if(count<position){
        fprintf(stderr, "INV position!\n");
        return;
    }
    if(!(*head)){
        fprintf(stderr, "Empty!\n");
        return;
    }
    Node* t=0;
    if(position==1){
        if((*head)->next==(*head)){
            free(*head);
            *head=NULL;
            return;
        }
        t=*head;
        *head = (*head)->next;
        // (*head)->prev = 0;
        tail->next = *head;
        free(t);
        count--;
        return;
    }
    if(count==position){
        // t=tail;
        t=*head;
        while(t->next!= tail){
            t=t->next;
        }
        Node*ff=t->next;
        t->next = *head;
        tail = t;
        count--;
        free(ff);
        return;
    }

    int c=0;
    t=*head;
    do{
        c++;
        if(c+1==position) break;
        t=t->next;
    }while(t!=*head);
    count--;
    Node* k = t->next;
    t->next = t->next->next;
    free(k);
    return;
}

int search(Node **head, int f){
    if(!*head)
        return 0;
    Node *t=*head;
    do{
        if(t->data == f)
            return 1;
        t=t->next;
    }while(t!=*head);
    return 0;
}

void deleteFromKey(Node **head, int key){
    if(!search(head, key)){
        fprintf(stderr, "Element not there\n");
        return;
    }
    Node *t=*head;

    if(t->data == key){
        //delete from beginning
        if((*head)->next==(*head)){
            free(*head);
            *head=NULL;
            return;
        }
        // t=*head;
        *head = (*head)->next;
        // (*head)->prev = 0;
        tail->next = *head;
        free(t);
        count--;
        return;
    }

    while(t->next->next!=*head){
        if(t->next->data == key)
            break;
        t=t->next;
    }

    Node *ff=t->next;


    if(t->next->next == *head){
        // end
        t->next = *head;
        tail = t;
        count--;
        free(ff);
        return;
    }

    t->next = t->next->next;
    free(ff);
    return;


}

void display(Node* head){
    if(!head)
    {
        fprintf(stderr, "Empty\n");
        return;
    }
    Node* t=head;
    do{
        printf("%d",t->data);
        t=t->next;
    }while(t!=head && printf("->"));
    printf("=>%d\n",head->data);
}

void deleteNode(Node **head){
    Node* t = *head;
    do{
        *head = (*head)->next;
        free(t);
        t = *head;
    }while(*head != t);
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    int ch;
    do{
        printf("\t1->Traverse the list \n");
        printf("\t2->Check if the list is empty \n");
        printf("\t3->Insert a node at the certain position\n");
        printf("\t4->Delete a node at the certain position \n");
        printf("\t5->Delete a node for the given key\n");
        printf("\t6->Count the total number of nodes \n");
        printf("\t7->Search for an element in the linked list\n");
        printf("\t-> ");
        scanf("%d",&ch);
        int pos, key;
        switch(ch){
            case 1:display(head);
            break;

            case 2:isEmpty(head);
            break;

            case 3:
            printf("enter the position where to insert: ");
            scanf("%d",&pos);
            insertAtPos(&head, pos);
            break;

            case 4:
            printf("enter the position where to delete: ");
            scanf("%d",&pos);
            deleteAtPos(&head, pos);
            break;

            case 5:
            printf("Enter the element to delete: ");
            scanf("%d",&key);
            deleteFromKey(&head,key);
            break;

            case 6:printf("No. of nodes: %d\n",count);
            break;

            case 7:
            printf("Enter the element to be searched: ");
            scanf("%d",&key);
            (search(&head,key))?printf("Found!\n"):printf("Not Found!\n");
            break;
        }

        printf("Enter 0 to STOP: ");
        scanf("%d",&ch);
    }while(ch);
    getchar();
    system("clear");
    remove(argv[0]);
    return 0;
}
