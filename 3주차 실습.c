#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void print(int arr[], int num)
{
	for (int i = 0; i < num; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void Search(int arr[], int key, int s, int e, int try)
{
	int mid = (s + e) / 2;
	if (s > e)
	{
		printf("찾지 못하였습니다\n");
		printf("시도횟수 %d\n", try - 1);
		return;
	}
	printf("arr[%d] ~ arr[%d] 탐색\n", s, e);
	printf("현재위치 arr[%d] 값:%d\n", mid, arr[mid]);
	if (arr[mid] == key)
	{
		printf("찾았습니다. arr[%d]에 있었습니다.\n", mid);
		printf("시도횟수 %d\n", try);
		return;
	}
	if (arr[mid] < key)
		Search(arr, key, mid + 1, e, try + 1);
	else
		Search(arr, key, s, mid - 1, try + 1);
}

int get_try(int arr[], int key, int s, int e)
{
	int try = 1;
	int mid = (s + e) / 2;
	if (s > e)
		return try-1;
	if (arr[mid] == key)
		return try;
	if (arr[mid] < key)
		try = get_try(arr, key, mid + 1, e)+1;
	else
		try = get_try(arr, key, s, mid - 1)+1;
	return try;
}

void S1(int num)
{
	int* arr = malloc(sizeof(int) * num);
	srand((unsigned int )time(NULL));
	for (int i = 0; i < num; i++)
	{
		arr[i] = rand() % 100;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
		printf("%d 삽입\n", arr[i]);
	}
	print(arr, num);
	for (int i = 0; i < num-1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	print(arr, num);
	int key;
	printf("찾을 숫자 입력:");
	scanf("%d", &key);
	Search(arr, key, 0, num-1, 1);
	double aver = 0;
	int big = 0;
	printf("다 찾을때 비교 횟수\n");
	int num_2 = num;
	int temp;
	for (int i = 0; i < num; i++)
	{
		if (i == num - 1)
			temp = NULL;
		else
			temp = arr[i + 1];
		int data = get_try(arr, arr[i], 0, num-1);
		if (temp == arr[i])
		{
			num_2--;
		}
		else
		{
			printf("arr[%d] 찾을떄 %d횟수\n", i, data);
			aver += data;
		}
		if (big < data)
			big = data;
	}
	printf("최악의 경우%d\n", big);
	printf("다 찾을떄 평균비교 %f \n", aver / num_2);

	aver = 0;
	printf("다 못찾을때 비교 횟수\n");
	num_2 = num;
	for (int i = 0; i < num; i++)
	{
		int use = arr[i] + 1;
		if (i != num - 1)
		{
			if (use == arr[i + 1])
			{
				num_2--;
				continue;
			}
		}
		int data = get_try(arr, use, 0, num, 1);
		printf("못찾을떄 %d횟수\n", data);
		aver += data;
		if (big < data)
			big = data;
	}
	printf("다 못찾을떄 평균비교 %f \n", aver / num_2);
	return;
}

// 2번 문제

typedef struct ListNode {
	int n;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create()
{
	ListType* plist = malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int num)
{
	ListNode* temp = malloc(sizeof(ListNode));
	if (temp == NULL)
		error("메모리 할당 에러");
	temp->n = num;
	temp->link = NULL;
	if (plist->tail == NULL)
	{
		plist->head = plist->tail = temp;
	}
	else
	{
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

int merge(int arr1[], int arr2[], int result[])
{
	int i1 = sizeof(arr1);
	int i2 = sizeof(arr2);
	int r1 = 0;
	int s1 = 0;
	int s2 = 0;
	while (s1 < i1 && s2 < i2)
	{
		if (arr1[s1] < arr2[s2])
			result[r1++] = arr1[s1++];
		else
			result[r1++] = arr2[s2++];
	}
	if (s1 >= i1)

		while (s2 <= i2)
			result[r1++] = arr2[s2++];
	else
		while (s1 <= i1)
			result[r1++] = arr1[s1++];
	return result;
}

ListNode* merge2(ListNode* n1, ListNode* n2)
{
	ListNode* start;
	ListNode* end;
	if (n1->n < n2->n)
	{
		start = n1;
		end = start;
		n1 = n1->link;
	}
	else
	{
		start = n2;
		end = start;
		n2 = n2->link;
	}
	while (n1 != NULL && n2 != NULL)
	{
		if (n1->n <= n2->n)
		{
			end->link = n1;
			end = n1;
			n1 = n1->link;
		}
		else
		{
			end->link = n2;
			end = n2;
			n2 = n2->link;
		}
	}
	if (n1 == NULL)
	{
		while (n2)
		{
			end->link = n2;
			end = n2;
			n2 = n2->link;
		}
	}
	else
	{
		while (n1)
		{
			end->link = n1;
			end = n1;
			n1 = n1->link;
		}
	}
	return start;
}

void print_list(ListType* list)
{
	ListNode* node = list->head;
	while (node)
	{
		printf("%d ", node->n);
		node = node->link;
	}
	printf("\n");
}

void print2(ListNode* node)
{
	while (node)
	{
		printf("%d ", node->n);
		node = node->link;
	}
	printf("\n");
}

void S2_1(void)
{
	int arr1[4] = { 5,7, 24,56 };
	for (int i = 0; i < 4; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	int arr2[5] = { 19, 45, 61, 79, 92 };
	for (int i = 0; i < 5; i++)
		printf("%d ", arr2[i]);
	printf("\n");
	int result[9];
	merge(arr1, arr2, result);
	for (int i = 0; i < 9; i++)
		printf("%d ", result[i]);
	printf("\n");

}

void S2_2(void)
{
	int arr1[4] = { 5,7, 24,56 };
	int arr2[5] = { 19, 45, 61, 79, 92 };
	ListType* l1;
	l1 = create();
	ListType* l2;
	l2 = create();
	for (int i = 0; i < 4; i++)
		insert_last(l1, arr1[i]);
	for (int i = 0; i < 5; i++)
		insert_last(l2, arr2[i]);
	ListType* result2;
	result2 = create();
	print_list(l1);
	print_list(l2);

	ListNode* head = merge2(l1->head, l2->head);
	result2->head = head;
	print_list(result2);
}

int S2(void)
{
	printf("배열 형태\n");
	S2_1();
	printf("연결리스트 형태\n");
	S2_2();
	return 0;
}

//3번문제

int hanoi(int n, int from, int temp, int target, int cnt) {
	if (n == 1) {
		printf("%d번기둥에서 %d번기둥으로\n", from, target);
		cnt += 1;
		return cnt;
	}
	else {
		cnt = hanoi(n - 1, from, target, temp, cnt);
		printf("%d번기둥에서 %d번기둥으로\n", from, target);
		cnt += 1;
		cnt = hanoi(n - 1, temp, from, target, cnt);
		return cnt;
	}
}

int S3(void) {
	int n;
	printf("원반개수 : ");
	scanf("%d", &n);
	printf("총 움직임 횟수 : %d\n", hanoi(n, 1, 2, 3, 0));
}

int main(void)
{
	bool b = true;
	while (b)
	{
		int ch;
		printf("1번 검색트리\n");
		printf("2번 병합정렬\n");
		printf("3번 하노이 타워\n");
		printf("그외. 종료\n");
		printf("입력: ");
		scanf("%d", &ch);
		int num;
		switch (ch)
		{
		case 1:
			printf("몇개의 값을 넣을것인가?\n 입력:");
			scanf("%d", &num);
			S1(num);
			break;
		case 2:
			S2();
			break;
		case 3:
			S3();
			break;
		default:
			b = false;
			break;
		}

	}
	return 0;
}