#include"Myheader.h"
//#include<stdlib.h>

/*
인자로 넘겨받은 row부터, 0~row까지 위, 왼쪽 대각선, 오른쪽 대각선에 값이 있는지 확인함.
pre - prameter로 넘겨받은 plane, row, col
post - 사용 가능여부를 return 가능하면 1 불가능하면 0
*/
int Is_empty(int plane[MAX_SIZE][MAX_SIZE], int row, int col)
{

	/* 현재 작업하려는 row가 사용 중이라면 */
	for (int i = 0; i < col; i++)
	{
		if (plane[row][i])
		{
			return 0;
		}
	}
	/*
	if(plane[row-i] == col - i ) return 0;
	*/

	//받은 index부터 왼쪽(i) 위(j)로 향하는 대각선이 사용중 이라면
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (plane[i][j])
		{
			return 0;
		}
	}

	//받은 index부터 오른쪽(i) 위(j)로 향하는 대각선이 사용중 이라면
	for (int i = row, j = col; i < MAX_SIZE &&j >= 0; i++, j--)
	{
		if (plane[i][j])
		{
			return 0;
		}
	}

	return 1;
}

/*
main에서 호출 함.  
솔루션이 없다면 0을 리턴
pre - 전체 적인 plane과, 작업해야할 col을 인자로 받는다.
post - Is_empty라는 함수로 Queen이 들어갈 수 있는 자리인지 판단하고, 그에 맞게 Queen을 넣는다.
또한, 다음 열에 대하여 작업하기 위해 이를 재귀적으로 호출한다.
위 작업을 수행하는 재귀적인 요소가 끝날 때 마다, check를 리턴하고 종료한다.
여기서, 한 행을 계속하여 backtraking 방법으로 작업하는데, 이 때 더 이상 row를 작업할 것이 없다면
이전에 했던 column을 반복해서 작업한다.
또한 column이 == MAX_SIZE일 때,
print_plane 함수를 호출한다.
*/
int re_Queen_column(int plane[MAX_SIZE][MAX_SIZE], int col)
{
	static int total_opering_count = 0;
	//8개의 열을 다사용 중 이라면, 출력하고 1을 리턴 
	if (col == MAX_SIZE)
	{
		print_plane(plane);
		return 1;
	}

	int check = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (Is_empty(plane, i, col))
		{
			plane[i][col] = 1;
			//printf("%4d - current row = %d, current col = %d, Insert queen!\n", ++total_opering_count, i, col);
			//print_plane(plane);
			check = re_Queen_column(plane, col + 1) || check;
			plane[i][col] = 0; //다시 위에 대한 연산을 하기위함
			//printf("%4d - current row = %d, current col = %d, Delete queen!\n", ++total_opering_count, i, col);
			//print_plane(plane);
		}
		
	}
	return check; // 여기서 0을 리턴한다면 해당 MAX_SIZE에서는, solution이 없음을 의미.
}


