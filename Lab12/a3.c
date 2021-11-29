/*WAP to create a directed graph using adjacency list method.*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct node{
    int TO;
    struct node *next;
} LL;

typedef struct Node{
    int Vertices;
    LL **arr;
} Graph;

void allocateMemory(int V, Graph* gp){
    gp->Vertices = V;
    gp->arr = (LL **)malloc(sizeof(LL*) * V);
    for (int i = 0; i < V;i++){
        gp->arr[i] = NULL;
    }
}

void displayGraph(Graph gp){
    printf("Connections\n");
    printf("FROM -> TO\n");
    for (int i = 0; i < gp.Vertices; i++)
    {
        LL *temp = gp.arr[i];
        while(temp){
            printf("%d -> %d\n", i, temp->TO);
            temp = temp->next;
        }
    }
    printf("============\n");
}

bool isValid(int i, int j, int v)
{
    if ((i < v && i >= 0) && (j < v && j >= 0))
        return true;
    return false;
}

LL* insert(LL* head, int key){
    LL *newN = (LL *)malloc(sizeof(LL));
    newN->TO = key;
    newN->next = NULL;
    if (!head)
    {
        return newN;
    }
    LL *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newN;
    return head;
}

Graph makeConnection(Graph gp, int from, int to){
    if(!isValid(from, to, gp.Vertices)){
        printf("INV vertices\n");
        return gp;
    }
    else
    {
        gp.arr[from] = insert(gp.arr[from], to);
        return gp;
    }
}

int main(int argc, char const *argv[])
{
    Graph gp;
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    allocateMemory(v, &gp);

    int ch;
    do
    {
        printf("Enter 1 to establish connection\n");
        printf("Enter 2 to display\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &ch);
        int i, j;
        switch (ch)
        {

        case 1:
            printf("Enter the 2 vertices{INSERTION} i.e. FROM TO: ");
            scanf("%d %d", &i, &j);
            gp = makeConnection(gp, i, j);
            break;

        case 2:
            displayGraph(gp);
            break;
        }
    } while (ch);

    remove(argv[0]);
    return 0;
}
