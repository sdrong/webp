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
	printf("��ȭ �帣 �Է�(A,C,F,R): ");
	scanf("%c", &p->data.genre);
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

ListType* insert_last(ListType* plist, ListNode*p)
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

void print_list(ListType* plist)
{
	ListNode* p = plist->head;
	for (; p != NULL; p = p->link)
	{
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
		for (ListNode* tmp = base-> link; tmp != NULL; tmp = tmp->link)
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

ListType* add_list(ListType* plist1, ListType* plist2, ListType*plist3)
{
	plist3 = plist1;
	ListNode* p = plist2->head;
	plist3->tail->link = p;
	plist3->tail = plist2->tail;
	plist3->size += plist2->size;
	return plist3;
}

int main(void)
{
	ListType* plist = NULL;
	plist = create();
	int num;
	bool b = true;
	while (b)
	{
		printf("1.�Ǿտ� ����\n2.���ϴ� ��ġ �ڿ� ����\n3.���\n4.���� ���ϱ�\n5.�̸��� ����\n�� ��.����\n�Է�:");
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
			print_list(plist);
			break;
		case 4:
			printf("���̴� %d\n", list_length(plist));
			break;
		default:
			printf("1�� ����\n");
			b = false;
			break;
		}
	}
	ListType* plist2 = NULL;
	plist2 = create();
	b = true;
	while (b)
	{
		printf("1.�Ǿտ� ����\n2.���ϴ� ��ġ �ڿ� ����\n3.���\n4.���� ���ϱ�\n5.�̸��� ����\n�� ��.����\n�Է�:");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			plist2 = insert_first(plist2);
			break;
		case 2:
			plist2 = insert(plist2);
			break;
		case 3:
			print_list(plist2);
			break;
		case 4:
			printf("���̴� %d\n", list_length(plist2));
			break;
		case 5:
			plist2 = sort_list(plist2);
			break;
		default:
			printf("2�� ����\n");
			b = false;
			break;
		}
	}
	ListType* plist3 = NULL;
	plist3 = create();
	b = true;
	plist3 = add_list(plist, plist2, plist3);
	while (b)
	{
		printf("1.���\n2.���� ���ϱ�\n3.�̸��� ����\n�� ��.����\n�Է�:");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			print_list(plist3);
			break;
		case 2:
			printf("���̴� %d\n", list_length(plist3));
			break;
		case 3:
			plist3 = sort_list(plist3);
			break;
		default:
			printf("3�� ����\n");
			b = false;
			break;
		}
	}
	return 0;
}