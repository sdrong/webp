#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 7

typedef struct list
{
	int data;
}list;

list table_list[TABLE_SIZE];

int function(int item)
{
	return item % TABLE_SIZE;
}

void add(list ht[], int item)
{
	int i;
	int inc = 0;
	int value = i = function(item);
	while (ht[i].data)
	{
		if (ht[i].data == item)
		{
			fprintf(stderr, "�ߺ��˴ϴ�.");
			return;
		}
		inc = inc + 1;
		i = (value + inc * inc) % TABLE_SIZE;
		if (i == value) {
			fprintf(stderr, "���̺��� ���� á���ϴ�.\n");
			exit(1);
		}
	}
	ht[i].data = item;

}

void search(list ht[], int item)
{
	int value, i, inc = 0;
	value = i = inc = function(item);
	while (ht[i].data)
	{
		if (ht[i].data == item)
		{
			fprintf(stderr, "ã�� %d�� ��ġ\n",i);
			return;
		}
		i = (i + inc) % TABLE_SIZE;
		if (i == value)
		{
			fprintf(stderr, "���̺��� �� á���Ϥ���.");
			exit(1);
		}
	}
	printf("�R�ڸ���\n");
}

void print(list ht[])
{
	printf("\n=========================================\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("ht[%d] : ", i);
		printf("%d \n", ht[i].data);
	}
	printf("\n=========================================\n");
}

int main(void)
{
	int arr[6] = { 24,21, 19,14, 55, 7 };
	for (int i = 0; i < 6; i++)
	{
		add(table_list, arr[i]);
		print(table_list);
	}
	print(table_list);
	search(table_list, 7);
	return 0;
}
