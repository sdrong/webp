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

ListType* insert_first(ListType* plist)
{
	ListNode* p = malloc(sizeof(ListNode));
	if (p == NULL)
		error("����");
	printf("�뷡 ���� �Է�: ");
	scanf("%s", p->data.music);
	printf("���� �Է�:");
	scanf("%s", p->data.man);
	while (1)
	{
		getchar();
		printf("�뷡 �帣 �Է�(B,C,H,J,T): ");
		scanf("%c", &p->data.genre);
		if (p->data.genre != 'B' && p->data.genre != 'C' && p->data.genre != 'H' && p->data.genre != 'J' && p->data.genre != 'T')
			printf("'B','C','H','J','T'�߿� �Է��Ͻÿ�\n�Է�:");
		else
			break;
	}
	printf("�뷡 ��ǥ �⵵ �Է�: ");
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
	printf("�뷡 ���� �Է�: ");
	scanf("%s", p->data.music);
	printf("���� �Է�:");
	scanf("%s", p->data.man);
	while (1)
	{
		getchar();
		printf("�뷡 �帣 �Է�(B,C,H,J,T): ");
		scanf("%c", &p->data.genre);
		if (p->data.genre != 'B' && p->data.genre != 'C' && p->data.genre != 'H' && p->data.genre != 'J' && p->data.genre != 'T')
			printf("'B','C','H','J','T'�߿� �Է��Ͻÿ�\n�Է�:");
		else
			break;
	}
	printf("�뷡 ��ǥ �⵵ �Է�: ");
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
			printf("ã�� �� �����Ƿ� �� �ڿ� ���� �ϰڽ��ϴ�.\n");
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
		printf("�뷡 ����: %s\n", p->data.music);
		printf("���� �̸�: %s\n", p->data.man);
		printf("�뷡 �帣: %c\n", p->data.genre);
		printf("�뷡 ��ǥ �⵵: %d\n", p->data.age);
		printf("===========����============\n\n\n");
		print_list(p->link);
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

int main(void)
{
	ListType* plist = NULL;
	plist = create();
	int num;
	bool b = true;
	while (b)
	{
		printf("1.�Ǿտ� ����\n2.���ϴ� ��ġ �ڿ� ����\n3.���\n4.���� ���ϱ�\n�� ��.����\n�Է�:");
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
			printf("���̴� %d\n", list_length(plist));
			break;
		default:
			printf("����\n");
			b = false;
			break;
		}
	}
	return 0;
}