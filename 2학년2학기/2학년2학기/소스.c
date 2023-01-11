#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionSort(int arr[])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = arr[i];
			}
		}
	}
}

void print()

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
	selectionSort(arr);
	return 0;
}