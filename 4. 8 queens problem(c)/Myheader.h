#pragma once
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 8


/* 
�� �ַ���� ����ϴ� �Լ�
pre - 0 or 1 �� bit pattern�� prameter�� ����
post - 1�̸� ��, 0�̸� ��� �ٲ� ���
*/
void print_plane(int plane[MAX_SIZE][MAX_SIZE]);



int Is_empty(int plane[MAX_SIZE][MAX_SIZE], int row, int col);