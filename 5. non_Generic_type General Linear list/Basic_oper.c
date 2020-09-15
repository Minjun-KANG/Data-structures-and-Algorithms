#include"Myheader.h"

int insert_Node(LIST *list, FILE *fp) {
	NODE *newNode = (NODE *)malloc(sizeof(NODE));

	if ((get_data(fp, &newNode->data)) == -1)
	{
		return -1;
	}

	newNode->next = NULL;
	if (list->head == NULL && list->tail == NULL)
		list->head = list->tail = newNode;
	else { 
		/*list->tail->next = newNode;
		list->tail = newNode;*/
		if (newNode->data.year < list->head->data.year) //head���� ������,
		{
			newNode->next = list->head; //new_data.next�� head ����
			list->head = newNode; //head�� new�� �ٲ�
		}
		else if (newNode->data.year > list->tail->data.year) //tail���� ũ��,
		{
			list->tail->next = newNode;//tail�� next ��带 new���� �ٲ�
			list->tail = newNode;//tail�� newNode ����. 
		}
		else //general case
		{
			NODE *pPre = insert_search(list, &newNode->data); //pre �� ������.
			newNode->next = pPre->next;
			pPre->next = newNode;
		}
		
	}
	//pPos�� ����, �����ؾ��� ��� �����Ϳ� ��ġ�� ����Ű�� ������ �ʿ��ҵ�? --> search
	list->cur = newNode;
}
NODE* insert_search(LIST *list, PICTURE *target)
{
	NODE *p = list->head;

	while (p->next != NULL) //while (p->next->next != NULL)
	{
		//node�� �ϳ��� ��, ����ó��

		if (p->data.year <= target->year && p->next->data.year >= target->year)
		{
			if (p->next->data.year == target->year)
			{
				if ((strcmp(p->next->data.title, target->title)) <= 0) // ã�� ����� 3��°���, 2��° �����͸� ������.
				{
					//title�� �� �۰ų� ���ٸ� ��������
					p = p->next;
					break;
				}
				/*else //���ε��� newNode�� data�� title�� �� ũ�ٸ�,
				{
					
					break;
				}*/
			}
			break;
		}
		p = p->next;
	}
	return p;
}
NODE* search_NODE(LIST *list)
{

	NODE *p = list->head;
	if (p == NULL)
	{
		printf("data�� �����ϴ�.\n");
		return NULL;
	}
	PICTURE target;
	printf("search target ex : [year], [Picture name], [Director] : ");
	scanf("%d, ", &target.year);
	scanf("%[^,]s", target.title);
	scanf(", %[^\n]s", target.name);
	char buf = getchar();
	//scanf("%d, %[^,]s, %[^\n]s", &target.year, target.title, target.name);
	while (p->next != NULL) //while (p->next->next != NULL)
	{
		//node�� �ϳ��� ��, ����ó��

		if (p->next->data.year == target.year)
		{
			if ((strcmp(p->next->data.title, target.title)) == 0) // ã�� ����� 3��°���, 2��° �����͸� ������.
			{
				break;
			}
		}
		p = p->next;
	}
	if (p->next == NULL)
	{
		return p;
	}
	
	printf("-- target data --\n");
	print_data(&p->next->data); //����� 2��°�� �ƴ� Target�� 3��°��
	
	return p;
}
int delete_Node(LIST *list) {
	NODE *pPre = search_NODE(list);
	if (pPre == NULL)
	{
		return -1;
	}
	NODE *pCur = pPre->next; //���� ���
	NODE *pLoc = pCur->next; // ���� ��
	if (pCur->data.year == list->tail->data.year) // ���� ����� tail�̶��,
	{
		if ((strcmp(pCur->data.title, list->tail->data.title)) == 0)
		{
			list->tail = pPre; //tail�� �� ������ �ٲ�
		}

	}
	else if (pCur->data.year == list->head->data.year) // ���� ����� head���,
	{
		if ((strcmp(pCur->data.title, list->head->data.title)) == 0)
		{
			list->head = pLoc; //head�� ���� ������ �ٲ�
		}

	}
	else { //general case
		
		pPre->next = pLoc;
	}
	return 1;
}

int switch_input(LIST*list, FILE *fp)
{
	//PICTURE target;
	/*
	 Input a key from user

		 If input key is ��P��, print all list of awarded pictures
		 If input key is ��S��, search for a year
		 If input key is ��I��, insert a node to the list         //������  ���⵵, ��ȭ����, �����̸����� ����ڷκ���(Ű����) �Է� �޾� ����
		 If input key is ��D��, delete a node from the list   // ������  ���⵵, ��ȭ����, �����̸����� ����ڷκ���(Ű����) �Է� �޾� ����
		 If input key is ��Q��, quit
	*/

	int return_num = 0;
	char type, buf;
	printf("INPUT : ");
	scanf("%c", &type);
	buf = getchar(); //%c�� ���� buf ���.
	if (type <= 'z' && type >= 'a') { type -= 32; } // �ҹ��� ����ó��

	switch (type)
	{
	case 'P': // print all list of data
		all_print_data(list);
		break;
	case 'S':
	
		
		search_NODE(list);
		break;
	case 'I': // inseat part

		if (insert_Node(list, fp) == -1)
		{
			return_num = return_num | ERROR_EMPTY;
		}
		else
		{
			printf("Insert Success!\n");
			print_data(&list->cur->data);
		}
		break;
	case 'D':
		if ((delete_Node(list)) == -1)
		{
			return_num = return_num | ERROR_WRONG;
		}

		break;
	case 'Q':
		printf("\n���α׷� ����\n");
		exit(1);
		break;

	default:
		return_num = return_num | ERROR_WRONG; // ������ �Է¹��ڿ� ���� ����ó��.
	}
	return return_num;
}














void all_print_data(LIST *list) {
	NODE *p = list->head;
	while (p != NULL) {
		print_data(&p->data);
		p = p->next;
	}

}
void print_data(PICTURE *data) //Ư�� i��°�� data�� ���
{
	printf("-----------------------------\n");
	printf("YEAR  : %d\n", data->year);
	printf("TITLE : %s\n", data->title);
	printf("NAME  : %s\n", data->name);
	printf("------------------------------\n");
}
int get_data(FILE *fp, PICTURE *p)
{
	PICTURE *data = (PICTURE*)malloc(sizeof(PICTURE));
	if (feof(fp)) //fp�� ������ ���� �ƴ϶��, 
	{
		return -1;
	}
	fscanf(fp, "%d, ", &data->year);
	fscanf(fp, "%[^,]s", data->title);
	fscanf(fp, ", %[^\n]s", data->name);

	memcpy(p, data, sizeof(PICTURE));
}