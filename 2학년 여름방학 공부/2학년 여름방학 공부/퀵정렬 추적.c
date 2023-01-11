#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;
	pivot = list[left];
	low = left;
	high = right+1;
	do {
		do {
			low++;
		} while (pivot > list[low]);
		do {
			high--;
		} while (pivot < list[high]);
		if(low<high)
			SWAP(list[low], list[high], temp);
	} while (low < high);
	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) 
	{
		printf("quick_sort(%d, %d)\n", list[left], list[right]);
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main(void)
{
	n = MAX_SIZE;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		list[i] = rand() % 100;
	for (int i = 0; i < n; i++)
	{
		printf("%3d", list[i]);
	}
	printf("\n");
	quick_sort(list, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%3d", list[i]);
	}
	return 0;
}