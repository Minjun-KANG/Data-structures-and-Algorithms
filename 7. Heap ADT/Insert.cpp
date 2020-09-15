#include "Heap.h"

using namespace MyHeap;

st_HEAP* MyHeap::Heap::Create(int maxSize)
{
	if (!maxSize) // input error
	{
		return NULL;
	}
	st_HEAP* heap = (st_HEAP*)malloc(sizeof(st_HEAP));
	if (!heap)
		return NULL; //비정상 종료
	heap->last = -1; //root node를 0으로 하기위함,
	heap->size = 0; // 단순 scalar

	// Force heap size to power of 2 -1 // 1, 3, 7, ………
	heap->maxSize = (int)pow(2, ceil(log2(maxSize))) - 1; //각 level마다 해당 node는 2의 level승 개의 node를 가질 수 있음.
	heap->heapAry = (st_DATA*)calloc(heap->maxSize, sizeof(st_DATA));
	return heap;
}

bool MyHeap::Heap::Insert(st_HEAP *heap, int target_data)
{
	if (IsFull(heap)) // full이면 1
		return 1; //exception -> 바로종료로 이어짐.

	++(heap->last);
	++(heap->size);
	heap->heapAry[heap->last].data = target_data;
	ReHeapUp(heap, heap->size - 1);
	return 0;
}
void MyHeap::Heap::ReHeapUp(st_HEAP * heap, int index)
{
	/*
	if(newNode not the root) // if newNode is root : base case
		set parent to parent of newnode
		if(newNode data > parent data)
			exchange newNode and parent
			reheapup()
		end if
	endif
	*/
	int temp;
	int p_index = (index - 1) / 2;
	if (index <= 0 || index >= heap->size) //error case
		return;
	if (heap->heapAry[index].data > heap->heapAry[p_index].data) {
		temp = heap->heapAry[index].data;
		heap->heapAry[index].data = heap->heapAry[p_index].data;
		heap->heapAry[p_index].data = temp;
		ReHeapUp(heap, p_index);
	}

}