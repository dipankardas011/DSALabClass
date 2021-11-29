/*Modify the above program to include a menu driven program and add options for the depth-first traversal and breadth-first traversal.*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "../CustomDS/QueueI.h"

typedef struct gg
{
    int Vertices;
    bool **graphMat;
} Graph;

void allocateMemory(int V, Graph *gp)
{
    gp->Vertices = V;
    gp->graphMat = (bool **)malloc(sizeof(bool *) * V);

    for (int i = 0; i < V; i++)
    {
        gp->graphMat[i] = (bool *)malloc(sizeof(bool));

        for (int j = 0; j < V; j++)
        {
            gp->graphMat[i][j] = false;
        }
    }
}


void displayGraph(Graph gp)
{
    // vertices are 0.... V-1
    printf("Connections\n");
    printf("FROM -> TO\n");
    for (int i = 0; i < gp.Vertices; i++)
    {
        for (int j = 0; j < gp.Vertices; j++)
        {
            if (gp.graphMat[i][j])
            {
                printf("%d -> %d\n", i, j);
            }
        }
    }
    printf("===========\n");
}

bool isValid(int v, int i, int j)
{
    if ((i < v && i >= 0) && (j < v && j >= 0))
        return true;
    return false;
}

void makeConnection(Graph *gp, int FROM, int TO)
{
    if (isValid(gp->Vertices, FROM, TO))
    {
        gp->graphMat[FROM][TO] = true;
        gp->graphMat[TO][FROM] = true;
        return;
    }
    printf("Invaliid vertices\n");
}

void removeConnections(Graph *gp, int FROM, int TO)
{
    if (isValid(gp->Vertices, FROM, TO))
    {
        gp->graphMat[FROM][TO] = false;
        return;
    }
    printf("Invaliid vertices\n");
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

        for (int i = 0; i < gp.Vertices; i++)
        {
            if (gp.graphMat[v][i] && !visited[i])
            {
                push(&queue, i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

void dfsTraversal(int start, Graph gp, bool *visited)
{
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < gp.Vertices; i++)
    {
        if (!visited[i] && gp.graphMat[start][i])
        {
            dfsTraversal(i, gp, visited);
        }
    }
}

void DFS(Graph gp, int root)
{
    bool *visited = (bool *)malloc(sizeof(bool) * gp.Vertices);

    for (int i = 0; i < gp.Vertices; i++)
        visited[i] = false;
    dfsTraversal(root, gp, visited);
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
        printf("Enter 3 to BFS\n");
        printf("Enter 4 to DFS\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &ch);
        int i, j;
        switch (ch)
        {

        case 1:
            printf("Enter the 2 vertices{INSERTION} i.e. FROM TO: ");
            scanf("%d %d", &i, &j);
            makeConnection(&gp, i, j);
            break;

        case 2:
            displayGraph(gp);
            break;

        case 3:
            printf("Enter the start vertice: ");
            scanf("%d", &i);
            BFS(gp, i);
            break;

        case 4:
            printf("Enter the start vertice: ");
            scanf("%d", &i);
            DFS(gp, i);
            printf("\n");
            break;
        }
    } while (ch);
    remove(argv[0]);

    return 0;
}
