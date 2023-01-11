#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define SWAP(a,b,t) ((t)=(a), (a)=(b), (b)=(t))

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

void print2(int arr[], int n, int finish)
{
	printf("[");
	for (int i = 0; i < n; i++)
	{
		printf("%2d ", arr[i]);
		if (i == finish)
			printf("]");
	}
	printf("\n");
}

void print3(int arr[], int n, int finish)
{
	for (int i = 0; i < n; i++)
	{
		if (i == finish)
			printf("[");
		printf("%2d ", arr[i]);
		
	}
	printf("]\n");
}

void selectionSort(int arr[], int n)
{
	int total = 0;
	int i;
	for (i = 0; i < n-1; i++)
	{
		int cnt = 0;
		int value = arr[i];
		int index = i;
		int j;
		for (j = i+1; j<n; j++)
		{
			if (value > arr[j])
			{
				value = arr[j];
				index = j;
			}
			total++;
			cnt++;
		}
		int temp;
		SWAP(arr[index], arr[i], temp);
		printf("%d번째 교환 최소값 %d, 비교회수%d \n", i + 1, arr[i], cnt);
		printf("%d단계:", i+1);
		print2(arr, n, i);
	}
	printf("결과\n%d단계:", i + 1);
	print2(arr, n, i);
	printf("전체 비교 회수%d\n", total);
}

void S1(int n)
{
	int* arr = malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("정렬할 원소:");
	print(arr, n);
	printf("\n<<선택정렬>>\n");
	selectionSort(arr, n);
	free(arr);
}

void insertion_sort(int arr[], int n)
{
	int cnt;
	int total = 0;
	for (int i = 1; i < n; i++)
	{
		cnt = 1;
		int loc = i - 1;
		int base = arr[i];
		if (arr[i] < arr[0])
			cnt--;
		while (loc >= 0 && base < arr[loc])
		{
			cnt++;
			arr[loc + 1] = arr[loc];
			loc--;
		}
		if (i == 1)
			cnt = 1;
		arr[loc + 1] = base;
		printf("%d단계 비교횟수 %d\n", i, cnt);
		printf("%d단계:", i);
		print2(arr, n, i);
		total += cnt;
	}
	printf("총 비교 횟수 %d\n", total);
}

void S2(int n)
{
	int* arr = malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("정렬할 원소: ");
	print(arr, n);
	printf("\n<<삽입 정렬>>\n");
	insertion_sort(arr, n);
	free(arr);
}

void bubble_sort(int arr[], int n)
{
	int use;
	printf("1 입력시 교환 횟수가 0일 시 종료\n");
	printf("그외.종료하지 않음");
	printf("입력:");
	scanf("%d", &use);
	int temp;
	int total = 0;
	int cnt;
	int j;
	for (int i = n - 1; i > 0; i--)
	{
		cnt = 0;
		printf("<<%d단계>>\n", n-i);
		for (j = 0; j <i; j++)
		{
			print(arr, n);
			if (arr[j] > arr[j + 1])
			{
				SWAP(arr[j], arr[j + 1], temp);
				total++;
				cnt++;
			}
		}
		if (cnt == 0 && use == 1)
		{
			print3(arr,n, 0);
			printf("비교횟수 %d 교환 횟수 %d\n", i, cnt);
			return;
		}
		print3(arr, n, i);
		printf("비교횟수 %d 교환 횟수 %d\n", i, cnt);
	}
	printf("결과\n");
	print3(arr, n, 0);
}

void S3(int n)
{
	int *arr = malloc(sizeof(int)*n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("정렬할 원소:");
	print(arr, n);
	printf("\n<<버블 정렬>>\n");
	bubble_sort(arr, n);
	free(arr);
}

int main(void)
{
	bool b = true;
	while (b) {
		int use;
		printf("1.선택정렬\n");
		printf("2.삽입정렬\n");
		printf("3.버블정렬\n");
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
		case 3:
			printf("n의 값 입력:");
			scanf("%d", &n);
			S3(n);
			break;
		default:
			b = false;
			break;
		}
	}
	return 0;
}Y