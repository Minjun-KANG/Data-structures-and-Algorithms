#include "Queue.h"

using namespace MyQueue;

int Queue::Input_case()
{
	DATA input_data;
	int re_carry = 0;
	char in;
	cout << "Input case : ";
	cin >> in;
	if (in <= 'z' && in >= 'a') { in -= 32; } // �ҹ��� ����ó��

	switch (in)
	{
	case 'P': // print all list of data
		all_printQueue();
		break;
	
	case 'I': // inseat part
		cout << "data : ";
		cin >> input_data.main_data;
		if (!Enqueue(input_data))
		{
			re_carry = re_carry | ERROR_EMPTY;
		}
		else
		{
			cout << "Insert Success" << endl;
		}
		break;

	case 'D':
		if (!Dequeue())
		{
			re_carry = re_carry | ERROR_INPUT;
		}
		else
		{
			cout << "Delete Success" << endl;
		}
		break;

	case 'Q':
		
		re_carry = re_carry | EXIT;
		break;

	default:
		re_carry = re_carry | ERROR_INPUT; // ������ �Է¹��ڿ� ���� ����ó��.
	}
	return re_carry;
}

int Queue::Enqueue(DATA a_data)
{
	int re_carry = 1;
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	if (newNode == NULL)
	{
		re_carry--;
	}
	memcpy(&newNode->data, &a_data, sizeof(DATA)); // data insert
	
	if (!CreateQueue(newNode))
	{
		re_carry--;
	}
	
	return re_carry;
}
int Queue::CreateQueue(NODE *newNode)
{
	int re_carry = 1;
	if (!list->data_size) //front, rear is NULL //first case
	{
		newNode->next = NULL;
		list->front = newNode;
		list->rear = newNode; //rear�� ó�� ������ ���� ����
		list->data_size++;
	}
	else //general case
	{
		//front�� newMode�� ����Ű��, newNode�� nextNode�� pPre���� ����Ŵ
		//  STACK
		NODE *pPre = list->front;
		newNode->next = pPre;
		list->front = newNode;
		list->data_size++;
		
		/*
		NODE *pPre = list->rear;
		list->rear->next = newNode;
		newNode->next = NULL;
		list->rear = newNode;
		list->data_size++;
		*/
	}
	return re_carry;
}
int Queue::Dequeue() // 0�� ��ȯ�ϴ� ���� empty state�� ����.
{
	//�� �� node�� ����, DeleteQueue�� ��������, int_size-- ��, �Ҵ�����
	int re_carry = 1;
	NODE *curNode = list->front;
	if (!list->data_size) //���� NODE�� empty�� ��,
	{
		re_carry--;
		return re_carry; //�ٷ� �Լ�����
	}
	else if (curNode->next == NULL) //curNode�� �����ϸ�, empty Node�� ��,
	{
		free(curNode);
	}
	else if (!DeleteQueue(curNode)) //general case
	{
		re_carry--;
		free(curNode);
	}
	return re_carry;
}
int Queue::DeleteQueue(NODE* curNode) //empty ����.
{
	int re_carry = 1;
	NODE *nextNode = curNode->next;
	list->front = nextNode;
	return re_carry;
}

NODE* Queue::QueueFront()
{
	return list->front;
}
NODE* Queue::QueueRear()
{
	return list->rear;
}

void Queue::all_printQueue()
{
	NODE *targetNode = QueueFront();
	while (targetNode != NULL) // targetNode�� �������� �ƴ� ������, 
	{
		printQueue(targetNode);
		targetNode = targetNode->next;
	}
}

void Queue:: printQueue(NODE* targetNode)
{
	if (targetNode == QueueFront())
	{
		cout << "------------Queue------------" << endl;
		cout << "front ->";
		cout.width(7);
		cout << targetNode->data.main_data << endl;

	}
	else if (targetNode == QueueRear())
	{
		cout.width(15);
		cout << targetNode->data.main_data;
		cout.width(14);
		cout << "<- rear" << endl;
		cout << "-----------------------------" << endl;
	}
	else
	{
		cout.width(15);
		cout << targetNode->data.main_data << endl;
	}
}
Queue::Queue() //constructor
{
	list = (LIST*)malloc(sizeof(LIST));
	//cout << "constructor" << endl;
	list->front = NULL;
	list->rear = NULL;
	list->data_size = 0;
}
Queue::~Queue() //destructor
{
	free(list);
	//cout << "destructor" << endl;
}
