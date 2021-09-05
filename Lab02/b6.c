/*WAP to find number of occurrences of all elements in a linked list.*/
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

void exec(struct Node* root){

    struct Node* t=root;
    int max=t->data;
    while(t){
        if(max<t->data)
            max=t->data;
        t=t->next;
    }
    int freq[max+1];
    for(int i=0;i<=max;i++) freq[i]=0;

    for(int i=0;i<=max;i++)
    {
        t=root;
        while(t){
            if(t->data==i)
                freq[i]++;
            t=t->next;
        }
    }
    for(int i=0;i<=max;i++)
    {
        if(freq[i]){
            printf("%d : %d\n",i,freq[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    struct Node* head=NULL;
    head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(2);
    head->next->next->next=createNode(5);
    head->next->next->next->next=createNode(6);
    head->next->next->next->next->next=createNode(7);
    print(head);

    exec(head);

    dealloc(head);
    remove(argv[0]);
    return 0;
}