/*Implement a dynamic array of size n. Each element in the array is the
root pointer to an individual header linked list. The header node has the
information about a unique Linked_List_ID and number of nodes in that linked list.
Write code to insert and remove nodes from the lists as per user entered value and
Linked_List_ID. Also, write a function which arranger all the pointers in the array
as per the increasing number of nodes in its linked list.

HINT: Header LL*/
#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
  int data;
  struct Node* next;
}LL;

typedef struct HeadPointer {
  int ID;
  int NoOfnodes;

  LL* head;
}Header;

Header* allocateHeader(int ID) {
  Header* t = (Header*)malloc(sizeof(Header));
  t->ID = ID;
  t->head = NULL;
  t->NoOfnodes = 0;
  return t;
}

LL* allocateLL(int data) {
  LL* t = (LL*)malloc(sizeof(LL));
  t->data = data;
  t->next = NULL;
  return t;
}



void deallocateArr(Header** arr, size_t size) {}

void insertNode(Header** arr, int size, int data, int ID) {
  int i;
  for (i = 0;i < size;i++)
    if (arr[i]->ID == ID)
      break;

  if (i == size) {
    printf("INVALID ID\n");
    return;
  }

  if (arr[i]->head == NULL) {
    arr[i]->head = allocateLL(data);
    (arr[i]->NoOfnodes)++;
    return;
  }

  LL* temp = arr[i]->head;

  while (temp->next) {
    temp = temp->next;
  }
  temp->next = allocateLL(data);
  (arr[i]->NoOfnodes)++;
}

void display(Header** arr, int size) {
  if (!arr) {
    return;
  }

  for (int i = 0;i < size;i++) {
    printf("{ %d [%d] :", arr[i]->ID, arr[i]->NoOfnodes);
    LL* temp = arr[i]->head;
    if (!temp) {
      printf("NULL}\n");
      continue;
    }
    do {
      printf("%d", temp->data);
      temp = temp->next;
    } while (temp && printf(", "));
    printf("}\n");
  }
}

void deleteNode(Header** arr, int size, int data, int ID) {
  int i;
  for (i = 0;i < size;i++)
    if (arr[i]->ID == ID)
      break;

  if (i == size) {
    printf("INVALID ID\n");
    return;
  }

  

  if (arr[i]->head == NULL) {
    printf("Already empty\n");
    return;
  }

  LL* temp = arr[i]->head;
  if (temp->data == data) {
    LL* ff = temp;
    temp = temp->next;
    arr[i]->head = temp;
    (arr[i]->NoOfnodes)--;
    free(ff);
    return;
  }

  while (temp->next && temp->next->data != data) {
    temp = temp->next;
  }

  if (temp->next == NULL) {
    printf("Not there\n");
    return;
  }

  LL* ff = NULL;
  ff = temp->next;
  temp->next = ff->next;
  (arr[i]->NoOfnodes)--;
  free(ff);
}

void arranger(Header** arr, int size) {
  for (int i = 0;i < size;i++) {
    for (int j = 0;j < size - i-1;j++) {
      if (arr[j]->NoOfnodes > arr[j + 1]->NoOfnodes) {
        /// swap
        Header* t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
      }
    }
  }
}

int main(int argc, char **argv) {
  Header** arr = NULL;
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  arr = (Header**)malloc(sizeof(Header*) * n);
  for (int i = 0; i < n; i++) {
    arr[i] = allocateHeader(i+5);// allocating memory for the header LL
  }

  int ch = 0;
  do {
    printf("Enter 1 > insert\n");
    printf("Enter 2 > delete\n");
    printf("Enter 3 > display\n");
    printf("Enter 4 > arranger\n");
    printf("Enter 0 > exit\n");
    printf("> ");
    int k, id;
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("Enter the ID and the data to be inserted: ");
      scanf("%d %d", &id, &k);
      insertNode(arr, n, k, id);
      break;

    case 2:
      printf("Enter the ID and the data to be deleted: ");
      scanf("%d %d", &id, &k);
      deleteNode(arr, n, k, id);
      break;

    case 3:
      display(arr, n);
      break;
    
    case 4:
      arranger(arr, n);
      break;
    }
  } while (ch);

  remove(argv[0]);
  return EXIT_SUCCESS;
}