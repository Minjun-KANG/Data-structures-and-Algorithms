#include "Heap.h"

using namespace MyHeap;

int main()
{
	Heap *heap = new Heap();

	st_HEAP *main_heap = NULL;
	int input;
	
	while (main_heap == NULL) {
		cout << "max size�� �Է��ϼ��� : ";
		cin >> input;
		if (cin.fail())
		{
			cout << "INPUT ERROR" << endl;
			cin.clear();
			cin.ignore(1,'\n');
			continue;
		}
		main_heap = heap->Create(input);
		if (main_heap == NULL)
		{
			cout << "CREATE ERROR" << endl;
		}
	}

	while (1)// mode ������ ���� type�� �ް� �ش� �Լ��� ȣ��.
	{
		int state = heap->Input_case(main_heap);
		if ((state & ERROR_INPUT) == ERROR_INPUT)
		{
			cout << "INPUT ERROR" << endl;
		}
		else if ((state & ERROR_EMPTY) == ERROR_EMPTY)
		{
			cout << "EMPTY ERROR" << endl;
		}
		else if ((state & ERROR_FULL) == ERROR_FULL)
		{
			cout << "FULL ERROR" << endl;
		}
		else if ((state & EXIT) == EXIT)
		{
			cout << "End of program" << endl;
			break;
		}
	}
		
		
}