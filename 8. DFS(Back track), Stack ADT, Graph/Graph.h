#pragma once
#include<iostream>
#include<cstdlib>

using namespace std;
namespace MyGraph 
{
	
	typedef struct _g_node {
		int data;
		struct _g_node *next;
	}G_NODE;
	//��ü node�� �ֻ��� node�� ����,
	typedef struct _head {
		struct _g_node *head;
	}HEAD;
	typedef struct _graph {
		int n;
		struct _head *arr;
	}GRAPH;

	class Graph
	{
	private :
		G_NODE* newNODE(int);

	public:
		Graph();
		~Graph();
		
		GRAPH* createGraph(int);
		void addEdge(GRAPH*, int, int);
		void printGraph(GRAPH*);
	};
}

