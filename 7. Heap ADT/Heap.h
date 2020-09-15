#pragma once

//Heap.h
#include <iostream>
#include <math.h> //ceil �� pow, log2 ���


#define ERROR_INPUT 0b0001
#define ERROR_EMPTY 0b0010
#define ERROR_FULL 0b0100
#define EXIT 0b1000


using namespace std;

namespace MyHeap
{
	typedef struct _st_heap
	{
		struct _st_data *heapAry;
		int last;
		int size;
		int maxSize;
	}st_HEAP;

	typedef struct _st_data
	{
		int data;
	}st_DATA;


	class Heap
	{
	private:
		int cnt;
		void ReHeapUp(st_HEAP* heap, int index);
		/*
		pre - order������ �������� ����, target_Heap�� �Ѱܹ���.
			  �� ��, �ش� ���� all > k�� ������ ������ ����.
		post - �̿� ���� order�� ����
		
		if(newNode not the root) // if newNode is root : base case
			set parent to parent of newnode
			if(newNode data > parent data)
				exchange newNode and parent
				reheapup()
			end if
		endif
		*/
		void ReHeapDown(st_HEAP* heap, int root); 
		//�̴� psuedo code�� �ۼ�������, �ڷ�ҽǷ� ���� �̱���
		/*
		pre - heap�� root node�� �Ѱܹ���
		post - �̿����� order�� ����
		*/
	public:

		Heap(); //Constructor
		~Heap();//Destructor
		bool IsFull(st_HEAP* heap); // Full state�� 1 return, �ƴϸ� 0 
		bool IsEmpty(st_HEAP* heap); // Empty state�� 1 return, �ƴϸ� 0
		int Count(st_HEAP* heap); //ȣ������������ Node�� ���� return

		int Input_case(st_HEAP *heap);
		void print_shape(st_HEAP *heap);
		/*
		pre - st_DATA(data)�� ����.
		post - Binary tree ������ ���
		*/

		bool Insert(st_HEAP *heap, int target_data);
		/* error �߻� ��, 1 return, �ƴϸ� 0 
		pre - st_DATA(data)��, �Է� ��� data�� �Ѱܹ���.
		post - shape�� �ǰ��Ͽ� data�� input ��, ReheapUp�� �̿��Ͽ� order�� ����.
		*/

		bool Delete(st_HEAP *heap, int *out_data);
		/* error �߻� ��, 1 return, �ƴϸ� 0
		pre - st_DATA(data)��, ���� ��� data�� �Ѱܹ���.
		post - shape�� �ǰ��Ͽ� data�� input ��, ReheapDown�� �̿��Ͽ� order�� ����.
		*/

		st_HEAP* Create(int maxSize);
		/* error �߻� ��, nullptr return, �ƴϸ� heap
		pre - maxSize�� �Ѱܹ���.
		post - st_HEAP ����, �Ҵ� �� return;
		*/

		bool Destroy(st_HEAP* heap);
		/* error �߻� ��, 1 return, �ƴϸ� 0.
		pre - st_HEAP�� �Ѱܹ���.
		post - �Ҵ����� �� ����.
		*/
		
		bool SelectK(st_HEAP *heap, int k);
		/* k��°�� ū ���� ã������
		pre - heap, k, last node�� ���� ������
		post - k��°�� ū ���� �ٷ� ���
		
		SelectK(heap, k, heapLast)//heapLast is Last node index
			if ( k > heap size)
				return false
			end if

			set origHeapSize to heapLast + 1
			loop (k times) // k��
				set tempData to root data
				deleteHeap (heap, heapLast, dataOut)
				move tempData to heapLast + 1
			end loop
			move root data to holdOut

			//Reconstruct heap
			loop (while heapLast < origHeapSize)
				increment heapLast
				reheapUp(heap, heapLast)
			end loop
			return holdOut
			end selectK


		*/
	};

}



