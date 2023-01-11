#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

void print(int list[])
{
	for (int i = 0; i < 10; i++)
		printf("%d ", list[i]);
	printf("\n");
}

int partition1(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;
	low = left-1;
	high = right;
	pivot = list[right];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		if (low < high)
			SWAP(list[low], list[high], temp);

	} while (low < high);
	SWAP(list[right], list[low], temp);
	return low;
}

int partition2(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		if (low < high)
			SWAP(list[low], list[high], temp);

	} while (low < high);
	SWAP(list[left], list[high], temp);
	return high;
}

int partition3(int list[], int left, int right)
{
	int pivot, temp;
	int low, high, mid;
	low = left -1;
	high = right + 1;
	mid = (low + high) / 2;
	pivot = list[mid];
	do{
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		if (low < high)
			SWAP(list[low], list[high], temp);
	} while (low < high);
	if (low == mid)
		SWAP(list[mid], list[high], temp);
	else
		SWAP(list[mid], list[low], temp);
	
	print(list);
	return mid;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right)
	{
		int q = partition3(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q +1 , right);
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		list[i] = rand() % 100;
	quick_sort(list, 0, n - 1);
	print(list);
	return 0;
}