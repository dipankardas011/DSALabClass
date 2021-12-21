/*WAP to check whether an undirected graph is connected or not using DFS.
https://i0.wp.com/algorithms.tutorialhorizon.com/files/2019/10/Connected-Undirected-Graph-Example.png?w=967&ssl=1*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void dfsTraversal(int start, Graph gp, bool *visited)
{
    visited[start] = true;
    for (int i = 0; i < gp.Vertices; i++)
    {
        if (!visited[i] && gp.graphMat[start][i])
        {
            dfsTraversal(i, gp, visited);
        }
    }
}

bool isConnected(Graph gp, int root)
{
    bool *visited = (bool *)malloc(sizeof(bool) * gp.Vertices);

    for (int i = 0; i < gp.Vertices; i++)
        visited[i] = false;
    dfsTraversal(root, gp, visited);
    for (int i = 0; i < gp.Vertices; i++)
    {
        if(visited[i] == false){
            return 0;
        }
    }
    return 1;
}


int main(int argc, char **argv) {

    // the demo data inserted
    Graph gp;
    allocateMemory(5, &gp);

    makeConnection(&gp, 0, 1);
    makeConnection(&gp, 1, 3);
    makeConnection(&gp, 2, 3);
    makeConnection(&gp, 2, 4);

    displayGraph(gp);
    (isConnected(gp, 0)) ? printf("Is Connected\n") : printf("Disconnection are there\n");


    remove(argv[0]);
    return EXIT_SUCCESS;
}