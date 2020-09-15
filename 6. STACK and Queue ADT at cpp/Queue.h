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
			FIFO��� Ư���� ���� ������, sort�� ���� �� ������ �̶�� �� ���.
			error - return 0, non_error - return 1

			pre - ��� DATA�� �Ѱܹ���
			post - DATA�� NODE���·� �����ϰ�, CreateQueue()�Լ��� ȣ��
		
		*/
		int CreateQueue(NODE *);
		/*
			Enqueue()���� �����ϴ� �޼ҵ�.
			error - return 0, non_error - return 1 //Overflow�� �������� ����, full state�� ����.

			pre - ������ ��� NODE�� �ּҸ� �Ѱܹ���.
			post - LIST�� front, rear���� update�ϰ�, size�� ������. NODE�� nextNode�� ����,  Node�� �����, �Ҵ�.
		*/
		int Dequeue();
		/*
			FIFO��� Ư���� ���� ������, �߰����� �� ������ ���� �� ������
			error - return 0, non_error - return 1

			pre - ��� LIST�� ����.
			post - DeleteQueue()ȣ��

		*/
		int DeleteQueue(NODE*);
		/*
			Dequeue();�Լ����� ȣ��
			error - return 0, non_error - return 1 //Underflow emtpy state�� ������ �� ����.

			pre - ������ ��� NODE �ּҸ��Ѱܹ���
			post - LIST�� front���� update�ϰ�, size�� ������. ��� NODE�� �Ҵ�����.
		*/
		NODE* QueueFront();
		/*
			pre - Queue�� Empty ���°� �ƴ� ���¿��� LIST�� ����
			post - front NODE�� return;
		
		*/
		NODE* QueueRear();
		/*
			pre - Queue�� Empty ���°� �ƴ� ���¿��� LIST�� ����
			post - rear NODE�� return;
		*/
		void all_printQueue();
		/*
			pre - LIST�� ����
			post - front���� ����������, rear���� printQueue()�� ȣ��
		*/
		void printQueue(NODE* );
		/*
			all_printQueue���� ȣ���ϴ� �Լ�

			pre - ��� Data�� �Ѱܹ���
			post - ��� Data�� data�� ���.
		*/
		
		int Input_case();
		/*
			Enqueue(), Dequeue(), all_printQueue() �� ȣ����.

			pre - main.cpp���� ������ q�� �Ѱܹ���
			post - ����ڰ� Ư�� ����� �Է��ϰ�, �̿����� �ش� ������ ������
		*/
	};

}

