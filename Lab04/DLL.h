typedef struct Node{
    int data;
    struct Node *prev, *next;
}DNode;

DNode* createNode(int d){
    DNode *t=(DNode*)malloc(sizeof(DNode));
    t->data=d;
    t->next=t->prev=0;
    return t;
}
DNode* insertUsr(DNode* head, int k){
    
    if(!head){
        return createNode(k);
    }
    DNode* t = head;
    while(t->next)  t=t->next;
    t->next = createNode(k);
    t->next->prev = t;

    return head;
}
DNode* insert(DNode* head){
    int k;
    printf("Enter data: ");
    scanf("%d",&k);
    
    if(!head){
        return createNode(k);
    }
    DNode* t = head;
    while(t->next)  t=t->next;
    t->next = createNode(k);
    t->next->prev = t;

    return head;
}

DNode* display(DNode* head){
    do{
        printf("%d",head->data);
        head = head->next;
    }while(head && printf("<->"));
    printf("\n");
}

void deleteNode(DNode* head){
    DNode* t=0;
    while(head){
        t=head;
        head = head->next;
        free(t);
    }
    free(head);
}