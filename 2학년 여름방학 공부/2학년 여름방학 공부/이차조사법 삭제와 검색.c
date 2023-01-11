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
			fprintf(stderr, "중복됩니다.");
			return;
		}
		inc = inc + 1;
		i = (value + inc * inc) % TABLE_SIZE;
		if (i == value) {
			fprintf(stderr, "테이블이 가득 찼습니다.\n");
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
			fprintf(stderr, "찾음 %d에 위치\n",i);
			return;
		}
		i = (i + inc) % TABLE_SIZE;
		if (i == value)
		{
			fprintf(stderr, "테이블이 다 찼습니ㅏㄷ.");
			exit(1);
		}
	}
	printf("첮자못험\n");
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
