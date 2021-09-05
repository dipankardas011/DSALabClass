/*A linked list is said to contain a cycle if any node is visited more than once while traversing the list. WAP to detect a cycle in a linked list.*/
// traverse using a fast pointeer and a slow pointer;
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Lab02/LL.h"

bool isCycle(struct Node* head){
    struct Node* slowPtr=head;
    struct Node* fastPtr=head->next;

    
    while(slowPtr != fastPtr){
        if(!slowPtr || !fastPtr)
            return false;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    
    return true;
}

int main(int argc, char const *argv[])
{
    struct Node* head=NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    // head->next->next->next->next=createNode(5);
    head->next->next->next->next = head->next;
    isCycle(head)? printf("Cycle present\n") : printf("No Cycle\n");
    remove(argv[0]);
    return 0;
}
