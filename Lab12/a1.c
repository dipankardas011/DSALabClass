/*WAP to create an un-directed graph using adjacency matrix method.*/
#include <stdio.h>
#include <assert.h>
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
        }
    } while (ch);

    remove(argv[0]);
    return EXIT_SUCCESS;
}