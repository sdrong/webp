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
		printf("%d��° ��ȯ �ּҰ� %d, ��ȸ��%d \n", i + 1, arr[i], cnt);
		printf("%d�ܰ�:", i+1);
		print2(arr, n, i);
	}
	printf("���\n%d�ܰ�:", i + 1);
	print2(arr, n, i);
	printf("��ü �� ȸ��%d\n", total);
}

void S1(int n)
{
	int* arr = malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("������ ����:");
	print(arr, n);
	printf("\n<<��������>>\n");
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
		printf("%d�ܰ� ��Ƚ�� %d\n", i, cnt);
		printf("%d�ܰ�:", i);
		print2(arr, n, i);
		total += cnt;
	}
	printf("�� �� Ƚ�� %d\n", total);
}

void S2(int n)
{
	int* arr = malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("������ ����: ");
	print(arr, n);
	printf("\n<<���� ����>>\n");
	insertion_sort(arr, n);
	free(arr);
}

void bubble_sort(int arr[], int n)
{
	int use;
	printf("1 �Է½� ��ȯ Ƚ���� 0�� �� ����\n");
	printf("�׿�.�������� ����");
	printf("�Է�:");
	scanf("%d", &use);
	int temp;
	int total = 0;
	int cnt;
	int j;
	for (int i = n - 1; i > 0; i--)
	{
		cnt = 0;
		printf("<<%d�ܰ�>>\n", n-i);
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
			printf("��Ƚ�� %d ��ȯ Ƚ�� %d\n", i, cnt);
			return;
		}
		print3(arr, n, i);
		printf("��Ƚ�� %d ��ȯ Ƚ�� %d\n", i, cnt);
	}
	printf("���\n");
	print3(arr, n, 0);
}

void S3(int n)
{
	int *arr = malloc(sizeof(int)*n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	printf("������ ����:");
	print(arr, n);
	printf("\n<<���� ����>>\n");
	bubble_sort(arr, n);
	free(arr);
}

int main(void)
{
	bool b = true;
	while (b) {
		int use;
		printf("1.��������\n");
		printf("2.��������\n");
		printf("3.��������\n");
		printf("�׿�. ����");
		printf("����:");
		scanf("%d", &use);
		int n;
		switch (use)
		{
		case 1:
			printf("n�� �� �Է�:");
			scanf("%d", &n);
			S1(n);
			break;
		case 2:
			printf("n�� �� �Է�:");
			scanf("%d", &n);
			S2(n);
			break;
		case 3:
			printf("n�� �� �Է�:");
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