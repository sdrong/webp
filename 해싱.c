#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int arr[13];

int hashinsert(int x)
{
	return x % 11;
}

void hashSearch(int* arr, int x) // 선형
{
	int value, i;
	value = i = hashinsert(x);
	int inc = 0;
	while (arr[i] != NULL) {
		i = hashinsert(1 + i);
		if (i == value)
			return;
	}
	arr[i] = x;
}

void hashSearch2(int* arr, int x) // 이차원
{
	int value, i;
	value = i = hashinsert(x);
	int inc = 1;
	while (arr[i] != NULL) {
		i = hashinsert(inc*inc + x);
		if (i == value)
			return;
		inc += 1;
	}
	arr[i] = x;
}

void hashSearch3(int* arr, int x) // 이차원
{
	int value, i;
	value = i = hashinsert(x);
	int inc = 1;
	while (arr[i] != NULL) {
		i = hashinsert(x + (inc * (7 - x % 7)));
		if (i == value)
			return;
		inc += 1;
	}
	arr[i] = x;
}

int main(void)
{
	int pp[11] = { 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5 };
	for (int i = 0; i < 11; i++)
	{
		hashSearch3(arr, pp[i]);
	}
	for(int i = 0; i < 11; i++)
		printf("%d ", arr[i]);
	return 0;
}