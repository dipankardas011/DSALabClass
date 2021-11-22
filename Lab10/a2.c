/**
 * Wap to check weather a cycle exists in a single linked list.
 * Also, edit remove the cycle to make the linked list proper.
 * Use both recursive and non-recursive techniques.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}SLL;

size_t NoOfNodes = 0;

int insert(SLL** head, int key) {
    SLL* newNode = (SLL*)malloc(sizeof(SLL));
    newNode->data = key;
    newNode->next = NULL;
    if (!(*head)) {
        *head = newNode;
        NoOfNodes++;
        return 1;
    }

    SLL* temp = *head;
    while (temp->next && temp->data != key)
        temp = temp->next;
    if (temp->data == key) {
        //then link the last to the temp
        NoOfNodes = NoOfNodes;
        SLL* next = temp;
        while (next->next) {
            next = next->next;
        }
        next->next = temp;

        return 0;// indicating that no more input can be taken
    }
    NoOfNodes++;
    temp->next = newNode;
    return 1;
}

void display(SLL* head) {
    if (!head) {
        printf("Empty!!\n");
        return;
    }

    int noOfIterations = 0;
    do {
        printf("%d ", head->data);
        head = head->next;
        noOfIterations++;
    } while (head && noOfIterations < 10 && printf("-> "));
    printf("\n");
}

// fast and slow pointer
int isCyclePresent(SLL* head) {
    SLL* slow = head;
    SLL* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return 1;
        }
    }
    return 0;
}

void removeCycles(SLL** head) {

    printf("Number of Nodes: %ld\n", NoOfNodes);

    SLL** arr = (SLL**)malloc(sizeof(SLL*)*NoOfNodes);
    for (int i = 0;i < NoOfNodes;i++)
        arr[i] = NULL;

    SLL* iter = *head;
    int iter1 = 0;

    if (iter->next == iter) {
        iter->next = NULL;// head itself
        return;
    }
    while (iter1 < NoOfNodes) {
        arr[iter1] = iter->next;


        if (iter->next == *head) {// connected to the first node
            iter->next = NULL;
            free(arr);
            return;
        }

        for (int j = 0; j < iter1; j++) {// should not check by itself
            if (iter->next == arr[j]) {
                iter->next = NULL;
                free(arr);
                return;// found
            }
        }
        iter = iter->next;
        iter1++;
    }

    free(arr);
    return;
}

int main(int argc, char** argv) {
    SLL* head = NULL;
    int ch;
    int canInput = 1;
    do {
        printf("Enter 0 to exit\n");
        printf("Enter 1 to insert\n");
        printf("Enter 2 to display\n");
        printf("Enter 3 to isCycle\n");
        printf("-> ");
        scanf("%d", &ch);
        int k;

        switch (ch) {
            case 1: {
                if (!canInput) {
                    printf("Can't insert anymore due to cycle\n");
                    break;
                }
                printf("Enter the Key\n");
                scanf("%d", &k);
                canInput = insert(&head, k);
                break;
            }
            case 2: {
                printf("Elements\n");
                // don't use display if in cycle advisible
                display(head);
                break;
            }
            case 3: {
                isCyclePresent(head) ? printf("CYCLE✅\n") : printf("CYCLE❌\n");
                removeCycles(&head);
                canInput = 1;
                break;
            }
        }

    } while (ch);

    remove(argv[0]);
    return EXIT_SUCCESS;
}
