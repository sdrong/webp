#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int fibo(int n, int arr[])
{
	arr[n]++;
	int sum = 0;
	if (n <= 1)
		sum = n;

	if (n > 1)
	{
		sum += fibo(n - 1, arr) + fibo(n - 2, arr);
	}
	return sum;
}

int main(void)
{
	int n, result = 0;
	int arr[20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = 0;
	}
	printf("피보나치 수열 입력:");
	scanf("%d", &n);
	result = fibo(n, arr);
	for (int i = 0; i < n; i++)
	{
		printf("fibo(%d): %d번 호출\n", i, arr[i]);
	}
	printf("result: %d\n", result);
	return 0;
}