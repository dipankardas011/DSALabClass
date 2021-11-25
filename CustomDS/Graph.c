#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
// #include "../CustomDS/StackI.h"
#include "../CustomDS/QueueI.h"
// we gona specify the number of vertices
// this the is the array implementation

// assumming that the graph is dense

typedef struct gg {
  int Vertices;
  bool** graphMat;
}Graph;

void allocateMemory(int V, Graph* gp) {
  gp->Vertices = V;
  gp->graphMat = (bool**)malloc(sizeof(bool*) * V);
  assert(gp->graphMat != NULL);
  
  for (int i = 0;i < V;i++) {
    gp->graphMat[i] = (bool*)malloc(sizeof(bool));
    assert(gp->graphMat[i] != NULL);

    for (int j = 0;j < V;j++) {
      gp->graphMat[i][j] = false;
    }
  }

}

void displayGraph(Graph gp) {
  // vertices are 0.... V-1
  printf("Connections\n");
  for (int i = 0; i < gp.Vertices; i++) {
    for (int j = 0; j < gp.Vertices; j++) {
      if (gp.graphMat[i][j]) {
        printf("%d -> %d\n", i, j);
      }
    }
  }
}

bool isValid(int v, int i, int j) {
  if ((i < v && i >= 0) && (j < v && j >= 0))
    return true;
  return false;
}

void makeConnection(Graph* gp, int FROM, int TO) {
  if (isValid(gp->Vertices, FROM, TO)) {
    gp->graphMat[FROM][TO] = true;
    return;
  }
  printf("Invaliid vertices\n");
}

void removeConnections(Graph* gp, int FROM, int TO) {
  if (isValid(gp->Vertices, FROM, TO)) {
    gp->graphMat[FROM][TO] = false;
    return;
  }
  printf("Invaliid vertices\n");
}

void BFS(Graph gp){
  bool *visited = (bool *)malloc(sizeof(bool) * gp.Vertices);

  for (int i = 0; i < gp.Vertices;i++)
    visited[i] = false;

  int startVertice = 1;
  Queue queue;
  queue.front = queue.rear = -1;

  push(&queue, startVertice);
  visited[startVertice] = true;

  while(!isEmpty(&queue)){
    int v = peek(&queue);
    pop(&queue);
    printf("%d ", v);

    for (int i = 0; i < gp.Vertices; i++){
      if(!visited[i]){
        push(&queue, i);
        visited[i] = true;
      }
    }
  }
  printf("\n");
}

void dfsTraversal(int start, Graph gp, bool* visited){
  visited[start] = true;
  printf("%d ", start);

  for (int i = 0; i <gp.Vertices; i++){
    if(!visited[i]){
      dfsTraversal(i, gp, visited);
    }
  }
}

void DFS(Graph gp){
  bool *visited = (bool *)malloc(sizeof(bool) * gp.Vertices);

  for (int i = 0; i < gp.Vertices;i++)
    visited[i] = false;
  dfsTraversal(0, gp, visited);
}

int main(int argc, char const* argv[]) {
  Graph gp;
  int v;
  printf("Enter the number of vertices: ");
  scanf("%d", &v);
  allocateMemory(v, &gp);

  int ch;
  do {
    printf("Enter 1 to establish connection\n");
    printf("Enter 2 to remove connection\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to BFS\n");
    printf("Enter 5 to DFS\n");
    printf("Enter 0 to exit\n");
    scanf("%d", &ch);
    int i, j;
    switch (ch) {

    case 1:
      printf("Enter the 2 vertices{INSERTION} i.e. FROM TO: ");
      scanf("%d %d", &i, &j);
      makeConnection(&gp, i, j);
      break;
    case 2:
      printf("Enter the 2 vertices{DELETION} i.e. FROM TO: ");
      scanf("%d %d", &i, &j);
      removeConnections(&gp, i, j);
      break;

    case 3:
      displayGraph(gp);
      break;
      
    case 4:
      BFS(gp);
      break;

    case 5:
      DFS(gp);
      break;
    }
  } while (ch);

  return 0;
}
