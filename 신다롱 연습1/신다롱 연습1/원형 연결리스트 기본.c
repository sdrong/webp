#include<stdio.h>
#include<stdlib.h>

typedef char element[100];

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = malloc(sizeof(ListNode));
	strcpy(node->data,data);
	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = malloc(sizeof(ListNode));
	strcpy(node->data, data);
	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

void print_list(ListNode* head)
{
	ListNode* node;
	if (head == NULL)
	{
		printf("비어있습니다.\n");
	}
	else
	{
		node = head->link;
		while (node != head)
		{
			printf("%d -> ", node->data);
			node = node->link;
		}
		printf("%d \n",node->data);
	}
}

int get_lench(ListNode* head)
{
	if (head == NULL)
		return 0;
	ListNode* p = head->link;
	int count = 1;
	while(p!= head)	{
		count++;
		p = p->link;
	}
	return count;
}

int main(void)
{
	ListNode* head = NULL;
	head = insert_first(head, "Kim");
	head = insert_first(head, "Sin");
	head = insert_first(head, "Um");
	printf("%d\n",get_lench(head));
	ListNode* p = head;
	for (int i = 0; i < 10; i++)
	{
		printf("%d번째 차례는 : %s\n", i+1, p->data);
		p = p->link;
	}
	return 0;
}