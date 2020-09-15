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
		if (newNode->data.year < list->head->data.year) //head보다 작으면,
		{
			newNode->next = list->head; //new_data.next에 head 대입
			list->head = newNode; //head를 new로 바꿈
		}
		else if (newNode->data.year > list->tail->data.year) //tail보다 크면,
		{
			list->tail->next = newNode;//tail에 next 노드를 new노드로 바꿈
			list->tail = newNode;//tail에 newNode 대입. 
		}
		else //general case
		{
			NODE *pPre = insert_search(list, &newNode->data); //pre 값 가져옴.
			newNode->next = pPre->next;
			pPre->next = newNode;
		}
		
	}
	//pPos를 만들어서, 대입해야할 대상 데이터에 위치를 가르키는 변수가 필요할듯? --> search
	list->cur = newNode;
}
NODE* insert_search(LIST *list, PICTURE *target)
{
	NODE *p = list->head;

	while (p->next != NULL) //while (p->next->next != NULL)
	{
		//node가 하나일 때, 예외처리

		if (p->data.year <= target->year && p->next->data.year >= target->year)
		{
			if (p->next->data.year == target->year)
			{
				if ((strcmp(p->next->data.title, target->title)) <= 0) // 찾는 대상이 3번째라면, 2번째 데이터를 리턴함.
				{
					//title이 더 작거나 같다면 문제없음
					p = p->next;
					break;
				}
				/*else //새로들어온 newNode의 data의 title이 더 크다면,
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
		printf("data가 없습니다.\n");
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
		//node가 하나일 때, 예외처리

		if (p->next->data.year == target.year)
		{
			if ((strcmp(p->next->data.title, target.title)) == 0) // 찾는 대상이 3번째라면, 2번째 데이터를 리턴함.
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
	print_data(&p->next->data); //출력은 2번째가 아닌 Target인 3번째로
	
	return p;
}
int delete_Node(LIST *list) {
	NODE *pPre = search_NODE(list);
	if (pPre == NULL)
	{
		return -1;
	}
	NODE *pCur = pPre->next; //지울 대상
	NODE *pLoc = pCur->next; // 다음 값
	if (pCur->data.year == list->tail->data.year) // 지울 대상이 tail이라면,
	{
		if ((strcmp(pCur->data.title, list->tail->data.title)) == 0)
		{
			list->tail = pPre; //tail을 전 값으로 바꿈
		}

	}
	else if (pCur->data.year == list->head->data.year) // 지울 대상이 head라면,
	{
		if ((strcmp(pCur->data.title, list->head->data.title)) == 0)
		{
			list->head = pLoc; //head를 다음 값으로 바꿈
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

		 If input key is ‘P’, print all list of awarded pictures
		 If input key is ‘S’, search for a year
		 If input key is ‘I’, insert a node to the list         //임의의  “년도, 영화제목, 감독이름”을 사용자로부터(키보드) 입력 받아 삽입
		 If input key is ‘D’, delete a node from the list   // 임의의  “년도, 영화제목, 감독이름”을 사용자로부터(키보드) 입력 받아 삭제
		 If input key is ‘Q’, quit
	*/

	int return_num = 0;
	char type, buf;
	printf("INPUT : ");
	scanf("%c", &type);
	buf = getchar(); //%c에 대한 buf 비움.
	if (type <= 'z' && type >= 'a') { type -= 32; } // 소문자 예외처리

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
		printf("\n프로그램 종료\n");
		exit(1);
		break;

	default:
		return_num = return_num | ERROR_WRONG; // 나머지 입력문자에 대해 예외처리.
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
void print_data(PICTURE *data) //특정 i번째의 data를 출력
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
	if (feof(fp)) //fp가 파일의 끝이 아니라면, 
	{
		return -1;
	}
	fscanf(fp, "%d, ", &data->year);
	fscanf(fp, "%[^,]s", data->title);
	fscanf(fp, ", %[^\n]s", data->name);

	memcpy(p, data, sizeof(PICTURE));
}