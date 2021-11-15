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


int insert(SLL** head, int key) {
    SLL* newNode = (SLL*)malloc(sizeof(SLL));
    newNode->data = key;
    newNode->next = NULL;
    if (!(*head)) {
        *head = newNode;
        return 1;
    }

    SLL* temp = *head;
    while (temp->next && temp->data != key)
        temp = temp->next;
    if (temp->data == key) {
        //then link the last to the temp
        SLL* next = temp;
        while (next->next) {
            next = next->next;
        }
        next->next = temp;

        return 0;// indicating that no more input can be taken
    }
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
    while (fast && fast->next && slow) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return 1;
        }
    }
    return 0;
}

SLL* CyclePresentRet(SLL* head) {
    SLL* slow = head;
    SLL* fast = head->next;
    while (fast && fast->next && slow) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return slow;
        }
    }
    return NULL;
}

void removeCycles(SLL** head) {
    SLL* cycleNode = CyclePresentRet(*head);
    if (!cycleNode) {
        // no more cycle to be found
        return;
    }
    printf("cycle node: %d\n", cycleNode->data);
    SLL* cycleTemp = cycleNode->next;
    while (cycleTemp->next->data != cycleNode->data) {
        printf("loop %d\n", cycleTemp->data);
        cycleTemp = cycleTemp->next;
    }
    cycleTemp->next = NULL;
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

    // deleteSLL(head);
    remove(argv[0]);
    return EXIT_SUCCESS;
}

void removeLoop(SLL*, SLL*);
 
/* This function detects and removes loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectAndRemoveLoop(SLL* list)
{
    SLL *slow_p = list, *fast_p = list;
 
    // Iterate and find if loop exists or not
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet at some point then there
           is a loop */
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);
 
            /* Return 1 to indicate that loop is found */
            return 1;
        }
    }
 
    /* Return 0 to indicate that there is no loop*/
    return 0;
}
 
/* Function to remove loop.
 loop_node --> Pointer to one of the loop nodes
 head -->  Pointer to the start node of the linked list */
void removeLoop(SLL* loop_node, SLL* head)
{
    SLL* ptr1 = loop_node;
    SLL* ptr2 = loop_node;
 
    // Count the number of nodes in loop
    unsigned int k = 1, i;
    while (ptr1->next != ptr2) {
        ptr1 = ptr1->next;
        k++;
    }
 
    // Fix one pointer to head
    ptr1 = head;
 
    // And the other pointer to k nodes after head
    ptr2 = head;
    for (i = 0; i < k; i++)
        ptr2 = ptr2->next;
 
    /*  Move both pointers at the same pace,
      they will meet at loop starting node */
    while (ptr2 != ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
 
    // Get pointer to the last node
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
 
    /* Set the next node of the loop ending node
      to fix the loop */
    ptr2->next = NULL;
}