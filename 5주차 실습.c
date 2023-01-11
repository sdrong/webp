#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define MAX_SIZE 100

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

void print2(int arr[], int n, int left, int right)
{
	for (int i = 0; i < n; i++)
	{
		if (left == i)
			printf("[");
		printf("%2d ", arr[i]);
		if (right == i)
			printf("]");
	}
	printf("\n");
}


int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
	{
		for (j; j <= right; j++)
			sorted[k++] = list[j];
	}
	else
	{
		for (i; i <= mid; i++)
			sorted[k++] = list[i];
	}
	for (int l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right, int n)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid, n);
		merge_sort(list, mid + 1, right, n);
		merge(list, left, mid, right);
		printf("병합된 범위[%d, %d] \n", left, right);
		print2(list, n, left, right);
	}
}

void S1(int n)
{
	int* arr = malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("정렬할 원소:");
	print(arr, n);
	printf("\n<<병합정렬>>\n");
	merge_sort(arr, 0, n-1, n);
	free(arr);
}

int sorted2[MAX_SIZE];

void merge2(int arr[], int left, int mid, int right, int n)
{
	int k = left, i = left, j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j]) {
			sorted2[k++] = arr[i++];
		}
		else {
			sorted2[k++] = arr[j++];
		}
	}

	while (i < n && i <= mid) {
		sorted2[k++] = arr[i++];
	}

	for (int i = left; i <= right; i++) {
		arr[i] = sorted2[i];
	}
}

void merge_sort2(int arr[], int left, int right, int n)
{
	int cnt = 0;
	for (int m = 1; m <= right - left; m = 2 * m)
	{
		cnt++;
		printf("\n<<%d단계>>\n", cnt);
		for (int i = left; i < right; i += 2 * m)
		{
			int mid = i + m - 1;
			int high = i + 2 * m - 1;
			if (high > right)
				high = right;
			merge2(arr, i, mid, high, n);
			printf("병합된 범위[%d, %d] \n", i, high);
			print2(arr, n, i, high);
		}
	}
}

void S2(int n)
{
	int *arr = malloc(sizeof(int) * n);
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		sorted2[i] = arr[i] = (rand() % 50);
	}
	printf("정렬할 배열\n");
	print(arr, n);
	merge_sort2(arr, 0, n - 1, n);
}

int main(void)
{
	bool b = true;
	while (b) {
		int use;
		printf("1.병합정렬 순환\n");
		printf("2.병합정렬 반복\n");
		printf("그외. 종료");
		printf("선택:");
		scanf("%d", &use);
		int n;
		switch (use)
		{
		case 1:
			printf("n의 값 입력:");
			scanf("%d", &n);
			S1(n);
			break;
		case 2:
			printf("n의 값 입력:");
			scanf("%d", &n);
			S2(n);
			break;
		default:
			b = false;
			break;
		}
	}
	return 0;
}