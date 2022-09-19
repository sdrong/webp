#include<stdio.h>
#include<stdlib.h>

typedef struct element {
	char name[50];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* Add_First(ListNode* head)
{
	element put;
	printf("���� �ܾ� �Է�:");
	scanf("%s", put.name);
	ListNode* p = malloc(sizeof(ListNode));
	p->data = put;
	p->link = head;
	head = p;
	return head;
}
ListNode* Add(ListNode* head, int n)
{
	element put;
	printf("���� �ܾ� �Է�:");
	scanf("%s", put.name);
	ListNode* temp = head;
	ListNode* p = malloc(sizeof(ListNode));
	for (int i = 0; i < n - 1; i++)
	{
		temp = temp->link;
	}
	if (temp->link == NULL)
	{
		p->data = put;
		temp->link = p;
		p->link = NULL;
	}
	else
	{
		p->data = put;
		p->link = temp->link;
		temp->link = p;
	}
	return head;
}

void Print(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
	{
		printf("%s -> ", p->data.name);
	}
	printf("NULL\n");
}

ListNode* Delete_First(ListNode* head)
{
	if (head == NULL)
	{
		printf("�̹� ����ֽ��ϴ�.\n");
	}
	else
	{
		ListNode* p = head;
		head = p->link;
		free(p);
		return head;
	}
}

ListNode* Delete(ListNode* head, int n)
{
	ListNode* temp = head;
	for (int i = 0; i < n - 1; i++)
	{
		temp = temp->link;
	}
	ListNode* p = malloc(sizeof(ListNode));
	p = temp->link;
	temp->link = p->link;
	free(p);
	return head;
}


int main(void)
{
	ListNode* head = NULL;
	int n;
	while (1)
	{
		printf("1.��忡 �߰�\n");
		printf("2.���ϴ� ��ġ�� �߰�\n");
		printf("3.��� ����\n");
		printf("4.���ϴ� ��ġ ����\n");
		printf("5.���\n");
		printf("6.��� ���� ���\n");
		printf("7.����\n");
		printf("�Է�:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			head = Add_First(head);
			break;
		case 2:
			printf("���°�� �߰� �Ͻǰǰ���?");
			scanf("%d", &n);
			head = Add(head, n);
			break;
		case 3:
			head = Delete_First(head);
			break;
		case 4:
			printf("���°�� ���� �Ͻǰǰ���?");
			scanf("%d", &n);
			head = Delete(head, n);
			break;
		case 5:
			Print(head);
			break;
		case 6:

		case 0:
			break;
		default:
			break;
		}
	}
	free(head);
	return 0;
}