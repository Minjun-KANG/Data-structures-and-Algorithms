#include<stdio.h>
#include<string.h>

#define OPERATIONS "+-*/"

void preToPostFix(char* preFixIn, char* exprOut);
int findExprLen(char* exprIn);

int main()
{
	//Local Definitions
	char preFixExpr[256] = "-+*ABC/EF";
	char postFixExpr[256] = "";

	//Statements
	printf("Begin prefix to postfix converstion\n\n");

	preToPostFix(preFixExpr, postFixExpr);
	printf("Prefix expr: %-s\n", preFixExpr);
	printf("Postfix expr: %-s\n", postFixExpr);

	printf("\nEnd prefix to postfix conversion");
	return 0;

}

void preToPostFix(char* preFixIn, char* postFix)
{
	//Local Definitions
	char operator [2];
	char postFix1[256];
	char postFix2[256];
	char temp[256];
	int lenPreFix;

	//statements
	if (strlen(preFixIn) == 1) //operand라는 의미 ,, basecase
	{
		*postFix = *preFixIn;
		*(postFix + 1) = '\0';
		return;
	}// if only operand

	*operator = *preFixIn;
	*(operator + 1) = '\0';

	// Find first expression
	lenPreFix = findExprLen(preFixIn + 1);
	strncpy(temp, preFixIn + 1, lenPreFix);
	*(temp + lenPreFix) = '\0';
	preToPostFix(temp, postFix1);

	//find second expression
	strcpy(temp, preFixIn + 1 + lenPreFix);
	preToPostFix(temp, postFix2);

	//Concatenate to postFix
	strcpy(postFix, postFix1);
	strcat(postFix, postFix2);
	strcat(postFix, operator);

	return;
}

int findExprLen(char* exprIn)
{
	//Local
	int len1;
	int len2;

	//statements
	if (strcspn(exprIn, OPERATIONS) == 0) //오른쪽 문자열안에 있는 문자가 왼쪽 문자열에 하나라도 존재하는가?
		//General case : First char is operator
		//find length of first expression
	{
		len1 = findExprLen(exprIn + 1);
		len2 = findExprLen(exprIn + 1 + len1);

	}
	else
	{
		len1 = len2 = 0;

	}
	return len1 + len2 + 1;
}