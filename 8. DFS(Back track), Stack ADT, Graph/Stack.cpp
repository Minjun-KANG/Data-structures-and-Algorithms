#include "Stack.h"

using namespace MyStack;

int Stack::Input_case()
{
	DATA input_data;
	int re_carry = 0;
	char in;
	cout << "Input case : ";
	cin >> in;
	if (in <= 'z' && in >= 'a') { in -= 32; } // 소문자 예외처리

	switch (in)
	{
	case 'P': // print all list of data
		all_printStack();
		break;

	case 'I': // inseat part
		cout << "data : ";
		cin >> input_data.main_data;
		if (!Enstack(input_data))
		{
			re_carry = re_carry | ERROR_EMPTY;
		}
		else
		{
			cout << "Insert Success" << endl;
		}
		break;

	case 'D':
		if (!Destack())
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
		re_carry = re_carry | ERROR_INPUT; // 나머지 입력문자에 대해 예외처리.
	}
	return re_carry;
}

int Stack::Enstack(DATA a_data)
{
	int re_carry = 1;
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	if (newNode == NULL)
	{
		re_carry--;
	}
	memcpy(&newNode->data, &a_data, sizeof(DATA)); // data insert

	if (!CreateStack(newNode))
	{
		re_carry--;
	}

	return re_carry;
}
int Stack::CreateStack(NODE *newNode)
{
	int re_carry = 1;
	if (!list->data_size) //front, rear is NULL //first case
	{
		newNode->next = NULL;
		list->front = newNode;
		list->rear = newNode; //rear는 처음 들어오는 값이 고정
		list->data_size++;
	}
	else //general case
	{
		//front가 newMode를 가르키고, newNode의 nextNode는 pPre값을 가르킴
		//  STACK
		NODE *pPre = list->front;
		newNode->next = pPre;
		list->front = newNode;
		list->data_size++;
		
		//Queue
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
int Stack::Destack() // 0을 반환하는 경우는 empty state일 때만.
{
	//맨 앞 node를 갖고, DeleteStack로 보낸다음, int_size-- 후, 할당해제
	int re_carry = 1;
	NODE *curNode = list->front;
	if (!list->data_size) //현재 NODE가 empty일 때,
	{
		re_carry--;
		return re_carry; //바로 함수종료
	}
	else if (curNode->next == NULL) //curNode를 삭제하면, empty Node일 때,
	{
		free(curNode);
	}
	else if (!DeleteStack(curNode)) //general case
	{
		re_carry--;
		free(curNode);
	}
	return re_carry;
}
int Stack::DeleteStack(NODE* curNode) //empty 조심.
{
	int re_carry = 1;
	NODE *nextNode = curNode->next;
	list->front = nextNode;
	return re_carry;
}

NODE* Stack::StackFront()
{
	return list->front;
}
NODE* Stack::StackRear()
{
	return list->rear;
}

void Stack::all_printStack()
{
	NODE *targetNode = StackFront();
	while (targetNode != NULL) // targetNode가 마지막이 아닐 때까지, 
	{
		printStack(targetNode);
		targetNode = targetNode->next;
	}
}

void Stack::printStack(NODE* targetNode)
{
	if (targetNode == StackFront())
	{
		cout << "------------Stack------------" << endl;
		cout << "front ->";
		cout.width(7);
		cout << targetNode->data.main_data << endl;

	}
	else if (targetNode == StackRear())
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
Stack::Stack() //constructor
{
	list = (LIST*)malloc(sizeof(LIST));
	//cout << "constructor" << endl;
	list->front = NULL;
	list->rear = NULL;
	list->data_size = 0;
}
Stack::~Stack() //destructor
{
	free(list);
	//cout << "destructor" << endl;
}

int MyStack::Stack::IsEmpty()
{
	
	if (!this->list->data_size)
	{
		return ERROR_EMPTY; //바로 함수종료
	}
	return 0;
}
