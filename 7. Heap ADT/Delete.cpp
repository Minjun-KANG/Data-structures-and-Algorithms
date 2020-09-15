#include "Heap.h"

using namespace MyHeap;


bool MyHeap::Heap::Delete(st_HEAP *heap, int *out_data)
{
	if (IsEmpty(heap)) // heap empty
		return 1;

	*out_data = heap->heapAry[0].data;
	heap->heapAry[0].data = heap->heapAry[heap->last].data; //root 를 제거하기위한 condition
	heap->heapAry[heap->last].data = 0;
	(heap->last)--;
	(heap->size)--;
	
	ReHeapDown(heap, 0);
	
	return 0;

}
void MyHeap::Heap::ReHeapDown(st_HEAP *heap, int index)
{
	int temp;
	if (index < 0 || index >= heap->size) //error case
		return;

	if (index * 2 + 1 < heap->size) {// left subtree 존재?

		int maxChild = index * 2 + 1; // maxchild is left
		
		if (maxChild + 1 < heap->size // right subtree 존재?
			&& heap->heapAry[maxChild + 1].data > heap->heapAry[maxChild].data) //Right subtree > left subtree
			maxChild++; // if right > left, maxchild is right
		
		if (heap->heapAry[maxChild].data > heap->heapAry[index].data) { //true: general case
			temp = heap->heapAry[index].data; //false: base case
			//print_shape(heap);
			heap->heapAry[index].data = heap->heapAry[maxChild].data;
			//print_shape(heap);
			heap->heapAry[maxChild].data = temp;
			//print_shape(heap);
			//
			//heap->heapAry[index].data = 0;
			//
			//print_shape(heap);
			ReHeapDown(heap, maxChild);
		}

	}
}


bool MyHeap::Heap::Destroy(st_HEAP *heap)
{
	free(heap->heapAry); //Destory
	return false;
}


