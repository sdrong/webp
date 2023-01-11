#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct dot {
	int x;
	int y;
}dot;

void repeat(dot arr[])
{
	for (int i = 0; i < 5; i++)
	{
		printf("%f\n", sqrt(pow(arr[i].x, 2) + pow(arr[i].y, 2)));
	}
}

void recursive(dot arr[], int i)
{
	if (i < 5)
	{
		printf("%f\n", sqrt(pow(arr[i].x, 2) + pow(arr[i].y, 2)));
		recursive(arr, i + 1);
	}
}

typedef struct dot2 {
	int x;
	int y;
	struct dot2* link;
}dot2;

void repeat2(dot2 *arr)
{
	while (arr)
	{
		printf("%f\n", sqrt(pow(arr->x, 2) + pow(arr->y, 2)));
		arr = arr->link;
	}
}

void recursive2(dot2 *arr)
{
	if (arr)
	{
		printf("%f\n", sqrt(pow(arr->x, 2) + pow(arr->y, 2)));
		recursive2(arr->link);
	}
}

int main(void)
{
	dot arr[5] = { {1,5},{3,4}, {5,2}, {7,3},{2,3}};
	dot2* arr2 = malloc(sizeof(dot2));
	dot2* tmp;
	arr2->x = arr[0].x;
	arr2->y = arr[0].y;
	arr2->link = NULL;
	dot2* tmp2 = arr2;
	for (int i = 1; i < 5; i++)
	{
		tmp = malloc(sizeof(dot2));
		tmp->x = arr[i].x;
		tmp->y = arr[i].y;
		tmp->link = NULL;
		tmp2->link = tmp;
		tmp2 = tmp2->link;
	}
	recursive2(arr2);

	for (int i = 0; i < 5; i++)
	{
		tmp = arr2;
		arr2 = arr2->link;
		free(tmp);
	}
	return 0;
}