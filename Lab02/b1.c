/*WAP to search an element in a simple linked list, if found delete that node and insert that node at beginning. Otherwise display an appropriate message.*/
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

struct Node* exec(struct Node* h, int ele){
    struct Node* prev=h;
    if(h->data==ele){
        //first element is itself in right place
        return h;
    }
    while(prev->next && prev->next->data!=ele){
        prev=prev->next;
    }
    if(!prev->next){
        fprintf(stderr,"Not present!\n");
        return h;
    }
    struct Node* store = prev->next;
    prev->next=store->next;
    store->next=NULL;

    store->next = h;
    h=store;
    return h;

}

int main(int argc, char const *argv[]){
    struct Node* head=NULL;
    head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    head->next->next->next->next->next=createNode(6);
    int ele;
    print(head);
    printf("enter a element: ");
    scanf("%d",&ele);

    head=exec(head,ele);
    print(head);

    dealloc(head);
    remove(argv[0]);
    return 0;
}