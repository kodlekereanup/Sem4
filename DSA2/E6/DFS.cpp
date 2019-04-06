#include <stdio.h>
#include <conio.h>

#define INITIAL 1
#define WAITING 2
#define VISITED 3
#define SIZE 100

struct Stack {
  private:
  int stack[SIZE];
  int state[SIZE];
  int top = -1;
  public:
  friend struct Graph;
  const inline int getTop();
  const inline bool isEmpty();
  void push(int);
  int pop();
};

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
  
  const inline int getVertices();
  const inline int getEdges();
  void initialize(Stack&);
  void connectVertices(int,int,bool);
  void showGraph();
  void DFS(int,Stack&);

};

const inline int Stack :: getTop() { return top; }

void Stack :: push(int v) {
  if(top == SIZE) return;
  else stack[++top] = v;
}

int Stack :: pop() {
  if (top == -1) return -1;
  else return stack[top--];
}

const inline bool Stack :: isEmpty() { return (top == -1)? true : false ; }
const inline int Graph :: getVertices() { return vertices; }
const inline int Graph :: getEdges() { return edges; }

void Graph :: connectVertices(int i, int j, bool state = true) {
  adjMatrix[i][j] = true;
  adjMatrix[j][i] = state;
}

void Graph :: showGraph() {
  for(int i = 0; i < vertices; ++i) {
    printf("%d: ", i);
    for(int j = 0; j < vertices; ++j) 
      printf("%d ", adjMatrix[i][j]);
    printf("\n");
  }
}

void Graph :: initialize(Stack& s) {
  for(int i = 0; i < vertices; ++i) s.state[i] = INITIAL;
}

void Graph :: DFS(int srcVertex, Stack& s) {
  int i;
  s.push(srcVertex);
  s.state[srcVertex] = WAITING;

  while(!s.isEmpty()) {
    srcVertex = s.pop();
    printf("%d ", srcVertex);
    s.state[srcVertex] = VISITED;

    for(int i = 0; i < vertices; ++i) {
      if(adjMatrix[srcVertex][i] == 1 && s.state[i] == INITIAL) {
        s.push(i);
        s.state[i] = WAITING;
      }
    }
  }
  printf("\n");
}

int main() {
	
	int v = 0,sv = 0, e = 0, state = 0, srcVertex = 0, desVertex = 0;
	printf("\n Enter the number of vertices and edges of the graph:");
	scanf("%d%d", &v, &e);
	Graph g(v, e);
	Stack s;
	for (int counter = 0; counter < e; counter++) {
		printf("\n Enter source and destination: ");
		scanf("%d%d", &srcVertex, &desVertex);
		printf("\n Enter 1 for bidirectional, 0 otherwise: ");
		scanf("%d", &state);
		printf("\n");
		g.connectVertices(srcVertex, desVertex, (bool)state);
	}

	g.showGraph();

	g.initialize(s);
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &sv);
	g.DFS(sv, s);

	getch();
	return 0;

}
