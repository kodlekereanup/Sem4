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
  for(int i = 0; i < vertices; i++) {
   // printf("%d ",i);
    for(int j = 0; j < vertices; j++) 
      printf("%d ",adjMatrix[i][j]);
    printf("\n");
  }
}

int main() {
  // No third argument: Undirected
  // true: directed both sides, false: directed only one side
  Graph g(4,3);
  g.connectVertices(0,1,false);
  g.connectVertices(1,2,false);
  g.connectVertices(2,3,false);
  g.connectVertices(3,0,false);
  g.showGraph();

  return 0;

}
