#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SIZE 6
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main(void)
{
	int list1[SIZE];
	int list2[SIZE];
	int temp;
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d번쨰 숫자 입력:", i + 1);
		scanf("%d", &list2[i]);
	}
	for (int i = 0; i <= SIZE; i++)
	{
		for (int j = 0; j < i; j++)
			printf("%3d", list1[j]);
		printf("\n(");
		for (int q = i+1; q < SIZE; q++)
		{
			if (list2[i] > list2[q])
				SWAP(list2[i], list2[q], temp);
		}
		for (int r = i; r < SIZE; r++)
		{
			printf("%3d", list2[r]);
		}
		printf(")\n");
		list1[i] = list2[i];
	}
	return 0;
}