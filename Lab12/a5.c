/*WAP to check if an undirected graph is a tree or not using BFS.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../CustomDS/QueueI.h"
#include "../CustomDS/Graph.h"

bool isCyclic(Graph gp, int s, bool *visited)
{
    Queue queue;
    queue.front = queue.rear = -1;

    int *parent = (int *)malloc(sizeof(int) * gp.Vertices);
    for (int i = 0; i < gp.Vertices; i++)
        parent[i] = -1;

    push(&queue, s);
    visited[s] = true;

    while (!isEmpty(&queue))
    {
        int v = peek(&queue);
        pop(&queue);

        for (int i = 0; i < gp.Vertices; i++)
        {
            if (gp.graphMat[v][i] && !visited[i])
            {
                push(&queue, i);
                visited[i] = true;
                parent[i] = v;
            }
            else if (gp.graphMat[v][i] && visited[i] && parent[v] != i)
            {
                free(parent);
                return true;
            }
        }
    }
    free(parent);
    return false;
}
// as tree are scyclic and graph contains loops so find for loops
bool isTree(Graph gp)
{
    bool *visited = (bool *)malloc(sizeof(bool) * gp.Vertices);
    for (int i = 0; i < gp.Vertices; i++)
        visited[i] = false;

    if (isCyclic(gp, 0, visited))
    {
        free(visited);
        return false;
    }

    // check for connectivity

    for (int i = 0; i < gp.Vertices; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    Graph gp;
    allocateMemory(5, &gp);

    // demo input
    makeConnection(&gp, 1, 0);
    makeConnection(&gp, 0, 2);
    makeConnection(&gp, 0, 3);
    makeConnection(&gp, 3, 4);
    displayGraph(gp);
    (isTree(gp)) ? printf("^~~~Tree!\n\n") : printf("^~~~Graph!\n\n");

    Graph g1;
    allocateMemory(5, &g1);
    makeConnection(&g1, 1, 0);
    makeConnection(&g1, 0, 2);
    makeConnection(&g1, 2, 1);
    makeConnection(&g1, 0, 3);
    makeConnection(&g1, 3, 4);
    displayGraph(g1);
    (isTree(g1)) ? printf("^~~~Tree!\n\n") : printf("^~~~Graph!\n\n");

    remove(argv[0]);
    return EXIT_SUCCESS;
}