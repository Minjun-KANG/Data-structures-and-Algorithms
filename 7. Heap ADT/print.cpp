#include "Heap.h"

using namespace MyHeap;

int MyHeap::Heap::Input_case(st_HEAP *heap)
{
	int input_data;
	int re_carry = 0;
	char in;
	cout << "Input case : ";
	cin >> in;
	if (in <= 'z' && in >= 'a') { in -= 32; } // �ҹ��� ����ó��

	switch (in)
	{
	case 'P': // print all list of data
		print_shape(heap);
		break;

	case 'I': // inseat part
		this->cnt++;
		cout << "data : ";
		cin >> input_data;
		if (Insert(heap, input_data))
		{
			re_carry = re_carry | ERROR_FULL;
		}
		else
		{
			cout << "Insert Success" << endl;
		}
		break;

	case 'D':
		int out_data;
		if (Delete(heap, &out_data))
		{
			re_carry = re_carry | ERROR_EMPTY;
		}
		else
		{
			cout << "The deleted data is "<< out_data << endl;
			cout << "Delete Success" << endl;
		}
		break;

	case 'S':
		cout << "k : ";
		cin >> input_data;
		if (SelectK(heap, input_data-1))
		{
			re_carry = re_carry | ERROR_EMPTY;
		}
		else
		{
			//cout << out_data << endl;
			cout << "Select Success" << endl;
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

void MyHeap::Heap::print_shape(st_HEAP *heap)
{
	
	int level = ceil(log2(heap->maxSize)) - 1; // level�� ����,
	int start_point = heap->maxSize;
	int pre_point = start_point;
	int cur = 0;
	//(int)pow(2, ceil(log2(maxSize)))
	for (int i = 0; i <= level; i++) {
		//cout.width(start_point/=2);
		//cout << "";
		for (int j = 1; j <= pow(2,i); j++, cur++)
		{
			if (j == 1) {
				cout.width(start_point);
			}
			if (heap->heapAry[cur].data) {
				cout << heap->heapAry[cur].data;
			}
			else {
				cout << " ";
			}
			cout.width(pre_point);
			cout << "";
		}
		pre_point = start_point;
		start_point /= 2;
		cout << endl;
	}

}