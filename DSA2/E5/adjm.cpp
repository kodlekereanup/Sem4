#include <stdio.h>

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

  int getVertices();
  int getEdges();
  
  void connectVertices(int,int,bool);
  void showGraph(); 

};

int Graph :: getVertices() { return vertices; }
int Graph :: getEdges() { return edges; }

void Graph :: connectVertices(int i , int j, bool state = true) {
  adjMatrix[i][j] = true;
  adjMatrix[j][i] = state;
}

void Graph :: showGraph() {
  //printf(" %d "); 
  for(int i = 0; i < vertices; i++) {
  //  printf("%d: ",i);
    for(int j = 0; j < vertices; j++) 
      printf("%d ",adjMatrix[i][j]);
    printf("\n");
  }
}

int main() {
  // No third argument: Undirected
  // true: directed both sides, false: directed only one side
  int v = 0, e = 0, counter = 0, srcVertex = 0, desVertex = 0;  
  int state = 0;
  printf("\n Enter the number of vertices and edges of the graph:");
  scanf("%d%d",&v,&e);
  Graph g(v,e);
  while(counter != (g.getVertices())) {
    counter++;
    printf("\n Enter source vertex number (0-vertices): ");
    scanf("%d",&srcVertex);
    printf("\n Enter destination vertex number (0-vertices): ");
    scanf("%d",&desVertex);
    printf("\n Enter true for bidirectional, false otherwise: ");
    scanf("%d",&state);
    printf("\n");
    g.connectVertices(srcVertex,desVertex,(bool)state);
  }

  g.showGraph();
  return 0;

}
