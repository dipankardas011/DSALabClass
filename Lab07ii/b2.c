/*WAP demonstrating bubble sort using linked list.*/
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
    if (!(*head)) {
        *head = createNodes(k);
        return;
    }
    SLL* newNode = createNodes(k);

    // insert according to ascending
    SLL* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
}

SLL* bubbleSort(SLL* head){
    SLL *i = head;
    SLL *j = NULL;

    while(i){
        j = head;

        while(j&& j->next){
            if(j->data > j->next->data){
                int t = j->data;
                j->data = j->next->data;
                j->next->data = t;
            }
            j = j->next;
        }
        i = i->next;
    }
    i = NULL;
    j = NULL;
    return head;
}

int main(int argc, char **argv) {
    SLL *head = NULL;
    int ch;
    do{
        printf("[ 1 ] insert\n");
        printf("[ 2 ] display\n[ 3 ] sort\n> ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                int i;
                printf("Enter the data to insert: ");
                scanf("%d", &i);
                insertNodes(&head, i);
                break;
            }
            case 2:{
                display(head);
                break;
            }
            case 3:{
                head = bubbleSort(head);
            }
        }
    } while (ch);
    remove(argv[0]);
    return EXIT_SUCCESS;
}