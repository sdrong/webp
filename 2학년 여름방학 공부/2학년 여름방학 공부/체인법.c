#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define KEY_SIZE 10
#define TABLE_SIZE 7

typedef struct
{
	int key;
}element;

struct list
{
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE];

int hash_function(int key)
{
	return key % TABLE_SIZE;
}

#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key,item2.key))

void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {
		if (node->item.key == item.key)
		{
			fprintf(stderr, "�̹� Ž��Ű�� ����Ǿ� ����\n");
			return;
		}
	}
	ptr = (struct list *)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[hash_value] = ptr;
}

void hash_chain_search(element item, struct list* ht[])
{
	struct list* node;

	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link)
	{
		if (node->item.key == item.key)
		{
			fprintf(stderr, "Ž�� %d ���� \n", item.key);
			return;
		}
	}
	printf("Ű�� ã������");
}

void hash_chain_print(struct list * ht[])
{
	struct list* node;
	int i;
	printf("\n======================================\n");
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("%d->", i);
		for (node = ht[i]; node; node = node->link) {
			printf("%d->", node->item.key);
		}
		printf("\n");
	}
	printf("\n======================================\n");
}

#define SIZE 5

int main(void)
{
	int num[SIZE] = { 8,1,9,6,13 };
	element e;
	for (int i = 0; i < SIZE; i++)
	{
		e.key = num[i];
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}
	for (int i = 0; i < SIZE; i++)
	{
		e.key = num[i];
		hash_chain_search(e, hash_table);
	}
	return 0;
}