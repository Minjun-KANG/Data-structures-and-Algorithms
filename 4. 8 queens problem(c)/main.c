#include"Myheader.h"
/*
2���� �迭 plane�� ����, �̸� 0���� �ʱ�ȭ ��.
�ܼ��� re_Queen_column()�� plane�� �Ѱ��ָ�, �� �� �������� 0���� �Ѱ��ش�.
���� re_Queen_column()�� �۾��� check ������ ���ٸ�, ����ó���� �� �� �ִ�.
*/
int main()
{
	int plane[MAX_SIZE][MAX_SIZE];
	memset(plane, 0, sizeof(plane)); // ��� �࿭�� 0���� �ʱ�ȭ

	if (!(re_Queen_column(plane, 0))) // ���н� 0�� ���� 
	{
		printf("Not exist of Solution");
	}

	return;
}


