#include"Myheader.h"

//1 1 2 3 5 8 13 21...
int Iteration(int n) //Interation 한 방법으로 동작
{
	int sum = 2, temp = 0, state = 2, prev = 1;

	if (n < 2)
	{
		return n;
	}

	for (int i = 2; i < n; i++)
	{
		sum += state;
		temp = prev;
		prev = state;
		state += temp;
	}
	return sum;

}

int Fac_iter(unsigned long long int n)
{
	unsigned long long int res = 1;
	for (int i = 1; i <= n; i++)
	{
		res *= i;
	}
	return res;

}