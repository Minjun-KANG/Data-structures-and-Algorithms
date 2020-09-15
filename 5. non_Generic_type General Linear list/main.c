#include "Myheader.h"



int main(void) {
	FILE *main_fp = fopen("input.txt", "r");
	LIST *main_list = (LIST *)malloc(sizeof(LIST));
	//초기 값
	main_list->cur = NULL;
	main_list->head = NULL;
	main_list->tail = NULL;

	while (1)// mode 설정에 대한 type을 받고 해당 함수를 호출.
	{
		int stat = switch_input(main_list, main_fp);
		if (stat == ERROR_WRONG)
		{
			printf("INPUT ERROR - 다시 입력하세요\n");
		}
		else if (stat == ERROR_EMPTY)
		{
			printf("더 이상 삽입할 데이터가 없습니다.\n");
			//break;
		}
	}


	return 0;
}