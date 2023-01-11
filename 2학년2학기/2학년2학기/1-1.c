#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int big_num(int arr[])
{
	int big = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (big < arr[i])
			big = arr[i];
	}
	return big;
}

int big_num2(int arr[], int big, int i)
{
	if (i >= 10)
		return big;
	if (big < arr[i])
		big = arr[i];
	return big_num2(arr, big, i+1);
}

int main(void)
{
	int arr[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < 10; i++)
		printf("[%d] ", arr[i]);

	printf("가장 큰 수: %d\n", big_num2(arr, arr[0], 1));
	return 0;
}