
struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int d)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = d;
    t->next = NULL;
    return t;
}

size_t countNodes(struct Node* h){
    size_t count=0;
    while(h){
        count++;
        h=h->next;
    }
    return count;
}

void display(struct Node *head)
{
    do
    {
        printf("%d", head->data);
        head = head->next;
    } while (head && printf("->"));
    printf("\n");
}

struct Node* insertAtBack(struct Node* h, int data){
    if(!h){
        return createNode(data);
    }

    struct Node* t=h;
    while(t->next)
        t=t->next;
    t->next=createNode(data);
    // t=NULL;
    return h;
}

struct Node* reverseFirstM_Nodes(struct Node* h, int m){
    // assumming the m<n
    struct Node* start=h;
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

void freeHeap(struct Node *h)
{
    struct Node *temp = NULL;
    while (h)
    {
        temp = h;
        temp = temp->next;
        free(h);
        h=temp;
    }
    free(temp);
}

struct Node* reverseLL(struct Node* head){
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next = head;
    while(curr){
        next = next->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

void insertWithHeadLastLL(struct Node **h, struct Node **l, int d)
{
    //insert at back
    if (!*h)
    {
        *h = *l = createNode(d);
        return;
    }

    struct Node *temp = createNode(d);
    (*l)->next = temp;
    (*l) = temp;
    temp = NULL;
    return;
}