#pragma once
//Queue.h
#include <iostream>
#define ERROR_INPUT 0b001
#define ERROR_EMPTY 0b010
#define EXIT 0b100

using namespace std;

namespace MyQueue
{
	typedef struct _list
	{
		struct _node *front;
		struct _node *rear;
		int data_size;
	}LIST;

	typedef struct _data
	{
		int main_data;
	}DATA;
	typedef struct _node
	{
		DATA data;
		struct _node *next;
	}NODE;

	class Queue
	{
	private:
		LIST *list;
	public:
		Queue(); //Constructor
		~Queue();//Destructor
		int Enqueue(DATA);
		/*
			FIFO라는 특성을 갖기 때문에, sort는 있을 수 없는일 이라는 걸 명시.
			error - return 0, non_error - return 1

			pre - 대상 DATA를 넘겨받음
			post - DATA를 NODE형태로 구성하고, CreateQueue()함수를 호출
		
		*/
		int CreateQueue(NODE *);
		/*
			Enqueue()에서 실행하는 메소드.
			error - return 0, non_error - return 1 //Overflow는 존재하지 않음, full state가 없음.

			pre - 삽입할 대상 NODE의 주소를 넘겨받음.
			post - LIST에 front, rear값을 update하고, size를 조절함. NODE의 nextNode를 연결,  Node를 만들고, 할당.
		*/
		int Dequeue();
		/*
			FIFO라는 특성을 갖기 때문에, 중간삭제 및 삽입은 있을 수 없는일
			error - return 0, non_error - return 1

			pre - 대상 LIST에 접근.
			post - DeleteQueue()호출

		*/
		int DeleteQueue(NODE*);
		/*
			Dequeue();함수에서 호출
			error - return 0, non_error - return 1 //Underflow emtpy state는 존재할 수 있음.

			pre - 삭제할 대상 NODE 주소를넘겨받음
			post - LIST에 front값을 update하고, size를 조절함. 대상 NODE를 할당해제.
		*/
		NODE* QueueFront();
		/*
			pre - Queue가 Empty 상태가 아닌 상태에서 LIST에 접근
			post - front NODE를 return;
		
		*/
		NODE* QueueRear();
		/*
			pre - Queue가 Empty 상태가 아닌 상태에서 LIST에 접근
			post - rear NODE를 return;
		*/
		void all_printQueue();
		/*
			pre - LIST에 접근
			post - front부터 순차적으로, rear까지 printQueue()를 호출
		*/
		void printQueue(NODE* );
		/*
			all_printQueue에서 호출하는 함수

			pre - 대상 Data를 넘겨받음
			post - 대상 Data의 data를 출력.
		*/
		
		int Input_case();
		/*
			Enqueue(), Dequeue(), all_printQueue() 를 호출함.

			pre - main.cpp에서 생성한 q를 넘겨받음
			post - 사용자가 특정 명령을 입력하고, 이에따라 해당 동작을 수행함
		*/
	};

}

