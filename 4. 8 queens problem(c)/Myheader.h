#pragma once
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 8


/* 
한 솔루션을 출력하는 함수
pre - 0 or 1 인 bit pattern을 prameter로 받음
post - 1이면 ★, 0이면 □로 바꿔 출력
*/
void print_plane(int plane[MAX_SIZE][MAX_SIZE]);



int Is_empty(int plane[MAX_SIZE][MAX_SIZE], int row, int col);