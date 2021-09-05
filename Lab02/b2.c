/*WAP to count the number of occurrences of an element in a linked list of n nodes.*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* t=(struct Node* )malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;

    return t;
}

void dealloc(struct Node* ptr){
    // in this case LL
    struct Node* t=0;
    while(ptr){
        t=ptr;
        t=t->next;
        free(ptr);
        ptr=t;
    }
    free(t);
}


void print(struct Node* k){
    do{
        printf("%d ",k->data);
        k=k->next;
    }while(k && printf("->"));
    printf("\n");
}

int occurences(struct Node* t, int data){
    int count=0;
    while(t){
        if(data==t->data){
            count++;
        }
        t=t->next;
    }
    return count;
}

int main(int argc, char const *argv[]){
    struct Node* head=NULL;
    head=createNode(113);
    head->next=createNode(22);
    head->next->next=createNode(324);
    head->next->next->next=createNode(22);
    head->next->next->next->next=createNode(5);
    head->next->next->next->next->next=createNode(1);
    int ele;
    print(head);
    printf("enter a element: ");
    scanf("%d",&ele);

    printf("frequency of {%d} = %d\n",ele,occurences(head,ele));

    dealloc(head);
    remove(argv[0]);
    return 0;
}