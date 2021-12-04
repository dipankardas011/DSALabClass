/*
Linklist in merge sort, quick sort
*/
#include <stdio.h>
#include <stdlib.h>

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
    if(!(*head)){
        *head = createNodes(k);
        return ;
    }

    SLL* iter = *head;
    while(iter->next)
        iter = iter->next;

    iter->next = createNodes(k);
    return;
}



SLL* mergeIt(SLL* a, SLL* b) {
    SLL* temp = NULL;

    if (a == NULL)// means that a is empty so insert reset of the b
        return b;

    if (b == NULL)
        return a;

    if (a->data < b->data) {
        // insert a
        temp = a;
        temp->next = mergeIt(a->next, b);
    } else {
        // insert b
        temp = b;
        temp->next = mergeIt(a, b->next);
    }

    return temp;
}

SLL* getMid(SLL* head) {
    SLL* midPrev = NULL;
    while (head && head->next) {
        midPrev = (midPrev == NULL) ? head : midPrev->next;
        head = head->next->next;
    }
    SLL* mid = midPrev->next;
    midPrev->next = NULL;
    return mid;
}

SLL* mergeSort(SLL* head){

    SLL* a = NULL;
    SLL* b = NULL;
    if (head== NULL || head->next == NULL) {
        return head;
    }

    SLL *mid = getMid(head);

    a = mergeSort(head);
    b = mergeSort(mid);

    return mergeIt(a, b);
}



// here we are taking the pivot as the last node
SLL* lastNode(SLL* node){
    if(!node)
        return NULL;

    while(node->next){
        node = node->next;
    }

    return node;
}

SLL* partition(SLL* head, SLL* end, SLL** newHead, SLL** newEnd)
{
    SLL* pivot = end;
    SLL *prev = NULL, *cur = head, *tail = pivot;
 
    // During partition, both the head and end of the list might change which is updated in the newHead and newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the pivot - becomes the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;
            cur = cur->next;
        }
        else
        {
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            SLL* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the current list, pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    return pivot;
}
 

SLL* quick(SLL* head, SLL* end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    SLL *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be updated by the partition function
    SLL* pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        SLL* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quick(newHead, tmp);
 
        // Change next of last node of the left half to
        // pivot
        tmp = lastNode(newHead);
        tmp->next = pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quick(pivot->next, newEnd);
 
    return newHead;
}

SLL* quickSort(SLL* head){
    return quick(head, lastNode(head));
}


int main(int argc, char **argv) {
    SLL* head = NULL;
    int ch;
    do{
        printf("[ 1 ] insert\n[ 2 ] display\n[ 3 ] sortit{Merge sort}\n[ 4 ] sortit{QuickSort}\n[ 0 ] EXIT\n> ");
        scanf("%d",&ch);
        int k;
        switch(ch){
            case 1:{
                printf("enter the key to insert: ");
                scanf("%d",&k);
                insertNodes(&head, k);
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 3:{
                head = mergeSort(head);
                break;
            }
            case 4:{
                head = quickSort(head);
                break;
            }
        }
    }while(ch);
    remove(argv[0]);
    return EXIT_SUCCESS;
}