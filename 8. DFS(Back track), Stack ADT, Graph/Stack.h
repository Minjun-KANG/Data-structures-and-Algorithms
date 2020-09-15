#pragma once
//Stack.h
#include <iostream>
#define ERROR_INPUT 0b001
#define ERROR_EMPTY 0b010
#define EXIT 0b100

using namespace std;

namespace MyStack
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

	class Stack
	{
	private:
		void printStack(NODE*);
		/*
			all_printStack���� ȣ���ϴ� �Լ�

			pre - ��� Data�� �Ѱܹ���
			post - ��� Data�� data�� ���.
		*/
		int DeleteStack(NODE*);
		/*
			Destack();�Լ����� ȣ��
			error - return 0, non_error - return 1 //Underflow emtpy state�� ������ �� ����.

			pre - ������ ��� NODE �ּҸ��Ѱܹ���
			post - LIST�� front���� update�ϰ�, size�� ������. ��� NODE�� �Ҵ�����.
		*/
		int CreateStack(NODE *);
		/*
			Enstack()���� �����ϴ� �޼ҵ�.
			error - return 0, non_error - return 1 //Overflow�� �������� ����, full state�� ����.

			pre - ������ ��� NODE�� �ּҸ� �Ѱܹ���.
			post - LIST�� front, rear���� update�ϰ�, size�� ������. NODE�� nextNode�� ����,  Node�� �����, �Ҵ�.
		*/
		
	public:
		LIST *list;
		Stack(); //Constructor
		~Stack();//Destructor
		int IsEmpty(); //non error 1, error ERROR empty
		int Enstack(DATA);
		/*
			FIFO��� Ư���� ���� ������, sort�� ���� �� ������ �̶�� �� ���.
			error - return 0, non_error - return 1

			pre - ��� DATA�� �Ѱܹ���
			post - DATA�� NODE���·� �����ϰ�, CreateStack()�Լ��� ȣ��

		*/
		
		int Destack();
		/*
			FIFO��� Ư���� ���� ������, �߰����� �� ������ ���� �� ������
			error - return 0, non_error - return 1

			pre - ��� LIST�� ����.
			post - DeleteStack()ȣ��

		*/
		
		NODE* StackFront();
		/*
			pre - Stack�� Empty ���°� �ƴ� ���¿��� LIST�� ����
			post - front NODE�� return;

		*/
		NODE* StackRear();
		/*
			pre - Stack�� Empty ���°� �ƴ� ���¿��� LIST�� ����
			post - rear NODE�� return;
		*/
		void all_printStack();
		/*
			pre - LIST�� ����
			post - front���� ����������, rear���� printStack()�� ȣ��
		*/
		

		int Input_case();
		/*
			Enstack(), Destack(), all_printStack() �� ȣ����.

			pre - main.cpp���� ������ q�� �Ѱܹ���
			post - ����ڰ� Ư�� ����� �Է��ϰ�, �̿����� �ش� ������ ������
		*/
	};

}

