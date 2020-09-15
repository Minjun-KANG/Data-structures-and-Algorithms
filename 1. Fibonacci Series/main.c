#include "Myheader.h"
//1 1 2 3 5 8 13 21...
/*
N = 1���� N���� Finonacci series�� summation

*/
//Fibonacci
/*int main()
{
	int n;
	clock_t start_time = { 0, } , end_time = { 0, };
	float Iter_operating_time, Recur_operationg_time;

	printf("input N : ");
	scanf("%d", &n);

	start_time = clock(); // start �ð� ����

	int Iteration_out = Iteration(n); // function call��, Fibonacci ��� ���� ����

	end_time = clock(); // end �ð� ����

	Iter_operating_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // function executing time�� ���
	printf("Iteration output : %d, executing time : %f[Sec]\n", Iteration_out, Iter_operating_time); // ���




	int Recursion_out = 0;
	start_time = clock(); // start �ð� ����
	/*for (int i = 0; i <=n; i++) {
		Recursion_out += Recursion(i);  // function call��, Fibonacci ��� ���� ���������� ����

	
	end_time = clock(); // end �ð� ����
	Recur_operationg_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // function executing time�� ���
	printf("Recursion output : %d, executing time : %f[Sec]\n", Recursion_out, Recur_operationg_time); // ���
}*/ 


//Factorial
int main()
{
	unsigned long long int n;
	clock_t start_time = { 0, }, end_time = { 0, };
	float Iter_operating_time, Recur_operationg_time;

	printf("input N : ");
	scanf("%lld", &n);

	start_time = clock(); // start �ð� ����

	unsigned long long int Iteration_out = Fac_iter(n); // function call��, Fibonacci ��� ���� ����

	end_time = clock(); // end �ð� ����

	Iter_operating_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // function executing time�� ���
	printf("Iteration output : %lld, executing time : %f[Sec]\n", Iteration_out, Iter_operating_time); // ���




	unsigned long long int Recursion_out = 0;
	start_time = clock(); // start �ð� ����
	/*for (int i = 0; i <=n; i++) {
		Recursion_out += Recursion(i);  // function call��, Fibonacci ��� ���� ���������� ����
		*/
	Recursion_out = Fac_recur(n);
	end_time = clock(); // end �ð� ����
	Recur_operationg_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // function executing time�� ���
	printf("Recursion output : %lld, executing time : %f[Sec]\n", Recursion_out, Recur_operationg_time); // ���
}