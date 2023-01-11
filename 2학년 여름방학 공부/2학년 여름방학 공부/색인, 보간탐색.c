#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
#define INDEX_SIZE 256
typedef struct {
	int key;
	int index;
}itable;

itable index_list[INDEX_SIZE];
int list[MAX_SIZE];


int compare(const void* arg1, const void* arg2)
{
	if (*(int*)arg1 > *(int*)arg2)
		return 1;
	else if (*(int*)arg1 == *(int*)arg2)
		return 0;
	else
		return -1;
}


int seq_search(int key, int low, int high)
{
	int i;

	for (int i = low; i <= high; i++)
		if (list[i] == key)
			return i;
	return -1;
}

//색인탐색

int search_index(int key, int n)
{
	int i, low, high;

	if (key<list[0] || key>list[n - 1])
	{
		return -1;
	}

	for (i = 0; i < INDEX_SIZE; i++)
	{
		printf("%d\n", index_list[i].key);
		if (index_list[i].key <= key && index_list[i + 1].key > key)
			break;
	}
	printf("i= %d\n", i);
	if (i == INDEX_SIZE)
	{
		low = index_list[i - 1].index;
		printf("low = %d\n", low);
		high = n;
	}
	else
	{
		low = index_list[i].index;
		high = index_list[i + 1].index;
	}
	return seq_search(key, low, high);
}

//보간탐색

int interpol_search(int key, int n)
{
	int low, high, j;

	low = 0;
	high = n - 1;
	while ((list[high] >= key) && (key > list[low]))
	{
		j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low;
		if (key > list[j])
			low = j + 1;
		else if (key < list[j])
			high = j - 1;
		else
			low = j;

	}
	if (list[low] == key)
		return(low);
	else return -1;
}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = rand()%100;
		printf("%3d", list[i]);
	}
	printf("\n정렬 후\n");
	qsort((void*)list, (size_t)10, sizeof(int), compare);
	int w = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (i%4 == 0)
		{
			index_list[w].key = list[i];
			index_list[w++].index = seq_search(list[i], 0, 9);
		}
		printf("%d ", list[i]);
	}
	int key;
	printf("\n찾을 숫자 입력:");
	scanf("%d", &key);
	if (interpol_search(key, MAX_SIZE) == -1)
		printf("not find");
	else
	{
		printf("find clear index: %d", interpol_search(key, MAX_SIZE));
	}
	return 0;
}