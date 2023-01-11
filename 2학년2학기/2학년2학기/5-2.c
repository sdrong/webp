#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print(int arr[])
{
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void sort(int arr[])
{
	for (int i = 9; i >= 0; i--)
	{
		printf("%d´Ü°è\n", 10 - i);
		for (int j = 0; j < i; j++)
		{
			print(arr);
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				print(arr);
			}
		}
	}
	printf("result\n");
	print(arr);
}

int main(void)
{
	int arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100;
	}
	sort(arr);
	return 0;
}