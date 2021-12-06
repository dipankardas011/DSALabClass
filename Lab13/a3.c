/*binary search in linklist*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct n{
    int data;
    struct n* next;
}SLL;

SLL* createNodes(int k){
    SLL* t=(SLL*)malloc(sizeof(SLL));
    t->data = k;
    t->next = NULL;
    return t;
}

void display(SLL* head){
    if(!head){
        printf("Empty!\n");
        return;
    }

    do{
        printf("%d",head->data);
        head=head->next;
    }while(head && printf(" -> "));
    printf("\n");
}

void insertNodes(SLL** head, int k){
    if (!(*head)) {
        *head = createNodes(k);
        return;
    }
    SLL* newNode = createNodes(k);

    // insert according to ascending
    SLL* temp = *head;
    SLL* prev = NULL;
    while (temp && temp->data < newNode->data) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        // insert at back
        prev->next = newNode;
        return;
    }
    if (prev == NULL) {
        // insert at first
        newNode->next = *head;
        *head = newNode;
        return;
    }
    newNode->next = temp;
    prev->next = newNode;
}

int noOfNodes(SLL* head, SLL* end){
    if(!head || !end){
        return 0;
    }
    if(head == end)
        return 1;

    return 1 + noOfNodes(head->next, end);
}

SLL* getMidNode(SLL* start, SLL* end){
    int count = noOfNodes(start, end);
    count = count / 2;
    int pos = 0;
    while(pos < count-1 && start!=end){
        start = start->next;
    }
    return start;
}

SLL* getMid(SLL* start, SLL* last)
{
    if (start == NULL)
        return NULL;
 
    SLL* slow = start;
    SLL* fast = start -> next;
 
    while (fast != last) {
        fast = fast -> next;
        if (fast != last) {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
 
    return slow;
}

bool binarySearch(SLL* head, int key ,SLL* start, SLL* end){

    if(end && start==end){
        return false;
    }

    SLL* midNode = getMid(start, end);
    if(!midNode){
        return false;
    }
    if(midNode->data > key)// left side present
        return binarySearch(head, key, start, midNode);

    else if(midNode->data < key)// right side present
        return binarySearch(head, key, midNode->next, end);
    
    else  // found
        return true;
}


bool findKey(SLL* head, int searchKey){
    SLL *start = head;
    SLL *end = NULL;
    return binarySearch(head, searchKey, start, end);
}

int main(int argc, char **argv) {
    SLL *head = NULL;
    int ch;
    do{
        printf("[ 1 ] insertKey\n[ 2 ] display\n[ 3 ] findKey\n> ");
        scanf("%d", &ch);
        int key;
        switch(ch){
            case 1:{
                printf("enter the key: ");
                scanf("%d", &key);
                insertNodes(&head, key);
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 3:{
                printf("enter the key: ");
                scanf("%d", &key);
                bool val = findKey(head, key);
                val ? printf("Found!\n") : printf("No Found\n");
                break;
            }
        }
    } while (ch);
    remove(argv[0]);
    return EXIT_SUCCESS;
}