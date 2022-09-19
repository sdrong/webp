#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int here;
	int j;
	for (int i = 1; i < n; i++)
	{
		int here = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] < here)
				break;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = here;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
	return 0;
}