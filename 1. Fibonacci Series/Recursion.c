#include"Myheader.h"

int Recursion(int n) //Recursive 한 방법으로 동작
{
	if (n == 1) //case 1
	{
		return 1;
	}
	else if(n == 0) //case 2
	{
		return 0;
	}
	else //general case
	{
		return Recursion(n - 1) + Recursion(n - 2);
	}
	
}

int Fac_recur(unsigned long long int n)
{
	if (n == 1) //case 1
	{
		return 1;
	}
	else //case 2
	{
		return n * Fac_recur(n - 1);
	}
}