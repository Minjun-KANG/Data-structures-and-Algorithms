#include"Myheader.h"
#define Is_Queen(x) x ? printf("★") : printf("□")

/* 한 솔루션을 출력하는 함수
pre - 0 or 1 인 bit pattern을 prameter로 받음
post - 1이면 ★, 0이면 □로 바꿔 출력
*/
void print_plane(int plane[MAX_SIZE][MAX_SIZE])
{
	//전역 변수 사용대신, static int 변수로 선언
	static int k = 1;
	printf("------ %d ------\n", k++);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			Is_Queen(plane[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

