#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define KEY_SIZE 10
#define TABLE_SIZE 5

typedef struct element
{
	char name[KEY_SIZE];
}element;

typedef struct list
{
	element data;
	struct list* link;
}list;


int transform(char* key)
{
	int sum = 0;
	for (int i = 0; key[i] != NULL; i++)
	{
		sum += key[i];
	}
	return sum;
}

int hash_function(char key[])
{
	return transform(key) % TABLE_SIZE;
}

list* hash_table[TABLE_SIZE];

#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key,item2.key))

void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.name);
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {
		if (strcmp(node->data.name, item.name)==0)
		{
			fprintf(stderr, "�̹� Ž��Ű�� ����Ǿ� ����\n");
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->data = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[hash_value] = ptr;
	printf("%d�� ����Ǿ���\n", hash_value);
}

void hash_chain_search(element item, struct list* ht[])
{
	struct list* node;

	int hash_value = hash_function(item.name);
	for (node = ht[hash_value]; node; node = node->link)
	{
		if (strcmp(node->data.name, item.name) == 0)
		{
			fprintf(stderr, "Ž�� %s ���� %d�� ����Ǿ����� \n", item.name, hash_value);
			return;
		}
	}
	printf("Ű�� ã������");
}

void hash_chain_print(struct list* ht[])
{
	struct list* node;
	int i;
	printf("\n======================================\n");
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("%d->", i);
		for (node = ht[i]; node; node = node->link) {
			printf("%s->", node->data.name);
		}
		printf("\n");
	}
	printf("\n======================================\n");
}

void hash_chain_delete(element item, list* ht[])
{
	list* node;

	int hash_value = hash_function(item.name);
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (ht[i] == NULL)
			continue;
		node = ht[i];
		if (strcmp(item.name, node->data.name) == 0)
		{
			ht[i] = node->link;
			free(node);
			return;
		}
		list* temp = node;

		for (; node; node = node->link)
		{
			if (strcmp(item.name, node->data.name) == 0)
			{
				temp->link = node->link;
				free(node);
				return;
			}
			temp = node;
		}
	}
}

#define SIZE 5

int main(void)
{
	char user[10];
	bool b = true;
	element e;
	while (b)
	{
		printf("����(i), Ž��(s), ����(d), ����(e) :");
		char u;
		scanf("%c", &u);
		
		switch (u)
		{
		case 'i':
			printf("������ �ܾ� �Է�:");
			scanf("%s", e.name);
			getchar();
			hash_chain_add(e, hash_table);
			hash_chain_print(hash_table);
			break;
		case 's':
			printf("Ž���� �ܾ� �Է�:");
			scanf("%s", e.name);
			getchar();
			hash_chain_search(e, hash_table);
			break;
		case 'd':
			printf("������ �ܾ� �Է�:");
			scanf("%s", e.name);
			getchar();
			hash_chain_delete(e, hash_table);
			hash_chain_print(hash_table);
			break;
		case 'e':
			b = false;
			break;
		}
	}
	return 0;
}