#include "Myheader.h"
//1 1 2 3 5 8 13 21...
/*
N = 1부터 N까지 Finonacci series에 summation

*/
//Fibonacci
/*int main()
{
	int n;
	clock_t start_time = { 0, } , end_time = { 0, };
	float Iter_operating_time, Recur_operationg_time;

	printf("input N : ");
	scanf("%d", &n);

	start_time = clock(); // start 시간 보관

	int Iteration_out = Iteration(n); // function call후, Fibonacci 계산 값을 보관

	end_time = clock(); // end 시간 보관

	Iter_operating_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // function executing time을 계산
	printf("Iteration output : %d, executing time : %f[Sec]\n", Iteration_out, Iter_operating_time); // 출력




	int Recursion_out = 0;
	start_time = clock(); // start 시간 보관
	/*for (int i = 0; i <=n; i++) {
		Recursion_out += Recursion(i);  // function call후, Fibonacci 계산 값을 연속적으로 더함

	
	end_time = clock(); // end 시간 보관
	Recur_operationg_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // function executing time을 계산
	printf("Recursion output : %d, executing time : %f[Sec]\n", Recursion_out, Recur_operationg_time); // 출력
}*/ 


//Factorial
int main()
{
	unsigned long long int n;
	clock_t start_time = { 0, }, end_time = { 0, };
	float Iter_operating_time, Recur_operationg_time;

	printf("input N : ");
	scanf("%lld", &n);

	start_time = clock(); // start 시간 보관

	unsigned long long int Iteration_out = Fac_iter(n); // function call후, Fibonacci 계산 값을 보관

	end_time = clock(); // end 시간 보관

	Iter_operating_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // function executing time을 계산
	printf("Iteration output : %lld, executing time : %f[Sec]\n", Iteration_out, Iter_operating_time); // 출력




	unsigned long long int Recursion_out = 0;
	start_time = clock(); // start 시간 보관
	/*for (int i = 0; i <=n; i++) {
		Recursion_out += Recursion(i);  // function call후, Fibonacci 계산 값을 연속적으로 더함
		*/
	Recursion_out = Fac_recur(n);
	end_time = clock(); // end 시간 보관
	Recur_operationg_time = (float)(end_time - start_time) / CLOCKS_PER_SEC; // function executing time을 계산
	printf("Recursion output : %lld, executing time : %f[Sec]\n", Recursion_out, Recur_operationg_time); // 출력
}