#pragma once

#include<iostream>
#include"Graph.h"
#include"Stack.h"

using namespace MyStack;
using namespace MyGraph;
using namespace std;
/*
using namespace MyStack;
using namespace MyGraph;
*/
/* Stack.h�� ERROR CODE
ERROR_INPUT 0b001
ERROR_EMPTY 0b010
EXIT 0b100
*/
/* Stack ���� ��밡���Լ�

int Enstack(DATA); //������ ����, ERROR��, Input ��ȯ
int Destack(); // ���� ������ ����, ERROR�� Empty ��ȯ

// Node ����ü��, data�� next node�� �̷�������.
NODE* StackFront(); // ���� ���� NODE��ȯ, �̴� NODE ����ü�� �˾ƾ���.
NODE* StackRear(); // ���� �ǾƷ� NODE��ȯ, �̴� NODE ����ü�� �˾ƾ���.

//2���� ���, ���������� STACK ������ ��°���.
void all_printStack();


*/
namespace MyGoal
{
	class Goal
	{
	private : 
		
	public:
		
		Goal();
		~Goal();

		
		int Goalseeking(GRAPH * m_graph, Stack * m_stack);
	};
}

