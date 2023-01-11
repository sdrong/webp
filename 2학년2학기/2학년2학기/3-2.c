#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print(int arr[])
{
	for (int i = 0; i < 10; i++)
		printf("%d->", arr[i]);
	printf("\n");
}

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}

void search(int arr[], int key, int head, int tail, int try)
{
	while (head < tail)
	{
		int mid = (head + tail) / 2;
		try++;
		printf("%d��° �õ�. arr[%d]Ž��\n", try, mid);
		if (arr[mid] == key)
		{
			printf("ã�ҽ��ϴ�. arr[%d]�� �־����ϴ�.\n", mid);
			return;
		}
		else if (arr[mid] > key)
		{
			tail = mid - 1;
		}
		else
		{
			head = mid + 1;
		}
	}
	printf("ã�� ���Ͽ����ϴ�.\n");
}

int main(viod)
{
	int arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 50;
	}
	print(arr);
	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);
	print(arr);
	int key;
	printf("ã����� ���ڸ� �Է��Ͻÿ�:");
	scanf("%d", &key);
	search(arr, key, 0, 9, 0);
	return 0;
}