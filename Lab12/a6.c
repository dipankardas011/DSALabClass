/*Write a menu driven program to create an un-directed graph using Adjacency List Method and perform graph traversal operations.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../CustomDS/QueueI.h"

typedef struct node1
{
    int TO;
    struct node1 *next;
} LL;

typedef struct Node
{
    int Vertices;
    LL **arr;
} Graph;

void allocateMemory(int V, Graph *gp)
{
    gp->Vertices = V;
    gp->arr = (LL **)malloc(sizeof(LL *) * V);
    for (int i = 0; i < V; i++)
    {
        gp->arr[i] = NULL;
    }
}

void displayGraph(Graph gp)
{
    printf("Connections\n");
    printf("FROM -> TO\n");
    for (int i = 0; i < gp.Vertices; i++)
    {
        LL *temp = gp.arr[i];
        while (temp)
        {
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

LL *insert(LL *head, int key)
{
    LL *newN = (LL *)malloc(sizeof(LL));
    newN->TO = key;
    newN->next = NULL;
    if (!head)
    {
        return newN;
    }
    LL *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newN;
    return head;
}

Graph makeConnection(Graph gp, int from, int to)
{
    if (!isValid(from, to, gp.Vertices))
    {
        printf("INV vertices\n");
        return gp;
    }
    else
    {
        gp.arr[from] = insert(gp.arr[from], to);
        gp.arr[to] = insert(gp.arr[to], from);
        return gp;
    }
}

void DFS(Graph gp, int s, bool *visited)
{
    visited[s] = true;
    LL *t = gp.arr[s];
    printf("%d ", s);
    while (t)
    {
        if (!visited[t->TO])
        {
            DFS(gp, t->TO, visited);
        }
        t = t->next;
    }
}


void BFS(Graph gp, int startVertice)
{
    bool *visited = (bool *)malloc(sizeof(bool) * gp.Vertices);

    for (int i = 0; i < gp.Vertices; i++)
        visited[i] = false;

    Queue queue;
    queue.front = queue.rear = -1;

    push(&queue, startVertice);
    visited[startVertice] = true;

    while (!isEmpty(&queue))
    {
        int v = peek(&queue);
        pop(&queue);
        printf("%d ", v);

        LL *t = gp.arr[v];
        while(t){
            if(!visited[t->TO]){
                push(&queue, t->TO);
                visited[t->TO] = true;
            }
            t = t->next;
        }
    }
    printf("\n");
}


int main(int argc, char **argv)
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
        printf("Enter 3 to DFS\n");
        printf("Enter 4 to BFS\n");
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

        case 3:
        {

            bool *v = (bool *)malloc(sizeof(bool) * gp.Vertices);
            for (size_t i = 0; i < gp.Vertices; i++)
            {
                v[i] = false;
            }

            DFS(gp, 0, v);
            printf("\n");
            free(v);
        }
        break;

        case 4:
        {
            BFS(gp, 0);
        }
        break;
        }
    } while (ch);

    remove(argv[0]);
    return 0;
}