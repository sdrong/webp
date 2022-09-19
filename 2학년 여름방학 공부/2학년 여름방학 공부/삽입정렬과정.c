#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define SIZE 6
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main(void)
{
	int i, j;
	int list1[SIZE];
	int list2[SIZE];
	int k = 0;
	int temp;
	for (i = 0; i < SIZE; i++)
	{
		list1[i] = NULL;
		printf("%d번째 숫자입력", i + 1);
		scanf("%d", &list2[i]);
	}
	printf("\n과정 출력 \n");
	for (i = 0; i < SIZE; i++)
	{
		list1[i] = list2[i];
		for (int q = 0; q <= i; q++)
		{
			for (int w = q + 1; w <= i; w++)
			{
				if (list1[q] > list1[w] && list1[w] != NULL)
					SWAP(list1[q], list1[w], temp);
			}
		}
		for (j = 0; list1[j] != NULL && j<SIZE; j++)
		{
			printf("%3d", list1[j]);
		}
		printf("\n");
		printf("(");
		for (j = i+1; j < SIZE; j++)
		{
			printf("%3d", list2[j]);
		}
		printf(")\n");
		
	}
	return 0;
}