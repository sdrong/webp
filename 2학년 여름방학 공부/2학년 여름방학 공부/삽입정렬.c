#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int arr[])
{
	for (int i = 1; i < 10; i++)
	{
		int loc = i - 1;
		int base = arr[i];
		while (loc >= 0 && base < arr[loc])
		{
			arr[loc + 1] = arr[loc];
			loc--;
		}
		arr[loc + 1] = base;
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
	selectionSort(arr);
	print(arr);
	return 0;
}