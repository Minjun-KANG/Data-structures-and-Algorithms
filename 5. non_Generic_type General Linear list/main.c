#include "Myheader.h"



int main(void) {
	FILE *main_fp = fopen("input.txt", "r");
	LIST *main_list = (LIST *)malloc(sizeof(LIST));
	//�ʱ� ��
	main_list->cur = NULL;
	main_list->head = NULL;
	main_list->tail = NULL;

	while (1)// mode ������ ���� type�� �ް� �ش� �Լ��� ȣ��.
	{
		int stat = switch_input(main_list, main_fp);
		if (stat == ERROR_WRONG)
		{
			printf("INPUT ERROR - �ٽ� �Է��ϼ���\n");
		}
		else if (stat == ERROR_EMPTY)
		{
			printf("�� �̻� ������ �����Ͱ� �����ϴ�.\n");
			//break;
		}
	}


	return 0;
}