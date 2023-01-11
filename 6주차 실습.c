#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define MAX_SIZE 100
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

void print2(int arr[], int left,int low, int right, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == left)
		{
			printf("[");
		}
		if (low == i)
		{
			printf("]");
		}
		printf("%2d ", arr[i]);
		if (i == low)
		{
			printf("[");
		}
		if (i == right)
		{
			printf("]");
		}
	}
	printf("\n");
}

void print3(int arr[], int left, int high, int right, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == left)
		{
			printf("[");
		}
		if (high == i)
		{
			printf("]");
		}
		printf("%2d ", arr[i]);
		if (i == high)
		{
			printf("[");
		}
		if (i == right)
		{
			printf("]");
		}
	}
	printf("\n");
}

int partition1(int arr[], int left, int right, int n)
{
	int pivot = arr[right];                                                                                                                                 
	int temp;
	int low = left;
	int high = left;
	printf("\n범위 %d ~ %d \n", left, right);
	printf("<<pivot:%d>>\n", pivot);
	while (high < right)
	{
		while (arr[high] > pivot&&high < right)
		{
			high++;
		}
		if (high < right)
		{
		
			SWAP(arr[high], arr[low], temp);
			low++;
			high++;
		}
	}
	SWAP(arr[low], arr[right], temp);
	print2(arr, left,low, right, n);
	return low;
}

void quick_sort1(int arr[], int left, int right, int n)
{
	if (left < right)
	{
		int q = partition1(arr, left, right, n);
		quick_sort1(arr, left, q - 1, n);
		quick_sort1(arr, q+1, right, n);
	}
}


int partition2(int arr[], int left, int right, int n)
{
	int pivot = arr[left];
	int temp;
	int low = right;
	int high = right;
	printf("\n범위 %d ~ %d \n", left, right);
	printf("<<pivot:%d>>\n", pivot);
	while (low > left)
	{
		while (arr[low] < pivot && left < low)
		{
			low--;
		}
		if (low > left)
		{
			SWAP(arr[low], arr[high], temp);
			low--;
			high--;
		}
	}
	SWAP(arr[high], arr[left], temp);
	print3(arr, left, high, right, n);
	return high;
}
void quick_sort2(int arr[], int left, int right, int n)
{
	if (left < right)
	{
		int q = partition2(arr, left, right, n);
		quick_sort2(arr, left, q-1, n);
		quick_sort2(arr, q+1, right, n);
	}
}

int partition3(int arr[], int left, int right, int n)
{
	int pivot = arr[left];
	printf("pivot:%d\n", pivot);
	int temp;
	int low = left;
	int high = right + 1;
	printf("\n범위 %d ~ %d \n", left, right);
	printf("<<pivot:%d>>\n", pivot);
	do {
		do {
			low++;
		} while (pivot > arr[low]);
		do {
			high--;
		} while (pivot < arr[high]);
		if (low < high)
		{
			SWAP(arr[low], arr[high], temp);
		}
	} while (low < high);
	SWAP(arr[left], arr[high], temp);
	print3(arr, left, high, right, n);
	return high;
}

void quick_sort3(int arr[], int left, int right, int n)
{
	if (left < right)
	{
		int q = partition3(arr, left, right, n);
		quick_sort3(arr, left, q - 1, n);
		quick_sort3(arr, q + 1, right, n);
	}
}

void S1(void)
{
	int n;
	printf("몇개의 배열로 만들 것인가요:");
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("정렬할 원소:");
	print(arr, n);
	quick_sort1(arr, 0, n - 1, n);
	print(arr, n);
}

void S2(void)
{
	int n;
	printf("몇개의 배열로 만들 것인가요:");
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("정렬할 원소:");
	print(arr, n);
	quick_sort2(arr, 0, n - 1, n);
	print(arr, n);
}

void S3(void)
{
	int n;
	printf("몇개의 배열로 만들 것인가요:");
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("정렬할 원소:");
	print(arr, n);
	quick_sort3(arr, 0, n - 1, n);
	print(arr, n);
}

int main(void)
{
	bool b = true;
	while (b) {
		int use;
		printf("1.퀵정렬 꼬리 피봇\n");
		printf("2.퀵정렬 헤드 피봇\n");
		printf("3.퀵정렬 헤드 피봇2\n");
		printf("그외. 종료");
		printf("선택:");
		scanf("%d", &use);
		int n;
		switch (use)
		{
		case 1:
			S1();
			break;
		case 2:
			S2();
			break;
		case 3:
			S3();
			break;
		default:
			b = false;
			break;
		}
	}
	return 0;
}