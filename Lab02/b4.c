/*WAP to remove duplicates from a linked list of n nodes.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int countNodes(struct Node* t){
    int c=0;
    while(t){
        c++;
        t=t->next;
    }
    return c;
}

bool find(int *a, int S, int search)
{
    for(int i=0;i<S;i++)
        if(a[i]==search)
            return true;

    return false;
}

struct Node* exec(struct Node* root){
    struct Node* h=root;
    int len=countNodes(h);
    int hash[len];
    int pos=0;
    struct Node* prev=0;
    while(h)
    {
        printf("%d\n",h->data);
        if(find(hash,pos,h->data)){
            //found && delete
            struct Node* curr = h;
            prev->next = h->next;
            h=h->next;
            free(curr);
        }else{
            //insert it
            hash[pos++]=h->data;
            prev=h;
            h=h->next;
        }
        
    }
    return root;
}

int main(int argc, char const *argv[]){
    struct Node* head=NULL;
    head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(2);
    head->next->next->next->next=createNode(5);
    head->next->next->next->next->next=createNode(3);

    print(head);
    

    head=exec(head);
    print(head);

    dealloc(head);
    remove(argv[0]);
    return 0;
}