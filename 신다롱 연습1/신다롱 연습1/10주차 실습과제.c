#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h> 
typedef struct {
	char music[20];
	char man[20];
	char genre;
	int age;
	int time;
}element;

typedef struct DListNode {
	element data;
	struct DListNode* llink, *rlink;
}DListNode;

DListNode* current;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(DListNode* head)
{
	head->llink = head;
	head->rlink = head;
}

DListNode* insert_first(DListNode* head)
{
	DListNode* p = malloc(sizeof(DListNode));
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
	p->rlink = head->rlink;
	p->llink = head;
	head->rlink->llink = p;
	head->rlink = p;
	return head;
}

DListNode* insert_last(DListNode* head, DListNode* p)
{
	p->rlink = head;
	p->llink = head->llink;
	head->llink->rlink = p;
	head->llink = p;
	return head;
}

DListNode* insert(DListNode* head)
{
	DListNode* p = malloc(sizeof(DListNode));
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
	srand(time(NULL));
	p->data.time = rand()%10 + 1;
	DListNode* tmp = head->rlink;
	if (tmp == head)
	{
		p->rlink = head->rlink;
		p->llink = head;
		head->rlink->llink = p;
		head->rlink = p;
		return head;
	}
	
	while (tmp != head && strcmp(tmp->data.music, p->data.music) <= 0)
	{
		tmp = tmp->rlink;
	}
	if (tmp == head)
	{
		head = insert_last(head, p);
		return head;
	}
	else
	{
		p->rlink = tmp;
		p->llink = tmp->llink;
		tmp->llink ->rlink = p;
		tmp->llink = p;
	}
	return head;
}

void print_list(DListNode* head)
{
	DListNode* p = head->rlink;
	if (p == head)
	{
		printf("����ֽ��ϴ�\n");
		return;
	}
	else
	{
		for (; p != head; p = p->rlink)
		{
			printf("�뷡 ����: %s\n", p->data.music);
			printf("���� �̸�: %s\n", p->data.man);
			printf("�뷡 �帣: %c\n", p->data.genre);
			printf("�뷡 ��ǥ �⵵: %d\n", p->data.age);
			printf("===========����============\n\n\n");
		}
	}
}


int list_length(DListNode* head)
{
	DListNode* p = head->rlink;
	int num = 0;
	for (; p != head; p = p->rlink)
		num++;
	return num;
}

DListNode* find_music(DListNode* head)
{
	DListNode* node = head->rlink;
	char find[40];
	printf("ã�� ���� ���Ǹ��� �Է��Ͻÿ�:");
	scanf("%s", find);
	while (node != head)
	{
		if (strcmp(node->data.music, find) == 0)
		{
			printf("ã�ҽ��ϴ�.\n");
			return node;
		}
		node = node->rlink;
	}
	return NULL;
}

DListNode* find_del(DListNode* head)
{
	DListNode* p = head->rlink;
	printf("�����ϰ� ���� ���Ǹ��� �Է��Ͻÿ�:");
	char find[40];
	scanf("%s", find);
	
	while (p != head)
	{
		if (strcmp(p->data.music, find) == 0)
		{
			p->llink->rlink = p->rlink;
			p->rlink->llink = p->llink;
			break;
		}
		p = p->rlink;
	}
	free(p);
	return head;
}

DListNode* all_del(DListNode* head)
{
	DListNode* p = head->rlink;
	if (p == head)
		return head;
	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	free(p);
	all_del(head);
}

DListNode* lately_music(DListNode* head)
{
	DListNode* node = head->rlink;
	if (node == head)
		return NULL;
	DListNode* lately = node;
	for (; node != head; node = node->rlink)
	{
		if (lately->data.age < node->data.age)
			lately = node;
	}
	return lately;
}

