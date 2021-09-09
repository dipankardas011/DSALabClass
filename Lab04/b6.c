/*WAP to print the middle of a double linked list.*/
#include <stdio.h>
#include <stdlib.h>
#include "../Lab04/DLL.h"

size_t countNodes(DNode *he){
    if(he)
        return 1+countNodes(he->next);
    return 0;
}

void middleElement(DNode *h){
    size_t c = countNodes(h);
    int k=0;
    k=c/2;
    c=0;
    while(h){
        if(c==k)
        {
            printf("Middle: %d\n",h->data);
            return;
        }
        c++;
        h=h->next;
    }
}

int main(int argc, char const *argv[])
{
    DNode *head = 0;
    head = insertUsr(head, 34);
    head = insertUsr(head, 54);
    head = insertUsr(head, 45);
    head = insertUsr(head, 5);
    head = insertUsr(head, 3);
    display(head);
    middleElement(head);
    deleteNode(head);
    remove(argv[0]);
    return 0;
}
