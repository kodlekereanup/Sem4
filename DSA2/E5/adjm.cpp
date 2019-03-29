#include <stdio.h>
#include <math.h>

struct Graph {
  private:
  int vertices;
  int edges;
  bool** adjMatrix;

  public:
  Graph(int v, int e) : vertices(v), edges(e) {
    adjMatrix = new bool*[vertices];
    for(int i = 0; i < vertices; ++i) {
      adjMatrix[i] = new bool[vertices];
      for(int j = 0; j < vertices; ++j)
        adjMatrix[i][j] = false;
    }
}
  
  void connectVertices(int,int,bool);
  void showGraph(); 

};

void Graph :: connectVertices(int i , int j, bool state = true) {
  adjMatrix[i][j] = true;
  adjMatrix[j][i] = state;
}

void Graph :: showGraph() {
  for(int i = 0; i < vertices; i++) {
    printf("%d: ",i);
    for(int j = 0; j < vertices; j++) 
      printf("%d ",adjMatrix[i][j]);
    printf("\n");
  }
}

int main() {
  int v = 0, e = 0, srcVertex = 0, desVertex = 0, state = 0;  
  printf("\n Enter the number of vertices and edges of the graph:");
  scanf("%d%d",&v,&e);
  Graph g(v,e);
  for(int counter = 0; counter < ceil(e); counter++) {
    printf("\n Enter source vertex number (0-vertices): ");
    scanf("%d",&srcVertex);
    printf("\n Enter destination vertex number (0-vertices): ");
    scanf("%d",&desVertex);
    printf("\n Enter 1 for bidirectional, 0 otherwise: ");
    scanf("%d",&state);
    printf("\n");
    g.connectVertices(srcVertex,desVertex,(bool)state);
  }

  g.showGraph();
  return 0;

}
