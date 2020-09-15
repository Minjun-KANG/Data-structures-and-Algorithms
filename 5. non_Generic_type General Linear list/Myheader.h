#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define ERROR_EMPTY 0b0001
#define ERROR_WRONG 0b0010

typedef struct _list
{
	struct _node *cur;
	struct _node *head;
	struct _node *tail;
}LIST;



typedef struct _picture
{
	int year;
	char title[30];
	char name[20];
}PICTURE;
typedef struct _node
{
	PICTURE data;
	struct _node *next;
}NODE;
int switch_input(LIST*, FILE *);
int get_data(FILE *, PICTURE *);
int insert_Node(LIST *, FILE*);
NODE* insert_search(LIST *list, PICTURE *target);
int delete_Node(LIST *);
NODE* search_NODE(LIST *);
void all_print_data(LIST *);
void print_data(PICTURE *);