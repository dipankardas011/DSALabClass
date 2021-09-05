/*Given a linked list, write a function to reverse every k nodes. (where k is an input to the function). If a linked list is given as 12->23->45->89->15->67->28->98->NULL and k = 3 then output will be 45->23->12->67->15->89->98->28->NULL.*/
#include <stdio.h>
#include <stdlib.h>
#include "../Lab02/LL.h"


struct Node *reverseEveryK_Nodes(struct Node *, int);

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    head = insertAtBack(head, 12);
    head = insertAtBack(head, 23);
    head = insertAtBack(head, 45);
    head = insertAtBack(head, 89);
    head = insertAtBack(head, 15);
    head = insertAtBack(head, 67);
    head = insertAtBack(head, 28);
    head = insertAtBack(head, 98);

    display(head);

    head = reverseEveryK_Nodes(head, 3);

    display(head);

    remove(argv[0]);
    return 0;
}

/***
 * @author      Dipankar Das
 * @version     %I%, %G%
 * @since       1.0
 * @param k k number of nodes to reverse
 * @param head to get the starting addr. for the singly link list
 */
struct Node *reverseEveryK_Nodes(struct Node *head, int k)
{
    /***
     * @param t it marks the start of every subnode
     * @param prevt marks the previous node of the t (trailing pointer)
     * @param end it is the end of the subnode
     * @param last it marks the next for the end of the subnode i.e. last = end->next; (next pointer)
     */
    size_t size = countNodes(head);
    struct Node *t = head;
    struct Node *prevt = NULL;
    for (size_t i = 0; i < size; i += k)
    {
        // reverse the halfs
        int K = k;
        /***
         * @param prev stores the prev node's addr.
         * @param curr stores the curr node's addr.
         * @param next stores the next node's addr; 
         */
        struct Node *last = t,
                    *end = t,
                    *prev = NULL,
                    *curr = NULL,
                    *next = NULL;
        while (last && K--)
        {
            end = last;
            last = last->next;
        }
        if (t == head)
        {
            // printf("start: %d\tend: %d\n",t->data, end->data);
            prev = last;
            curr = t;
            next = t;

            while (curr != end)
            {
                next = next->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            curr->next = prev;
            head = curr;

            // update the prevt to the t for the next iteration
            prevt = t;
            // update the t to the next
            t = last;
            // display(head);
            
        }
        else if (last == NULL)
        {
            // printf("start: %d\tend: %d\n",t->data, end->data);
            prev = NULL;
            curr = t;
            next = t;

            while (curr != end)
            {
                next = next->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            curr->next = prev;
            prevt->next = curr;
            // stoping further iteration as we are in the last subnode
            prevt = NULL;
            t=NULL;//it's the last so stop the iteration
            // display(head);
            
        }
        else
        {
            // printf("start: %d\tend: %d\n",t->data, end->data);
            prev = last;
            curr = t;
            next = t;

            while (curr != end)
            {
                next = next->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            curr->next = prev;
            prevt->next = curr;
            // update the prevt to the t for the next iteration
            prevt = t;
            // update the t to the next
            t=last;
            // display(head);
        }
    }
    prevt = NULL;
    t=NULL;
    free(t);
    free(prevt);

    return head;
}
