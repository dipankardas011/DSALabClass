/*
wap tp have a menu driven priority queue as per users choosen
1-> insertion
2->deletion
3->traversal
4->display*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    int priority;
    struct node *next;
}Pqueue;

void insertion (Pqueue **start, int priority, int data) {
    Pqueue *temp = (Pqueue*)malloc(sizeof(Pqueue));

    temp->data = data;
    temp->priority = priority;
    temp->next=NULL;

    // now find the position
    if(!(*start)) {
        *start = temp;
        return ;
    }

    if ((*start)->priority > priority) {
        temp->next = *start;
        *start = temp;
        return;
    }

    // fond the place
    Pqueue *iter = *start;

    while (iter->next!= NULL && iter->next->priority < priority) {
        iter = iter->next;
    }

    if (iter->next == NULL){
        // inside the last node
        iter->next = temp;
        return;
    }

    // between the last and front
    temp->next = iter->next;
    iter->next = temp;

    temp=NULL;
}

void delete(Pqueue **start, int data) {
    Pqueue *ff =  0;
    if((*start)->data == data) {
        // first node to be deleted
        ff = *start;
        *start = (*start)->next;
        free(ff);
        return;
    }

    Pqueue *iter = *start;
    while (iter->next!=NULL && iter->next->data != data){
        iter = iter->next;
    }
    if (!iter->next) {
            fprintf(stderr, "## Not found!!\n");
            return;
    }

    ff = iter->next;
    iter->next = iter->next->next;
    free(ff);

}
/**
 * @param iter takes the start
 * @param priority priority
 * @param data data
 * @param isInsertion has insertion called it OR deletion
 * @return returns the Pqueue* address to the iter->next;
 * @bug if we pass the double pointer to *iter and then it gets passed to the called function
 * it gets corrupted
 * @look to it
 */

Pqueue* traverse(Pqueue *iter, int priority, int data, bool isInsertion) {

    if(isInsertion)
    {
        while (iter->next!= NULL && iter->next->priority < priority) {
            iter = iter->next;
        }
        return iter->next;
    } else{
        while (iter->next!=NULL && iter->next->data != data){
            // prev = iter;
            iter = iter->next;
        }
        return iter->next;
    }
}

void display(Pqueue *start) {
    if (!(start)) {
        fprintf(stderr, "Empty queue\n");
        return;
    }
    do {
        printf("|%d|%d|",start->data,start->priority);
        start = start->next;
    }while(start!=NULL && printf(" -> "));
    printf("\n");
}


int main(int argc, char **argv) {
    Pqueue *head = NULL;
    int ch;
    do {
        printf("Choices:\n");
        printf(" 1-> Insertion\n");
        printf(" 2-> Deletion\n");
        printf(" 3-> Display\n");
        printf(" 0-> EXIT\n");
        printf(" > ");
        ch=0;
        scanf("%d",&ch);
        int data;
        int pp;
        switch(ch) {
            case 1:
            printf("Enter the data and priority to be inserted\n");
            scanf("%d %d",&data, &pp);
            insertion(&head,pp,data);
            break;

            case 2:
            printf("Enter the data to be deleted\n");
            scanf("%d",&data);
            delete(&head, data);
            break;

            case 3:
            display(head);
            break;

        }
    }while(ch!=0);
    remove(argv[0]);
    return EXIT_SUCCESS;
}