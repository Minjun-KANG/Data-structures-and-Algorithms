#include "Queue.h"

using namespace MyQueue;

int main()
{
	Queue *my_queue = new Queue();
	
	while (1)// mode ������ ���� type�� �ް� �ش� �Լ��� ȣ��.
	{
		int state = my_queue->Input_case();
		if ((state & ERROR_INPUT) == ERROR_INPUT)
		{
			cout << "INPUT ERROR" << endl;
		}
		else if ((state & ERROR_EMPTY) == ERROR_EMPTY)
		{
			cout << "EMPTY ERROR" << endl;
		}
		else if ((state & EXIT) == EXIT)
		{
			cout << "End of program" << endl;
			break;
		}
	}
	

}

