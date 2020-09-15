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
/* Stack.h의 ERROR CODE
ERROR_INPUT 0b001
ERROR_EMPTY 0b010
EXIT 0b100
*/
/* Stack 에서 사용가능함수

int Enstack(DATA); //데이터 삽입, ERROR시, Input 반환
int Destack(); // 맨위 데이터 삭제, ERROR시 Empty 반환

// Node 구조체는, data와 next node로 이뤄져있음.
NODE* StackFront(); // 가장 맨위 NODE반환, 이는 NODE 구조체를 알아야함.
NODE* StackRear(); // 가장 맨아래 NODE반환, 이는 NODE 구조체를 알아야함.

//2차원 평면, 수직방향의 STACK 구조를 출력가능.
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

