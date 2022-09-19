#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 7

typedef struct list
{
	int data;
	int use;
}list;

list table_list[TABLE_SIZE];

int ch(int item)
{
	return item % TABLE_SIZE;
}

void init(list tb[])
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		tb[i].use = 0;
	}
}

void add(list tb[], int item)
{
	int value = ch(item);
	while (tb[value].data)
	{
		value = (value + 1) % TABLE_SIZE;
		if (value == ch(item))
		{
			fprintf(stderr,"리스트가 꽉 찼습니다.\n");
			return;
		}
	}
	tb[value].data = item;
	tb[value].use = 1;
}

void print(list tb[])
{
	printf("\n======================================\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("tb[%d]: %d", i, tb[i].data);
		printf("\n");
	}
	printf("\n======================================\n");
}

void search(list tb[], int item)
{
	int value = ch(item);
	int i = value;
	while(tb[i].use != 0)
	{
		if (tb[i].data == item)
		{
			printf("찾았습니다. tb[%d]에 있습니다.\n", i);
			return;
		}
		i++;
		if (value == i)
		{
			break;
		}
	}
	printf("없습니다\n");
}

void delete(list tb[], int item)
{
	int value = ch(item);
	int i = value;
	while (tb[i].use == 1)
	{
		if (tb[i].data == item)
		{
			printf("찾았습니다 삭제합니다. \n");
			tb[i].data = 0;
			return;
		}
		i++;
		if (value == i)
		{
			break;
		}
	}
	printf("없습니다.\n");
}

int main(void)
{
	int arr[6] = { 24,21, 19,14, 55, 7 }; 
	init(table_list);
	for (int i = 0; i < 6; i++)
	{
		add(table_list, arr[i]);
		print(table_list);
	}
	delete(table_list, 14);
	print(table_list);
	search(table_list, 7);
	return 0;
}