/*Given a linked list which is sorted, WAP to insert an element into the linked list in sorted way.*/
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

struct Node* exec(struct Node* root, int ele){
    struct Node* h=root;
    struct Node* prev=NULL;
    while(h)
    {
        if(h->data > ele){
            break;
        }
        prev=h;
        h=h->next;
    }
    struct Node* t=createNode(ele);
    t->next=h;
    prev->next=t;
    return root;
}

int main(int argc, char const *argv[])
{
    struct Node* head=NULL;
    head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(5);
    head->next->next->next->next=createNode(6);
    head->next->next->next->next->next=createNode(7);
    int ele;
    print(head);
    printf("enter a element to be inserted: ");
    scanf("%d",&ele);

    head=exec(head,ele);
    print(head);

    dealloc(head);
    remove(argv[0]);
    return 0;
}