#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element[100];
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

DListNode* current;

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
		if (p == current)
			printf("<-| #%s# |->", p->data);
		else
			printf("<-| %s |->", p->data);
	}
	printf("\n");
}

void dinsert(DListNode* head, element data)
{
	DListNode* newnode = malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = head;
	newnode->rlink = head->rlink;
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
	char ch;
	DListNode* head = malloc(sizeof(DListNode));
	init(head);
	dinsert(head, "Mamamia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");

	current = head->rlink;
	print_dlist(head);

	do {
		printf("명령어를 입력하시오(<, >, q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->llink;
			if (current == head)
				current = current->llink;
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head)
				current = current->rlink;
		}
		print_dlist(head);
		getchar();
	} while (ch != 'q');
	free(head);
	return 0;
}