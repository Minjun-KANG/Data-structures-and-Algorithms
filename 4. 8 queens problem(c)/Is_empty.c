#include"Myheader.h"
//#include<stdlib.h>

/*
���ڷ� �Ѱܹ��� row����, 0~row���� ��, ���� �밢��, ������ �밢���� ���� �ִ��� Ȯ����.
pre - prameter�� �Ѱܹ��� plane, row, col
post - ��� ���ɿ��θ� return �����ϸ� 1 �Ұ����ϸ� 0
*/
int Is_empty(int plane[MAX_SIZE][MAX_SIZE], int row, int col)
{

	/* ���� �۾��Ϸ��� row�� ��� ���̶�� */
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

	//���� index���� ����(i) ��(j)�� ���ϴ� �밢���� ����� �̶��
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (plane[i][j])
		{
			return 0;
		}
	}

	//���� index���� ������(i) ��(j)�� ���ϴ� �밢���� ����� �̶��
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
main���� ȣ�� ��.  
�ַ���� ���ٸ� 0�� ����
pre - ��ü ���� plane��, �۾��ؾ��� col�� ���ڷ� �޴´�.
post - Is_empty��� �Լ��� Queen�� �� �� �ִ� �ڸ����� �Ǵ��ϰ�, �׿� �°� Queen�� �ִ´�.
����, ���� ���� ���Ͽ� �۾��ϱ� ���� �̸� ��������� ȣ���Ѵ�.
�� �۾��� �����ϴ� ������� ��Ұ� ���� �� ����, check�� �����ϰ� �����Ѵ�.
���⼭, �� ���� ����Ͽ� backtraking ������� �۾��ϴµ�, �� �� �� �̻� row�� �۾��� ���� ���ٸ�
������ �ߴ� column�� �ݺ��ؼ� �۾��Ѵ�.
���� column�� == MAX_SIZE�� ��,
print_plane �Լ��� ȣ���Ѵ�.
*/
int re_Queen_column(int plane[MAX_SIZE][MAX_SIZE], int col)
{
	static int total_opering_count = 0;
	//8���� ���� �ٻ�� �� �̶��, ����ϰ� 1�� ���� 
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
			plane[i][col] = 0; //�ٽ� ���� ���� ������ �ϱ�����
			//printf("%4d - current row = %d, current col = %d, Delete queen!\n", ++total_opering_count, i, col);
			//print_plane(plane);
		}
		
	}
	return check; // ���⼭ 0�� �����Ѵٸ� �ش� MAX_SIZE������, solution�� ������ �ǹ�.
}


