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
		error("����");
	printf("��ȭ ���� �Է�: ");
	scanf("%s", p->data.movie);
	while (1)
	{
		getchar();
		printf("��ȭ �帣 �Է�(A,C,F,R): ");
		scanf("%c", &p->data.genre);
		if (p->data.genre != 'A' && p->data.genre != 'C' && p->data.genre != 'F' && p->data.genre != 'R')
			printf("'A','C','F','R'�߿� �Է��Ͻÿ�\n�Է�:");
		else
			break;
	}
	printf("��ȭ ���� �⵵ �Է�: ");
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
		error("����");
	printf("��ȭ ���� �Է�: ");
	scanf("%s", p->data.movie);
	while (1)
	{
		getchar();
		printf("��ȭ �帣 �Է�(A,C,F,R): ");
		scanf("%c", &p->data.genre);
		if (p->data.genre != 'A' && p->data.genre != 'C' && p->data.genre != 'F' && p->data.genre != 'R')
			printf("'A','C','F','R'�߿� �Է��Ͻÿ�\n�Է�:");
		else
			break;
	}
	printf("��ȭ ���� �⵵ �Է�: ");
	scanf("%d", &p->data.age);

	if (plist->size == 0)
	{
		p->link = NULL;
		plist->head = plist->tail = p;
		plist->size++;
		return plist;
	}
	printf("���ϴ� ��ȭ������ �ڿ� ����:");
	char find[20];
	scanf("%s", find);
	ListNode* tmp = plist->head;
	while (tmp != NULL && strcmp(tmp->data.movie, find) != 0)
	{
		tmp = tmp->link;
	}
	if (tmp == NULL)
	{
		printf("ã�� �� �����Ƿ� �� �ڿ� ���� �ϰڽ��ϴ�.\n");
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
		printf("��ȭ ����: %s\n", p->data.movie);
		printf("��ȭ �帣: %c\n", p->data.genre);
		printf("��ȭ ���� �⵵: %d\n", p->data.age);
		printf("===========����============\n\n\n");
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
		printf("��ȭ ����: %s\n", p->data.movie);
		printf("��ȭ �帣: %c\n", p->data.genre);
		printf("��ȭ ���� �⵵: %d\n", p->data.age);
		printf("===========����============\n\n\n");
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
	printf("ã�� ��ȭ ������ �Է�:");
	scanf("%s", find);
	ListNode* p = plist->head;
	for(; p != NULL; p = p->link)
	{
		if (strcmp(p->data.movie, find) == 0)
		{
			printf("ã�ҽ��ϴ�.\n");
			printf("��ȭ ����: %s\n", p->data.movie);
			printf("��ȭ �帣: %c\n", p->data.genre);
			printf("��ȭ ���� �⵵: %d\n\n", p->data.age);
			return;
		}
	}
	printf("��ã�ҽ��ϴ�.\n");
}

ListType* find_del(ListType* plist)
{
	char find[20];
	printf("ã�� ��ȭ ������ �Է�:");
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
		printf("�����Ұ��� ã�� ���Ͽ����ϴ�.\n");
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
	printf("�ֽſ�ȭ\n");
	printf("��ȭ ����: %s\n", lately.movie);
	printf("��ȭ �帣: %c\n", lately.genre);
	printf("��ȭ ���� �⵵: %d\n\n", lately.age);
}

void wish_genre(ListType* plist)
{
	char find;
	while (1)
	{
		printf("��ȭ �帣 �Է�(A,C,F,R): ");
		scanf("%c", &find);
		if (find != 'A' && find != 'C' && find != 'F' && find != 'R')
			printf("'A','C','F','R'�߿� �Է��Ͻÿ�\n�Է�:");
		else
			break;
	}
	ListNode* p = plist->head;
	for (; p != NULL; p = p->link)
	{
		if (find == p->data.genre)
		{
			printf("��ȭ ����: %s\n", p->data.movie);
			printf("��ȭ �帣: %c\n", p->data.genre);
			printf("��ȭ ���� �⵵: %d\n", p->data.age);
			printf("===========����============\n\n\n");
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
		printf("1.�Ǿտ� ����\n2.���ϴ� ��ġ �ڿ� ����\n3.���\n4.������ ���\n5.���� ���ϱ�\n6.�̸��� ����\n7.��ȭã��\n8.Ư�� ��ȭ ����\n9.���� �ֱٿ�ȭ ��ȸ\n10.���ϴ� �帣 ��ȸ\n�� ��.����\n�Է�:");
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
			printf("���̴� %d\n", list_length(plist));
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
			printf("����\n");
			b = false;
			break;
		}
	}
	return 0;
}