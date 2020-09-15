#include "Heap.h"

using namespace MyHeap;


Heap::Heap()
{
	this->cnt = 0;
}
Heap::~Heap()
{
}

bool MyHeap::Heap::IsFull(st_HEAP * heap)
{
	if (heap->size >= heap->maxSize)
		return 1;
	else
		return 0;
}


int MyHeap::Heap::Count(st_HEAP * target_Heap)
{
	return 0;
}


bool MyHeap::Heap::IsEmpty(st_HEAP *heap)
{
	if (heap->size == 0) //empty
		return 1;
	else
		return 0;
}

bool  MyHeap::Heap::SelectK(st_HEAP *heap, int k)
{
	
	int out_data;
	int *temp = (int*)malloc(sizeof(int)*(k+1));
	 
	if (k > heap->size)
		return 1; //error

	for (int i = 0; i < k; i++)
	{
		temp[i] = heap->heapAry[0].data;
		Delete(heap, &out_data);
	}
	cout << k+1 << "th is : " << heap->heapAry[0].data << endl;

	//Reconstruct heap
	for (int i = 0; i < k; i++)
	{
		Insert(heap, temp[i]);
	}
	return 0;
}


