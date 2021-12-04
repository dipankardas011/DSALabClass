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

SLL* sortList(SLL* head){

    SLL* a = NULL;
    SLL* b = NULL;
    if (head== NULL || head->next == NULL) {
        return head;
    }

    SLL *mid = getMid(head);

    a = sortList(head);
    b = sortList(mid);

    return mergeIt(a, b);
}


int main(int argc, char **argv) {
    SLL* head = NULL;
    int ch;
    do{
        printf("[ 1 ] insert\n[ 2 ] display\n[ 3 ] sortit\n[ 0 ] EXIT\n> ");
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
                head = sortList(head);
                break;
            }
        }
    }while(ch);
    remove(argv[0]);
    return EXIT_SUCCESS;
}