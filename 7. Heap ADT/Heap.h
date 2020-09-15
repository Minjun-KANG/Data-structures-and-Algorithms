#pragma once

//Heap.h
#include <iostream>
#include <math.h> //ceil 과 pow, log2 사용


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
		pre - order조건을 만족하지 못한, target_Heap을 넘겨받음.
			  이 때, 해당 값은 all > k의 조건을 가지고 있음.
		post - 이에 대한 order를 정렬
		
		if(newNode not the root) // if newNode is root : base case
			set parent to parent of newnode
			if(newNode data > parent data)
				exchange newNode and parent
				reheapup()
			end if
		endif
		*/
		void ReHeapDown(st_HEAP* heap, int root); 
		//이는 psuedo code를 작성했으나, 자료소실로 인해 미기제
		/*
		pre - heap과 root node를 넘겨받음
		post - 이에대한 order를 결정
		*/
	public:

		Heap(); //Constructor
		~Heap();//Destructor
		bool IsFull(st_HEAP* heap); // Full state시 1 return, 아니면 0 
		bool IsEmpty(st_HEAP* heap); // Empty state시 1 return, 아니면 0
		int Count(st_HEAP* heap); //호출지점까지의 Node의 갯수 return

		int Input_case(st_HEAP *heap);
		void print_shape(st_HEAP *heap);
		/*
		pre - st_DATA(data)를 받음.
		post - Binary tree 구조로 출력
		*/

		bool Insert(st_HEAP *heap, int target_data);
		/* error 발생 시, 1 return, 아니면 0 
		pre - st_DATA(data)과, 입력 대상 data를 넘겨받음.
		post - shape에 의거하여 data를 input 후, ReheapUp을 이용하여 order에 맞춤.
		*/

		bool Delete(st_HEAP *heap, int *out_data);
		/* error 발생 시, 1 return, 아니면 0
		pre - st_DATA(data)과, 삭제 대상 data를 넘겨받음.
		post - shape에 의거하여 data를 input 후, ReheapDown을 이용하여 order에 맞춤.
		*/

		st_HEAP* Create(int maxSize);
		/* error 발생 시, nullptr return, 아니면 heap
		pre - maxSize를 넘겨받음.
		post - st_HEAP 생성, 할당 후 return;
		*/

		bool Destroy(st_HEAP* heap);
		/* error 발생 시, 1 return, 아니면 0.
		pre - st_HEAP을 넘겨받음.
		post - 할당해제 후 리턴.
		*/
		
		bool SelectK(st_HEAP *heap, int k);
		/* k번째로 큰 수를 찾기위함
		pre - heap, k, last node의 값을 가져옴
		post - k번째로 큰 수를 바로 출력
		
		SelectK(heap, k, heapLast)//heapLast is Last node index
			if ( k > heap size)
				return false
			end if

			set origHeapSize to heapLast + 1
			loop (k times) // k번
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



