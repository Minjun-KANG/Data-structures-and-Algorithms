#include"Myheader.h"
#define Is_Queen(x) x ? printf("��") : printf("��")

/* �� �ַ���� ����ϴ� �Լ�
pre - 0 or 1 �� bit pattern�� prameter�� ����
post - 1�̸� ��, 0�̸� ��� �ٲ� ���
*/
void print_plane(int plane[MAX_SIZE][MAX_SIZE])
{
	//���� ���� �����, static int ������ ����
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

