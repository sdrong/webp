#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void init(DListNode* head)
{
	head->llink = head;
	head->rlink = head;
}

void print_dlist(DListNode* head)  
{
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink)
	{
		printf("<-| |%d| |->",p->data);
	}
	printf("\n");
}

void dinsert(DListNode* head, element data)
{
	DListNode* newnode = malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = head->rlink;
	newnode->llink = head;
	head->rlink->llink = newnode;
	head->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

int main(void)
{
	DListNode* head = malloc(sizeof(DListNode));
	init(head);
	printf("�߰��ܰ�\n");
	for (int i = 0; i < 5; i++)
	{
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n�����ܰ�\n");
	for (int i = 0; i < 5; i++)
	{
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}