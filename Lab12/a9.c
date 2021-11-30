/* WAP to check if a directed graph is a tree or not using DFS.*/
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

bool isCyclicUtil(Graph gp, int v, bool* visited, bool* recS){
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recS[v] = true;
  
        // Recur for all the vertices adjacent to this vertex
        for(int i = 0; i < gp.Vertices; ++i)
        {
            if (gp.graphMat[v][i] && !visited[i] && isCyclicUtil(gp,i, visited, recS) )
                return true;
            // so if the adjacent vertex is there in the recurernce stack & visited ✅
            // cycle detected
            else if (gp.graphMat[v][i] && visited[i] && recS[i])
                return true;
        }
    }
    recS[v] = false;  // remove the vertex from recursion stack
    return false;
}

// as tree are scyclic and graph contains loops so find for loops
bool isCycle(Graph gp)
{
    bool *visited = (bool *)malloc(sizeof(bool) * gp.Vertices);
    bool *recStack = (bool *)malloc(sizeof(bool) * gp.Vertices);
    for (int i = 0; i < gp.Vertices; i++){
        visited[i] = false;
        recStack[i] = false;
    }

    // if there is a disconnection it also helps
    for(int i = 0; i < gp.Vertices; i++)
        if (isCyclicUtil(gp, i, visited, recStack)){
            free(visited);
            free(recStack);
            return true;
        }

    free(visited);
    free(recStack);
    return false;
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
    (!isCycle(gp)) ? printf("^~~~Tree!\n\n") : printf("^~~~Graph!\n\n");

    Graph g1;
    allocateMemory(5, &g1);
    makeConnection(&g1, 1, 0);
    makeConnection(&g1, 0, 2);
    makeConnection(&g1, 2, 1);
    makeConnection(&g1, 0, 3);
    makeConnection(&g1, 3, 4);
    displayGraph(g1);
    (!isCycle(g1)) ? printf("^~~~Tree!\n\n") : printf("^~~~Graph!\n\n");


    Graph g;
    allocateMemory(4, &g);
    makeConnection(&g, 0, 1);
    makeConnection(&g, 0, 2);
    makeConnection(&g, 1, 2);
    makeConnection(&g, 2, 0);
    makeConnection(&g, 2, 3);
    makeConnection(&g, 3, 3);
    displayGraph(g1);
    (!isCycle(g1)) ? printf("^~~~Tree!\n\n") : printf("^~~~Graph!\n\n");

    remove(argv[0]);
    return EXIT_SUCCESS;
}