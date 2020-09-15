#include "Graph.h"


using namespace MyGraph;



//������带 ���� ����ü - ����带 ��Ÿ��

//create a new node
G_NODE* MyGraph::Graph::newNODE(int data) {
	G_NODE *nptr = new G_NODE;
	nptr->data = data;
	//nptr->data = data;
	nptr->next = NULL;
	return nptr;
}

//�׷��� ����
GRAPH* MyGraph::Graph::createGraph(int n) {
	GRAPH *graph = new GRAPH;
	graph->n = n;
	//��������Ʈ�� arr ����. n��
	graph->arr = new _head[n];
	
	for (int i = 0; i < n; i++) {
		graph->arr[i].head = NULL;
	}
	return graph;
}

void MyGraph::Graph::addEdge(GRAPH *graph, int src, int dest)
{
	//dest�� src�� ����
	G_NODE *nptr = newNODE(dest);
	nptr->next = graph->arr[src].head;
	graph->arr[src].head = nptr;
	//src�� dest�� ����
	nptr = newNODE(src);
	nptr->next = graph->arr[dest].head;
	graph->arr[dest].head = nptr;
}




//function to print the graph
void MyGraph::Graph::printGraph(GRAPH* graph) {
	//loop over each adjacent list
	for (int i = 0; i < graph->n; i++) {
		G_NODE *root = graph->arr[i].head;
		cout << i << "�� �������" << endl;
		
		//�� ����Ʈ����.
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


