// weighted graph implementation
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct n
{
    int vertices;
    int **edges;
} Graph;

Graph *allocateMemory(int V)
{
    Graph *t = (Graph *)malloc(sizeof(Graph));
    t->vertices = V;
    t->edges = NULL;

    // allocate Memory
    t->edges = (int **)malloc(sizeof(int *) * V);
    assert(t->edges);
    for (int i = 0; i < t->vertices; i++)
    {
        t->edges[i] = (int *)malloc(sizeof(int) * V);
        assert(t->edges[i]);
        for (int j = 0; j < V; j++)
            t->edges[i][j] = -1;
    }
    return t;
}

int isSafe(int i,int j,int v){
    return (i < v && i >= 0 && j < v && j >= 0);
}

Graph* insertPath(Graph* gp, int V, int from, int to, int w){
    if(!gp){
        gp = allocateMemory(V);
    }

    if(isSafe(from,to,V)){
        gp->edges[from][to] = w;
        return gp;
    } else {
        printf("^~~~ INV vertices\n");
        return gp;
    }
}

void display(Graph* gp){
    printf("FROM TO\n");
    for (int i = 0; i < gp->vertices; i++)
    {
        for (int j = 0; j < gp->vertices; j++)
            if(gp->edges[i][j]!=-1)
                printf("{%d} ->[%d]  {%d}\n", i, gp->edges[i][j] ,j);
    }    
}

int main(int argc, char **argv)
{
    Graph *gp = NULL;
    printf("Enter the Vertices: ");
    int v;
    scanf("%d",&v);
    int ch;
    do{
        printf("[ 1 ] insert\n");
        printf("[ 2 ] display\n");
        printf("> ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                printf("Enter the from->to and the weight: ");
                int t,f,w;
                scanf("%d %d %d", &f, &t, &w);
                gp = insertPath(gp, v, f, t, w);
                break;
            }
            case 2:{
                display(gp);
            }
        }
    } while (ch);
    remove(argv[0]);
    return EXIT_SUCCESS;
}