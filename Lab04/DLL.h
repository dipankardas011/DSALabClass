struct Node{
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int d){
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=d;
    t->next=t->prev=0;
    return t;
}
struct Node* insertUsr(struct Node* head, int k){
    
    if(!head){
        return createNode(k);
    }
    struct Node* t = head;
    while(t->next)  t=t->next;
    t->next = createNode(k);
    t->next->prev = t;

    return head;
}
struct Node* insert(struct Node* head){
    int k;
    printf("Enter data: ");
    scanf("%d",&k);
    
    if(!head){
        return createNode(k);
    }
    struct Node* t = head;
    while(t->next)  t=t->next;
    t->next = createNode(k);
    t->next->prev = t;

    return head;
}

struct Node* display(struct Node* head){
    do{
        printf("%d",head->data);
        head = head->next;
    }while(head && printf("<->"));
    printf("\n");
}

void deleteNode(struct Node* head){
    struct Node* t=0;
    while(head){
        t=head;
        head = head->next;
        free(t);
    }
    free(head);
}