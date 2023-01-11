#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct ListNode {
	int key;
	struct ListNode* link;
}ListNode;

typedef struct ListType{
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

ListType* create()
{
	ListType* list = malloc(sizeof(ListType));
	list->head = list->tail = NULL;
	list->size = 0;
}

void print(ListNode* arr)
{
	while (arr)
	{
		printf("%d ", arr->key);
		arr = arr->link;
	}
	printf("\n");
}

ListNode* new_node(int n)
{
	ListNode* tmp = malloc(sizeof(ListNode));
	tmp->key = n;
	tmp->link = NULL;
	return tmp;
}

void insert_node(ListType* list, int num)
{
	ListNode* tail = list->tail;
	ListNode* tmp = new_node(num);
	list->size++;
	if (list->tail == NULL)
	{
		list->head = list->tail = tmp;
		return;
	}
	tail->link = tmp;
	list->tail = tmp;
}

void sort(ListType* list)
{
	ListNode* base = list->head;
	ListNode* tmp;
	for (int i = 0; i<list->size-1 ; i++, base = base->link)
	{
		for (tmp = base->link; tmp != NULL; tmp = tmp->link)
		{
			if (base->key > tmp->key)
			{
				int temp = base->key;
				base->key = tmp->key;
				tmp->key = temp;
			}
		}
	}
}

int main(viod)
{
	ListType* list;
	list = create();
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		insert_node(list, rand()%100);

	}
	print(list->head);
	sort(list);
	print(list->head);
	return 0;
}