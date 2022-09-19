#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SWAP(a,b,t) ((t)=(a), (a)=(b), (b)=(t))

void heapify(int arr[], int k, int n)
{
	int left = 2 * k;
	int right = 2 * k + 1;
	int smaller;
	int temp;
	if (right <= n)
	{
		if (arr[left] < arr[right])
			smaller = left;
		else
			smaller = right;
	}
	else if (left <= n)
		smaller = left;
	else
		return;
	if (arr[smaller] < arr[k])
	{
		SWAP(arr[k], arr[smaller], temp);
		heapify(arr, smaller, n);
	}
}

void print(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void build(int arr[], int n)
{
	for (int i = n / 2; i >= 0; i--)
	{
		heapify(arr, i, n);
		print(arr);
	}
}

int main(void)
{
	int arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int key = rand() % 100;
		printf("%d »ðÀÔ\n", key);
		arr[i] = key;
	}
	print(arr);
	build(arr, 9);
	print(arr);
	return 0;
}