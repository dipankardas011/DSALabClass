/** wap to take n number of data values from the user 
 * each data value has 3 parts 
 * i) amount
 * ii) quantity
 * iii) unit price
 * ask user to enter N number of data values and store it in a linklist
 * user shall enter the amount and the quantity then unit price has to be calculated
 * in the program
 * insert , delete, display, sort {using unit price}
 * implemente it using double linklist
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    float amount;
    int qty;
    float unitPrice;

    struct node* next, * prev;
} DLL;

DLL* createMemory(float a, int q) {
    DLL* t = (DLL*)malloc(sizeof(DLL));
    t->amount = a;
    t->qty = q;
    t->unitPrice = a / q;

    t->prev = t->next = NULL;

    return t;
}

void insert(DLL** head, float a, int q) {
    if (!(*head)) {
        *head = createMemory(a, q);
        return;
    }
    DLL* newNode = createMemory(a, q);

    /* insert according to ascending
    DLL* temp = *head;
    DLL* prev = NULL;
    while (temp && temp->unitPrice < newNode->unitPrice) {
        prev = temp;
        temp = temp->next;
    }

    // here temp>newNode
    // printf("%p\n", temp);
    if (!temp) {
        // insert at back
        prev->next = newNode;
        newNode->prev = prev;
        return;
    }
    if (prev == NULL) {
        // insert at first
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    newNode->next = temp;
    newNode->prev = prev;
    prev->next = newNode;
    temp->prev = newNode;
*/
    DLL* temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void display(DLL* head) {
    if (!head) {
        printf("Empty!!\n");
        return;
    }

    do {
        printf("|%.3f, %d, %.3f| ", head->amount, head->qty, head->unitPrice);
        head = head->next;
    } while (head && printf("<-> "));
    printf("\n");
}

void deleteNode(DLL** head, float unitPriceTodel) {
    // assume that it is there
    DLL* temp = *head;
    while (temp && temp->unitPrice != unitPriceTodel) {
        temp = temp->next;
    }
    DLL* ff = NULL;
    if (!temp) {
        // not present;
        printf("Not present\n");
        return;
    }
    if (!(temp->prev)) {
        // del first
        ff = temp;
        temp = temp->next;
        *head = temp;
        free(ff);
        return;
    }
    if (!(temp->next)) {
        //del last
        ff = temp;
        temp->prev->next = NULL;
        free(ff);
        return;
        
    }

    ff = temp;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(ff);
}

void deleteDLL(DLL* head) {
    if (head) {
        deleteDLL(head->next);
        // printf("DEBUG: DEL\n");
        free(head);
    }
}

DLL* mergeIt(DLL* a, DLL* b) {
    DLL* temp = NULL;

    if (a == NULL)// means that a is empty so insert reset of the b
        return b;

    if (b == NULL)
        return a;

    if (a->unitPrice < b->unitPrice) { //ascending
        // insert a
        temp = a;
        temp->next = mergeIt(a->next, b);
        // if (temp) {
        //     temp->next->prev = temp;
        // }
        // else {
        //     temp->next->prev = NULL;
        // }
        temp->next->prev = temp == NULL ? NULL : temp;
    }
    else {
        // insert b
        temp = b;
        temp->next = mergeIt(a, b->next);
        // if (temp) {
        //     temp->next->prev = temp;
        // }
        // else {
        //     temp->next->prev = NULL;
        // }
        temp->next->prev = temp == NULL ? NULL : temp;
    }

    return temp;
}

DLL* getMid(DLL* head) {
    DLL* midPrev = NULL;
    while (head && head->next) {
        midPrev = (midPrev == NULL) ? head : midPrev->next;
        head = head->next->next;
    }
    DLL* mid = midPrev->next;
    midPrev->next = NULL;
    return mid;
}

DLL* sortList(DLL* head){

    DLL* a = NULL;
    DLL* b = NULL;
    if (head== NULL || head->next == NULL) {
        return head;
    }

    DLL *mid = getMid(head);

    a = sortList(head);
    b = sortList(mid);

    return mergeIt(a, b);
}


int main(int argc, char** argv) {
    DLL* head = 0;

    int ch;
    do {
        printf("Enter 0 to exit\n");
        printf("Enter 1 to insert\n");
        printf("Enter 2 to display\n");
        printf("Enter 3 to delete\n");
        printf("Enter 4 to sortItDesc\n");
        printf("-> ");
        scanf("%d", &ch);
        float a;
        int q;

        switch (ch) {
            case 1: {
                printf("Enter the amount & quantity\n");
                scanf("%f %d", &a, & q);
                insert(&head, a, q);
                break;
            }
            case 2:{
                printf("Elements\n");
                display(head);
                break;
            }
            case 3: {
                printf("Enter the unitPrice to delete\n");
                scanf("%f", &a);
                deleteNode(&head, a);
                break;
            }
            case 4: {
                head = sortList(head);
                break;
            }
        }

    } while (ch);

    deleteDLL(head);

    remove(argv[0]);
    return EXIT_SUCCESS;
}