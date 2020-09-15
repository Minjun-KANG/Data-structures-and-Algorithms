#include "Graph.h"


using namespace MyGraph;



//인접노드를 위한 구조체 - 각노드를 나타냄

//create a new node
G_NODE* MyGraph::Graph::newNODE(int data) {
	G_NODE *nptr = new G_NODE;
	nptr->data = data;
	//nptr->data = data;
	nptr->next = NULL;
	return nptr;
}

//그래프 생성
GRAPH* MyGraph::Graph::createGraph(int n) {
	GRAPH *graph = new GRAPH;
	graph->n = n;
	//인접리스트로 arr 생성. n개
	graph->arr = new _head[n];
	
	for (int i = 0; i < n; i++) {
		graph->arr[i].head = NULL;
	}
	return graph;
}

void MyGraph::Graph::addEdge(GRAPH *graph, int src, int dest)
{
	//dest랑 src를 연결
	G_NODE *nptr = newNODE(dest);
	nptr->next = graph->arr[src].head;
	graph->arr[src].head = nptr;
	//src랑 dest를 연결
	nptr = newNODE(src);
	nptr->next = graph->arr[dest].head;
	graph->arr[dest].head = nptr;
}




//function to print the graph
void MyGraph::Graph::printGraph(GRAPH* graph) {
	//loop over each adjacent list
	for (int i = 0; i < graph->n; i++) {
		G_NODE *root = graph->arr[i].head;
		cout << i << "의 인접노드" << endl;
		
		//각 리스트연결.
		while (root != NULL) {
			cout << root->data << ", ";
			root = root->next;
		}
		cout << endl;
	}
}

Graph::Graph()
{
}


Graph::~Graph()
{
}


