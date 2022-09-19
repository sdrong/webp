#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h> 
typedef struct {
	char music[20];
	char man[20];
	char genre;
	int age;
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	ListNode* head;
	ListNode* tail;
	int size;
}ListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create()
{
	ListType* plist = malloc(sizeof(ListType));
	plist->head = plist->tail = NULL;
	plist->size = 0;
	return plist;
}

ListType* insert_last(ListType* plist, ListNode* p)
{
	p->link = NULL;
	plist->tail->link = p;
	plist->tail = p;
	plist->size++;

	return plist;
}

ListType* insert(ListType* plist)
{
	ListNode* p = malloc(sizeof(ListNode));
	if (p == NULL)
		error("오류");
	printf("노래 제목 입력: ");
	scanf("%s", p->data.music);
	printf("가수 입력:");
	scanf("%s", p->data.man);
	while (1)
	{
		getchar();
		printf("노래 장르 입력(B,C,H,J,T): ");
		scanf("%c", &p->data.genre);
		if (p->data.genre != 'B' && p->data.genre != 'C' && p->data.genre != 'H' && p->data.genre != 'J' && p->data.genre != 'T')
			printf("'B','C','H','J','T'중에 입력하시오\n");
		else
			break;
	}
	printf("노래 발표 년도 입력: ");
	scanf("%d", &p->data.age);

	if (plist->size == 0)
	{
		p->link = NULL;
		plist->head = plist->tail = p;
		plist->size++;
		return plist;
	}
	ListNode* tmp = plist->head;
	if (strcmp(tmp->data.music, p->data.music) > 0)
	{
		p->link = plist->head;
		plist->head = p;
	}
	else
	{
		while (tmp->link != NULL && strcmp(tmp->link->data.music, p->data.music) <= 0)
		{
			tmp = tmp->link;
		}
		if (tmp == NULL)
		{
			plist = insert_last(plist, p);
			return plist;
		}
		else
		{
			p->link = tmp->link;
			tmp->link = p;
		}
	}
	plist->size++;
	return plist;
}

void print_list(ListNode* p)
{
	if (p == NULL)
		return;
	else
	{
		printf("노래 제목: %s\n", p->data.music);
		printf("가수 이름: %s\n", p->data.man);
		printf("노래 장르: %c\n", p->data.genre);
		printf("노래 발표 년도: %d\n", p->data.age);
		printf("===========다음============\n\n\n");
		print_list(p->link);
	}
}

void print_reverse(ListNode* p)
{
	if (p == NULL)
		return;
	else
	{
		print_list(p->link);
		printf("노래 제목: %s\n", p->data.music);
		printf("가수 이름: %s\n", p->data.man);
		printf("노래 장르: %c\n", p->data.genre);
		printf("노래 발표 년도: %d\n", p->data.age);
		printf("===========다음============\n\n\n");
	}
}
int list_length(ListType* plist)
{
	ListNode* p = plist->head;
	int num = 0;
	for (; p != NULL; p = p->link)
		num++;
	return num;
}

ListNode* find_music(ListType* plist)
{
	ListNode* node = plist->head;
	char find[40];
	printf("찾고 싶은 음악명을 입력하시오:");
	scanf("%s", find);
	while (node != NULL)
	{
		if (strcmp(node->data.music, find) == 0)
		{
			printf("찾았습니다.\n");
			return node;
		}
		node = node->link;
	}
	return NULL;
}

ListNode* find_del(ListType* plist)
{
	ListNode* p = plist->head;
	printf("삭제하고 싶은 음악명을 입력하시오:");
	char find[40];
	scanf("%s", find);
	if (strcmp(p->data.music, find)==0)
	{
		plist->head = plist->head->link;
		plist->size--;
		return plist;
	}
	while (p->link != NULL)
	{
		if (strcmp(p->link->data.music, find) == 0)
		{
			ListNode* temp = p->link;
			if (temp->link == NULL)
			{
				temp = NULL;
				p->link = NULL;
				plist->size--;
				plist->tail = p;
				return plist;
			}
			p->link = temp->link;
			if (p->link == NULL)
				plist->tail = p;
		}
		p = p->link;
	}
	plist->size--;
	return plist;
}

ListNode* lately_movie(ListType* plist)
{
	ListNode* node = plist->head;
	if (plist == NULL)
		return NULL;
	ListNode* lately = node;
	for (; node != NULL; node = node->link)
	{
		if (lately->data.age < node->data.age)
			lately = node;
	}
	return lately;
}

void genre_search(ListType* plist)
{
	if (plist == NULL)
		printf("리스트가 비워져있습니다.\n");
	else
	{
		ListNode* node = plist->head;
		char find;
		while (1)
		{
			getchar();
			printf("노래 장르 입력(B,C,H,J,T): ");
			scanf("%c", &find);
			if (find != 'B' && find != 'C' && find != 'H' && find != 'J' && find != 'T')
				printf("'B','C','H','J','T'중에 입력하시오\n");
			else
				break;
		}
		for (; node != NULL; node = node->link)
		{
			if (node->data.genre == find)
			{
				printf("노래 제목: %s\n", node->data.music);
				printf("가수 이름: %s\n", node->data.man);
				printf("노래 장르: %c\n", node->data.genre);
				printf("노래 발표 년도: %d\n", node->data.age);
				printf("===========다음============\n\n\n");
			}
				
		}
	}
	printf("끝\n\n");
}

int main(void)
{
	ListType* plist = NULL;
	plist = create();
	int num;
	bool b = true;
	ListNode* data;
	while (b)
	{
		printf("1.노드 삽입\n2.출력\n3.리버스 출력\n4.길이 구하기\n5.노래 검색\n6.삭제\n7.가장 최근 노래\n8.장르 검색\n그 외.종료\n입력:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			plist = insert(plist);
			break;
		case 2:
			print_list(plist->head);
			break;
		case 3:
			print_reverse(plist->head);
			break;
		case 4:
			printf("길이는 %d\n", list_length(plist));
			break;
		case 5:
			data = find_music(plist);
			if (data == NULL)
				printf("못찾았습니다.\n");
			else
			{
				printf("노래 제목: %s\n", data->data.music);
				printf("가수 이름: %s\n", data->data.man);
				printf("노래 장르: %c\n", data->data.genre);
				printf("노래 발표 년도: %d\n\n", data->data.age);
			}
			break;
		case 6:
			plist = find_del(plist);
			break;
		case 7:
			data = lately_movie(plist);
			if (data == NULL)
				printf("리스트가 비어있습니다.\n");
			else
			{
				printf("노래 제목: %s\n", data->data.music);
				printf("가수 이름: %s\n", data->data.man);
				printf("노래 장르: %c\n", data->data.genre);
				printf("노래 발표 년도: %d\n\n", data->data.age);
			}
			break; 
		case 8:
			genre_search(plist);
			break;
		default:
			printf("종료\n");
			b = false;
			break;
		}
	}
	return 0;
}

// SONG5 MAN5 J 7245 1 SONG3 MAN3 C 5314 1 SONG7 MAN7 J 5311 1 SONG4 MAN4 J 531
// SONG3 MAN3 C 5314
// SONG7 MAN7 J 53141
// SONG4 MAN4 J 531