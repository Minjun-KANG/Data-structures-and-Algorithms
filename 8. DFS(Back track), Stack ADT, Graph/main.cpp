#include "Goal.h"
#include "Graph.h"
#include "Stack.h"
//using namespace MyStack;
using namespace MyGoal;
using namespace MyGraph;
using namespace MyStack;

int main()
{
	Goal *goal = new Goal();
	Graph *G = new Graph();
	GRAPH *graph;

	
	// node 생성 -> 강의자료와 동일하게 구성.
	cout << "Node의 개수 : 18개" << endl;
	graph = G->createGraph(18); // 개수에 맞는 Graph 생성.
	cout << "각 NODE의 연결 구조" << endl;
	//G->addEdge(graph, 0, 1);
	G->addEdge(graph, 1, 2);
	G->addEdge(graph, 2, 3);
	G->addEdge(graph, 3, 4);
	G->addEdge(graph, 3, 12);
	G->addEdge(graph, 4, 5);
	G->addEdge(graph, 5, 6);
	G->addEdge(graph, 5, 8); //end
	G->addEdge(graph, 5, 9);
	G->addEdge(graph, 6, 7); // end
	G->addEdge(graph, 9, 10);
	G->addEdge(graph, 10, 11); //end 
	G->addEdge(graph, 12, 13);
	G->addEdge(graph, 13, 14);
	G->addEdge(graph, 13, 17); 
	G->addEdge(graph, 14, 15); 
	G->addEdge(graph, 15, 16); //end or goal
	G->addEdge(graph, 17, 18); //end
	G->printGraph(graph);
	/*
	G_NODE *root = graph->arr[i].head;
	cout << i << "의 인접노드" << endl;
	//loop over each node in list
	while (root != NULL) {
		cout << root->data << ", ";
		root = root->next;
	}*/

	Stack *stack = new Stack();
	int error_sign = goal->Goalseeking(graph, stack);
	if (error_sign & ERROR_EMPTY == ERROR_EMPTY)
	{
		cout << "empty error !" << endl;
	}
	else if(error_sign & ERROR_INPUT == ERROR_INPUT)
	{
		cout << "input error !" << endl;
	}

	return 0;

}

