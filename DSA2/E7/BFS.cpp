#include <stdio.h>
#include <conio.h>
#include <math.h>

#define SIZE 100
#define initial 1
#define waiting 2
#define visited 3

struct Queue {
private:
	int state[SIZE];
	int queue[SIZE];
	int front = -1, rear = -1;
public:
	friend struct Graph;
	const inline bool isEmpty();
	const inline int getFront();
	const inline int getRear();
	void enqueue(int);
	int dequeue();
};

struct Graph {
private:
	int vertices;
	int edges;
	bool** adjMatrix;

public:
	Graph(int v, int e) : vertices(v), edges(e) {
		adjMatrix = new bool*[vertices];
		for (int i = 0; i < vertices; ++i) {
			adjMatrix[i] = new bool[vertices];
			for (int j = 0; j < vertices; ++j)
				adjMatrix[i][j] = false;
		}
	}

	const inline int getVertices();
	const inline int getEdges();
	void Initialize(Queue&);
	void connectVertices(int, int, bool);
	void showGraph();

	void BFS(int,Queue&);

};

const inline bool Queue :: isEmpty() {
	if (front == -1 || front > rear) return true;
	else return false;
}

const inline int Queue :: getFront() { return front; }
const inline int Queue :: getRear() { return rear; }
	

void Queue ::enqueue(int v) {

	if (front == -1) front = 0;
	if (rear == SIZE - 1) return;
	else queue[++rear] = v;

}

int Queue :: dequeue() {
	if (front == -1 || front > rear) return -1;
	else return queue[front++];
}

const inline int Graph::getVertices() { return vertices; }
const inline int Graph::getEdges() { return edges; }

void Graph::connectVertices(int i, int j, bool state = true) {
	adjMatrix[i][j] = true;
	adjMatrix[j][i] = state;
}

void Graph::showGraph() {
	
	for (int i = 0; i < vertices; i++) {
	  printf("%d: ",i);
		for (int j = 0; j < vertices; j++)
			printf("%d ", adjMatrix[i][j]);
		printf("\n");
	}
}

void Graph::BFS(int v, Queue& q) {
	int i;
	q.enqueue(v);
	q.state[v] = waiting;

	while (!q.isEmpty()) {

		v = q.dequeue();
		printf("%d ", v);
		q.state[v] = visited;

		for (i = 0; i < vertices; i++) {

			if (adjMatrix[v][i] == 1 && q.state[i] == initial) {
				q.enqueue(i);
				q.state[i] = waiting;
			}
		}
	}
	printf("\n");
}

void Graph :: Initialize(Queue& q) {		
	for (int i = 0; i < vertices; i++) q.state[i] = initial;	
}

int main() {
	
	int v = 0,sv = 0, e = 0, state = 0, srcVertex = 0, desVertex = 0;
	printf("\n Enter the number of vertices and edges of the graph:");
	scanf("%d%d", &v, &e);
	Graph g(v, e);
	Queue q;
	for (int counter = 0; counter < ceil(e); counter++) {

		printf("\n Enter source vertex number (0-vertices): ");
		scanf("%d", &srcVertex);
		printf("\n Enter destination vertex number (0-vertices): ");
		scanf("%d", &desVertex);
		printf("\n Enter true for bidirectional, false otherwise: ");
		scanf("%d", &state);
		printf("\n");
		g.connectVertices(srcVertex, desVertex, (bool)state);
	}

	g.showGraph();

	g.Initialize(q);
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &sv);
	g.BFS(sv, q);

	getch();
	return 0;


}


