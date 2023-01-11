#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void add( int result[],int arr1[], int arr2[])
{
	int i1 = 0, i2 = 0;
	int i = 0;
	while (i < 10 && i1<5 && i2<5)
	{
		if (arr1[i1] < arr2[i2])
			result[i++] = arr1[i1++];
		else
			result[i++] = arr2[i2++];
	}
	if (i1 >= 5)
	{
		while (i2 < 5)
		{
			result[i++] = arr2[i2++];
		}
	}
	else
		while (i1 < 5)
		{
			result[i++] = arr1[i1++];
		}
}

typedef struct list {
	int key;
	struct list* link;
}list;

list* new_node(list* arr, int n)
{
	list* new = malloc(sizeof(list));
	new->key = n;

	if (arr == NULL)
	{
		new->link = arr;
		arr = new;
	}
	else {
		new->link = arr->link;
		arr->link = new;
		arr = new;
	}
	return arr;
}

void print2(list* arr)
{
	list* tmp = arr->link;
	while (tmp != NULL)
	{
		printf("%d ", tmp->key);
		tmp = tmp->link;
	}
}

list* add2(list* arr, list* arr2, list* arr3)
{
	list* tmp2 = arr2->link;
	list* tmp3 = arr3->link;
	do {
		if (tmp2->key < tmp3->key)
		{
			arr = new_node(arr, tmp2->key);
			tmp2 = tmp2->link;
		}
		else
		{
			arr = new_node(arr, tmp3->key);
			tmp3 = tmp3->link;
		}
	} while (tmp2 != NULL && tmp3 != NULL);

	if (tmp2 == NULL)
	{
		do {
			arr = new_node(arr, tmp3->key);
			tmp3 = tmp3->link;
		} while (tmp3 != NULL);
		tmp3 = tmp3->link;
	}
	else
	{
		arr = new_node(arr, tmp3->key);
		tmp3 = tmp3->link;
		do {
			arr = new_node(arr, tmp2->key);
			tmp2 = tmp2->link;
		} while (tmp2 != NULL);
		arr = new_node(arr, tmp2->key);
		tmp2 = tmp2->link;
	}

	return arr;
}

int main(void)
{
	int arr1[5]= { 5, 7, 24, 56, 62 };
	int arr2[5] = { 19, 45, 61, 79, 92 };
	list* arrr1 = NULL;
	list* arrr2 = NULL;
	list* arrr = NULL;
	for (int i = 0; i < 5; i++)
	{
		arrr1 = new_node(arrr1, arr1[i]);
		arrr2 = new_node(arrr2, arr2[i]);
	}
	
	print2(arrr1);
	print2(arrr2);

	arrr = add2(arrr, arrr1, arrr2);
	print2(arrr);
	
	return 0;
}