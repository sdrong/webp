#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h> 
typedef struct {
	char movie[20];
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

ListType* insert_first(ListType* plist)
{
	ListNode* p = malloc(sizeof(ListNode));
	if (p == NULL)
		error("오류");
	printf("영화 제목 입력: ");
	scanf("%s", p->data.movie);
	while (1)
	{
		getchar();
		printf("영화 장르 입력(A,C,F,R): ");
		scanf("%c", &p->data.genre);
		if (p->data.genre != 'A' && p->data.genre != 'C' && p->data.genre != 'F' && p->data.genre != 'R')
			printf("'A','C','F','R'중에 입력하시오\n입력:");
		else
			break;
	}
	printf("영화 개봉 년도 입력: ");
	scanf("%d", &p->data.age);
	if (plist->head == NULL)
	{
		p->link = NULL;
		plist->head = plist->tail = p;
		plist->size++;
	}
	else
	{
		p->link = plist->head;
		plist->head = p;
		plist->size++;
	}
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
	printf("영화 제목 입력: ");
	scanf("%s", p->data.movie);
	while (1)
	{
		getchar();
		printf("영화 장르 입력(A,C,F,R): ");
		scanf("%c", &p->data.genre);
		if (p->data.genre != 'A' && p->data.genre != 'C' && p->data.genre != 'F' && p->data.genre != 'R')
			printf("'A','C','F','R'중에 입력하시오\n입력:");
		else
			break;
	}
	printf("영화 개봉 년도 입력: ");
	scanf("%d", &p->data.age);

	if (plist->size == 0)
	{
		p->link = NULL;
		plist->head = plist->tail = p;
		plist->size++;
		return plist;
	}
	printf("원하는 영화제목의 뒤에 저장:");
	char find[20];
	scanf("%s", find);
	ListNode* tmp = plist->head;
	while (tmp != NULL && strcmp(tmp->data.movie, find) != 0)
	{
		tmp = tmp->link;
	}
	if (tmp == NULL)
	{
		printf("찾을 수 없으므로 맨 뒤에 저장 하겠습니다.\n");
		plist = insert_last(plist, p);
		return plist;
	}
	else
	{
		p->link = tmp->link;
		tmp->link = p;
		plist->tail = p;
	}
	plist->size++;
	return plist;
}

ListType* delete_first(ListType* plist)
{
	ListNode* removed;
	if (plist->head == NULL)
		return NULL;
	removed = plist->head;
	plist->head = removed->link;
	free(removed);
	return plist;
}

void print_list(ListNode*p)
{
	if (p == NULL)
		return;
	else
	{
		printf("영화 제목: %s\n", p->data.movie);
		printf("영화 장르: %c\n", p->data.genre);
		printf("영화 개봉 년도: %d\n", p->data.age);
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
		printf("영화 제목: %s\n", p->data.movie);
		printf("영화 장르: %c\n", p->data.genre);
		printf("영화 개봉 년도: %d\n", p->data.age);
		printf("===========다음============\n\n\n");
	}
}
int list_length(ListType* plist)
{
	return plist->size;
}

ListType* sort_list(ListType* plist)
{
	ListNode* base = plist->head;
	for (; base->link != NULL; base = base->link)
	{
		for (ListNode* tmp = base->link; tmp != NULL; tmp = tmp->link)
		{
			if (strcmp(base->data.movie, tmp->data.movie) == 1)
			{
				element temp = base->data;
				base->data = tmp->data;
				tmp->data = temp;
			}
		}
	}
	return plist;
}

ListType* add_list(ListType* plist1, ListType* plist2, ListType* plist3)
{
	plist3 = plist1;
	ListNode* p = plist2->head;
	plist3->tail->link = p;
	plist3->tail = plist2->tail;
	plist3->size += plist2->size;
	return plist3;
}

void find_movie(ListType* plist)
{
	char find[20];
	printf("찾을 영화 제목을 입력:");
	scanf("%s", find);
	ListNode* p = plist->head;
	for(; p != NULL; p = p->link)
	{
		if (strcmp(p->data.movie, find) == 0)
		{
			printf("찾았습니다.\n");
			printf("영화 제목: %s\n", p->data.movie);
			printf("영화 장르: %c\n", p->data.genre);
			printf("영화 개봉 년도: %d\n\n", p->data.age);
			return;
		}
	}
	printf("못찾았습니다.\n");
}

ListType* find_del(ListType* plist)
{
	char find[20];
	printf("찾을 영화 제목을 입력:");
	scanf("%s", find);
	ListNode* p = plist->head;
	ListNode* p2 = p;
	while (strcmp(p->data.movie, find) != 0 && p != NULL)
	{
		p2 = p;
		p = p->link;
	}
	if (strcmp(p->data.movie, plist->head->data.movie) == 0)
	{
		plist = delete_first(plist);
		plist->size--;
		return plist;
	}
	else if (p == NULL)
	{
		printf("삭제할것을 찾지 못하였씁니다.\n");
		return plist;
	}
	ListNode* p3 = p2->link;
	p2->link = p3->link;
	return plist;
}

void lately_movie(ListType* plist)
{
	ListNode* p = plist->head;
	element lately = plist->head->data;
	while (p-> link!= NULL)
	{
		p = p->link;
		if (p->data.age > lately.age)
		{
			lately = p->data;
		}
	}
	printf("최신영화\n");
	printf("영화 제목: %s\n", lately.movie);
	printf("영화 장르: %c\n", lately.genre);
	printf("영화 개봉 년도: %d\n\n", lately.age);
}

void wish_genre(ListType* plist)
{
	char find;
	while (1)
	{
		printf("영화 장르 입력(A,C,F,R): ");
		scanf("%c", &find);
		if (find != 'A' && find != 'C' && find != 'F' && find != 'R')
			printf("'A','C','F','R'중에 입력하시오\n입력:");
		else
			break;
	}
	ListNode* p = plist->head;
	for (; p != NULL; p = p->link)
	{
		if (find == p->data.genre)
		{
			printf("영화 제목: %s\n", p->data.movie);
			printf("영화 장르: %c\n", p->data.genre);
			printf("영화 개봉 년도: %d\n", p->data.age);
			printf("===========다음============\n\n\n");
		}
	}

}
int main(void)
{
	ListType* plist = NULL;
	plist = create();
	int num;
	bool b = true;
	while (b)
	{
		printf("1.맨앞에 삽입\n2.원하는 위치 뒤에 삽입\n3.출력\n4.리버스 출력\n5.길이 구하기\n6.이름순 정렬\n7.영화찾기\n8.특정 영화 삭제\n9.가장 최근영화 조회\n10.원하는 장르 조회\n그 외.종료\n입력:");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			plist = insert_first(plist);
			break;
		case 2:
			plist = insert(plist);
			break;
		case 3:
			print_list(plist->head);
			break;
		case 4:
			print_reverse(plist->head);
			break;
		case 5:
			printf("길이는 %d\n", list_length(plist));
			break;
		case 6:
			plist = sort_list(plist);
			break;
		case 7:
			find_movie(plist);
			break;
		case 8:
			plist = find_del(plist);
			break;
		case 9:
			lately_movie(plist);
			break;
		case 10:
			wish_genre(plist);
			break;
		default:
			printf("종료\n");
			b = false;
			break;
		}
	}
	return 0;
}