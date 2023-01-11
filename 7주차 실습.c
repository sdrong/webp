#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define MAX_SIZE 100
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

void print2(int arr[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

void heapy(int arr[], int k, int n)
{
	int left = 2 * k;
	int right = 2 * k + 1;
	int big;
	int temp;
	if (right <= n)
	{
		if (arr[left] > arr[right])
			big = left;
		else
			big = right;
	}
	else if (left <= n)
	{
		big = left;
	}
	else
		return;
	if (arr[big] > arr[k])
	{
		printf("arr[%d]: %d�� arr[%d]: %d ��ȯ\n", k, arr[k], big, arr[big]);
		SWAP(arr[k], arr[big], temp);
		printf("\n");
		heapy(arr, big, n);
	}
}

void build_heap(int arr[], int n)
{
	for (int i = n / 2; i > 0; i--)
		heapy(arr, i, n);
}

void heap_sort(int arr[], int n)
{
	int temp;
	build_heap(arr, n);
	printf("<<�ʱ� ��>>\n");
	print2(arr, n);
	for (int i = n; i > 1; i--)
	{
		printf("<<�ִ� ��>>\n");
		print2(arr, i);
		printf("%d Ż��\n", arr[1]);
		SWAP(arr[i], arr[1], temp);
		heapy(arr, 1, i - 1);
	}
}

void S1(void)
{
	int n;
	printf("�Է�:");
	scanf("%d", &n);
	srand(time(NULL));
	int* arr = malloc(sizeof(int) * (n+1));
	for (int i = 1; i <= n; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("������ ����\n");
	print2(arr, n);
	heap_sort(arr, n);
	printf("���ĵ� ����\n");
	print2(arr, n);
}

#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;

typedef struct HeapType {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void hprint(HeapType* h)
{
	printf("���� ���� ����\n");
	if (h->heap_size < 0)
	{
		printf("���� ����ֽ��ϴ�.");
		return;
	}
	printf("<< ");
	for (int i = 1; i <= h->heap_size; i++)
	{
		printf("%2d ", h->heap[i].key);
	}
	printf(">>\n");
}

HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void S2(void)
{
	HeapType* h;
	h = create();
	init(h);
	int use = 1;
	element num;
	int n;
	while (use != 0)
	{
		printf("1.���\n");
		printf("2.����\n");
		printf("3.����\n");
		printf("�Է�:");
		scanf("%d", &use);
		switch (use)
		{
		case 1:
			hprint(h);
			break;
		case 2:
			printf("�߰��� ���� �Է�:");
			scanf("%d", &num.key);
			insert_max_heap(h, num);
			hprint(h);
			break;
		case 3:
			if (h->heap_size < 0)
			{
				printf("������ ��Ʈ�� �����ϴ�.\n");
				break;
			}
			printf("��Ʈ ����:");
			printf("%d\n", delete_max_heap(h).key);
			hprint(h);
			break;
		default:
			break;
		}
	}
}

#define MAX_QUEUE_SIZE 100


typedef int element1;

typedef struct QueueType
{
	element1 queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void queue_init(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element1 item)
{
	if (is_full(q))
		error("ť�� ��ȭ�� ����");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element1 dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


#define BUCKETS 8
#define DIGITS 5
void radix_sort(int arr[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];
	for (b = 0; b < BUCKETS; b++)
		queue_init(&queues[b]);
	for (d = 0; d < DIGITS; d++)
	{
		for (i = 0; i < n; i++)
			enqueue(&queues[(arr[i] / factor) % 10], arr[i]);
		for (b = i = 0; b < BUCKETS; b++)
		{
			while (!is_empty(&queues[b]))
				arr[i++] = dequeue(&queues[b]);
		}
		printf("<<%d �� �ڸ� ����>>\n", factor);
		factor *= 10;
		print(arr, n);
	}
}

int change(int num)
{
	char ch_num[100];
	sprintf(ch_num,"%o\n", num);
	int i_num = atoi(ch_num);
	return i_num;
}

void S3(void)
{
	int n;
	printf("�Է�:");
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		arr[i] = change(rand()) % 100000;
	printf("\n<<������ ��>>: ");
	print(arr, n);
	radix_sort(arr, n);
	printf("\n<<���� �Ϸ�� ��>>: ");
	print(arr, n);
}

int main(void)
{
	bool b = true;
	while (b) {
		int use;
		printf("1. ������\n");
		printf("2. �� �켱����ť\n");
		printf("3. �������\n");
		printf("�׿�. ����\n");
		printf("����:");
		scanf("%d", &use);
		int n;
		switch (use)
		{
		case 1:
			S1();
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