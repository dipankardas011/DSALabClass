/*WAP to reverse the first m elements of a linked list of n nodes.*/
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


struct Node* exec(struct Node* h, int m){
    // assumming the m<n
    struct Node* start=h;
    //savingthe1asitwillbethelasttobeconnected
    struct Node* curr=h;
    struct Node* prev=NULL;
    struct Node* next=h;
    while(m-- && curr){
        next=next->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    start->next = next;
    return prev;
}

int main(int argc, char const *argv[]){
    struct Node* head=NULL;
    head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    head->next->next->next->next->next=createNode(6);
    int m;
    print(head);
    printf("enter a element: ");
    scanf("%d",&m);

    head=exec(head,m);
    print(head);

    dealloc(head);
    remove(argv[0]);
    return 0;
}