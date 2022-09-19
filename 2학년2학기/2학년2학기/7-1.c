#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int sorted[MAX_SIZE];

void print(int list[])
{
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
}

void marge(int list[], int left, int right, int mid)
{
	int i, j, k, l;
	i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (list[i] < list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
	{
		for (l = j; l <= right; l++)
		{
			sorted[k++] = list[l];
		}
	}
	else
	{
		for (l = i; l <= mid; l++)
		{
			sorted[k++] = list[l];
		}
	}
	for (i = left; i <= right; i++)
	{
		list[i] = sorted[i];
	}
}

void marge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		marge_sort(list, left, mid);
		marge_sort(list, mid + 1, right);
		marge(list, left, right, mid);
	}
}

int main(void)
{
	int list[MAX_SIZE];
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
		list[i] = rand() % 100;
	print(list);
	marge_sort(list, 0 ,9);
	print(list);
	return 0;
}