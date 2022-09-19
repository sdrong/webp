#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_SIZE 10

#define MAX_QUEUE_SIZE 100


typedef int element;

typedef struct QueueType
{
	element queue[MAX_QUEUE_SIZE];
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

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화된 상태");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

#define BUCKET 10
#define DIGIT 4

void radix_sort(int list[], int n)
{
	int factor = 1;
	QueueType queues[BUCKET];
	for (int i = 0; i<BUCKET; i++)
	{
		queue_init(&queues[i]);
	}
	for (int i = 0; i < DIGIT; i++)
	{
		for (int j = 0; j < n; j++)
		{
			enqueue(&queues[list[j] / factor % 10], list[j]);
		}
		for (int u = 0, j = 0; u < BUCKET; u++)
		{
			printf("[%d]->", u);
			while (!is_empty(&queues[u]))
			{
				list[j] = dequeue(&queues[u]);
				printf("%5d", list[j++]);
			}
			printf("\n");
		}
		printf("\n");
		factor *= 10;
	}
}

int main(void)
{
	int list[MAX_SIZE];
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = rand() % 10000;
	}
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%5d", list[i]);
	printf("\n");
	radix_sort(list, MAX_SIZE);
	printf("\n");
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%5d", list[i]);
	return 0;
}