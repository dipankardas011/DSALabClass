/*Design algorithm write C code to delete all duplicate nodes from a doubly circular linked list.*/
#include <stdio.h>
#include <stdlib.h>

// doubly LL
typedef struct node
{
  int data;
  struct node *prev;
  struct node *next;
} DLL;

DLL *allocateMemory(int k)
{
  DLL *t = (DLL *)malloc(sizeof(DLL));
  t->data = k;
  t->prev = NULL;
  t->next = NULL;
  return t;
}

DLL *insert(DLL *h, int k)
{
  DLL *t = allocateMemory(k);
  if (!h)
  {
    t->next = t->prev = t;
    h = t;
    return h;
  }

  DLL *iter = h->prev;
  t->next = h;
  t->prev = iter;
  iter->next = t;
  h->prev = t;
  return h;
}

void display(DLL *h)
{
  if (!h)
  {
    printf("Empty!\n");
    return;
  }
  printf("| prev | data | next |\n");
  DLL *iter = h;
  do
  {
    printf("Its address: { %p }\n", iter);
    printf("| %p | %d | %p |\n\n", iter->prev, iter->data, iter->next);
    iter = iter->next;
  } while (iter != h);
}

void deallocateMemory(DLL *head, DLL *iter)
{
  if (!head)
  {
    return;
  }
  if (iter != head)
  {
    return;
  }

  deallocateMemory(head, iter->next);
  printf("DELETION of key{%d}\n", iter->data);
  free(iter);
}

DLL *removeDuplicates(DLL *head)
{
  // we move on
  // one by one
  // if we get that data is already in our history then skip it i.e.
  // free it and link the next to its next
}

int main(int argc, char **argv)
{
  DLL *head = NULL;
  int ch;
  do
  {
    printf("Your choices\n");
    printf("[ 1 ] insertion\n");
    printf("[ 2 ] display\n");
    printf("[ 0 ] EXIT\n");
    printf("> ");
    scanf("%d", &ch);
    int k;
    switch (ch)
    {
    case 1:
    {
      printf("Enter the key to insert: ");
      scanf("%d", &k);
      head = insert(head, k);
      break;
    }
    case 2:
    {
      printf("DISPLAY\n");
      display(head);
      break;
    }
    }
  } while (ch);

  deallocateMemory(head, head->next);
  printf("✅\n");
  remove(argv[0]);
  return EXIT_SUCCESS;
}