void genre_search(DListNode* head)
{
	if (head->rlink == head)
		printf("����Ʈ�� ������ֽ��ϴ�.\n");
	else
	{
		DListNode* node = head->rlink;
		char find;
		while (1)
		{
			getchar();
			printf("�뷡 �帣 �Է�(B,C,H,J,T): ");
			scanf("%c", &find);
			if (find != 'B' && find != 'C' && find != 'H' && find != 'J' && find != 'T')
				printf("'B','C','H','J','T'�߿� �Է��Ͻÿ�\n");
			else
				break;
		}
		for (; node != head; node = node->rlink)
		{
			if (node->data.genre == find)
			{
				printf("�뷡 ����: %s\n", node->data.music);
				printf("���� �̸�: %s\n", node->data.man);
				printf("�뷡 �帣: %c\n", node->data.genre);
				printf("�뷡 ��ǥ �⵵: %d\n", node->data.age);
				printf("===========����============\n\n\n");
			}

		}
	}
	printf("��\n\n");
}

void play_song()
{
	printf("%s ���\n", current->data.music);
	for (int i = 0; i < current->data.time; i++)
	{
		printf("�� ");
		Sleep(300);
	}
	printf("\n%s ��� ����\n", current->data.music);
}

void play(DListNode* head)
{
	if (current == head)
	{
		printf("�����̾����ϴ�.\n");
		exit(1);
	}
	bool b = true;
	char n;
	while (b)
	{
		play_song(current);
		printf(">�Է½� �����뷡\n<�Է½� �����뷡\nF/f�Է½� �� �� �뷡\nL/l�Է½� �� �� �뷡\n�׿ܿ� �÷��� ����\n�Է�:");
		getchar();
		scanf("%c", &n);
		switch (n)
		{
		case '>':
			current = current ->rlink;
			if(current == head)
				current = current->rlink;
			break;
		case '<':
			current = current->llink;
			if (current == head)
				current = current->llink;
			break;
		case 'f':
		case 'F':
			current = head->rlink;
			break;
		case 'l':
		case 'L':
			current = head->llink;
			break;
		default:
			b = false;
			break;
		}
	}
}

int main(void)
{
	DListNode* head = malloc(sizeof(DListNode));
	init(head);
	int num;
	bool b = true;
	DListNode* data;
	while (b)
	{
		printf("1.��� ����\n2.���\n3.���� ���ϱ�\n4.�뷡 �˻�\n5.����\n6.���� �ֱ� �뷡\n7.�帣 �˻�\n8.���(������� 9.�뷡 ó�� ��ġ ���� ��Ź�帳�ϴ�.)\n9.�뷡 ó�� ��ġ��\n�� ��.����\n�Է�:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			head = insert(head);
			break;
		case 2:
			print_list(head);
			break;
		case 3:
			printf("���̴� %d\n", list_length(head));
			break;
		case 4:
			data = find_music(head);
			if (data == NULL)
				printf("��ã�ҽ��ϴ�.\n");
			else
			{
				printf("�뷡 ����: %s\n", data->data.music);
				printf("���� �̸�: %s\n", data->data.man);
				printf("�뷡 �帣: %c\n", data->data.genre);
				printf("�뷡 ��ǥ �⵵: %d\n\n", data->data.age);
			}
			break;
		case 5:
			head = find_del(head);
			break;
		case 6:
			data = lately_music(head);
			if (data == NULL)
				printf("����Ʈ�� ����ֽ��ϴ�.\n");
			else
			{
				printf("�뷡 ����: %s\n", data->data.music);
				printf("���� �̸�: %s\n", data->data.man);
				printf("�뷡 �帣: %c\n", data->data.genre);
				printf("�뷡 ��ǥ �⵵: %d\n\n", data->data.age);
			}   
			break;
		case 7:
			genre_search(head);
			break;
		case 8:
			play(head);
			break;
		case 9:
			current = head->rlink;
			if (current == head)
			{
				printf("�����̾����ϴ�.\n");
				exit(1);
			}
			break;
		default:
			head = all_del(head);
			printf("����\n");
			b = false;
			break;
		}
	}

	free(head);
	return 0;
}

// SONG5 MAN5 J 7245 
// SONG3 MAN3 C 5314 
// SONG7 MAN7 J 5311 
// SONG4 MAN4 J 5314