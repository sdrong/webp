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
	int cnt[11];
	for (int i = 0; i < 11; i++)
		cnt[i] = 0;
	for (int i = 1; i < 10; i++)
	{
		printf("%d´Ü°è: ", i);
		print(arr);
		for (int j = i; j >= 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				cnt[i]++;
				cnt[10]++;
			}
			else
				break;
		}
	}
	printf("10´Ü°è: ");
	print(arr);
	for (int i = 1; i < 10; i++)
	{
		printf("%d¹ø¤Š ºñ±³È½¼ö: %d\n", i, cnt[i]);
	}
	printf("ÃÑ ºñ±³È½¼ö: %d\n", cnt[10]);
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