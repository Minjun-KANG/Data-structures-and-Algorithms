#include"Myheader.h"
/*
2차원 배열 plane을 갖고, 이를 0으로 초기화 함.
단순히 re_Queen_column()에 plane을 넘겨주며, 이 때 시작행을 0으로 넘겨준다.
또한 re_Queen_column()이 작업한 check 사항이 없다면, 예외처리를 할 수 있다.
*/
int main()
{
	int plane[MAX_SIZE][MAX_SIZE];
	memset(plane, 0, sizeof(plane)); // 모든 행열을 0으로 초기화

	if (!(re_Queen_column(plane, 0))) // 실패시 0을 리턴 
	{
		printf("Not exist of Solution");
	}

	return;
}


