#include<stdio.h>


void top(int *binary, int *index);
void push(int *binary, int *decimal, int *index);
void pop(int *binary, int *index);

int main()//non recurisve
{

	int flag = 0;
	int top_value = -1;
	int decimal_vaule = 300;

	printf("decimal value = %d\n", decimal_vaule);
	if (decimal_vaule < 0) // 양의 정수만 입력 가능
	{
		decimal_vaule = ~decimal_vaule + 1;
	}

	int binary[32];
	for (int i = 0; i < 32; i++)
	{
		binary[i] = -1;
	}
	
	for (int i = 0; i < 32; i++) {
		push(binary, &decimal_vaule, &top_value);
	}
	
	for (int i = 0; i < 10; i++)
	{
		pop(binary, &top_value);
		if (!((i + 1) % 4))
		{
			if (i == 31) {
				printf("\n\n"); continue;
			}
			printf("_");
		}
	}
	top(binary, &top_value);
	
}

void top(int *binary, int *index) // becareful empty // 
{
	if (*index == -1)
	{
		printf("\nSTACK is empty\n");
		return;
	}
	printf("\nTOP index is %d\n", binary[*index]);
}
void push(int *binary, int *decimal, int *index) //in becareful overflow
{
	if (*index == 31)
	{
		printf("STACK is full - overflow\n");
		return;
	}
	(*index)++;
	binary[*index] = *decimal % 2;
	*decimal /= 2;

}
void pop(int *binary, int *index) // out becareful underflow
{
	if (*index == -1)
	{
		printf("STACK is empty - underflow\n");
		return;
	}
	
	printf("%d", binary[*index]);
	binary[*index] = -1; //delete
	(*index)--;
}

/*
int main()//Using array
{
	int a = 2147483647;
	//int a = 4;
	int binary[32] = { 0, };

	for (int i = 0; i < 32; i++) {
		binary[i] = a % 2; //binary[0]인 배열 첫번째 칸에 2^0 자리 수 부터 2^31 까지 순차적으로 입력 
		a /= 2;
	}

	for (int i = 32; i > 0; i--) //Last input First output 
	{
		printf("%d", binary[(i - 1)]); //binary[31]인 배열 맨 마지막 칸 즉 2^31부터 출력 
		if (!((i - 1) % 4))
		{
			if (i == 1) continue;
			printf("_");
		}
	}


}
*/

/*
int main()
{
	unsigned int a = 2147483647;  //decimal value
	unsigned int hex = 0x80000000; //filter value

	for (int i = 32; i > 0; i--)
	{
		printf("%d", (a & hex) >> (i - 1));
		hex = hex >> 1;

		if (!((i - 1) % 4)) // 4자리수 마다 _ 출력
		{
			if (i == 1) continue;
			printf("_");
		}
	}

}*/
