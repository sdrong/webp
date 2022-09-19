#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front;
	int rear;
}Queue_Type;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(Queue_Type* q)
{
	q->front = q->rear = 0;
}

int is_empty(Queue_Type* q)
{
	return (q->front == q->rear);
}

int is_full(Queue_Type* q)
{
	return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

void queue_print(Queue_Type* q)
{
	printf("Queue(front: %d, rear: %d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(Queue_Type* q, element item)
{
	if (is_full(q))
		error("큐가 포화 상태입니다.\n");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(Queue_Type* q)
{
	if (is_empty(q))
		error("큐가 공백 상태입니다.\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(Queue_Type* q)
{
	if (is_empty(q))
		error("큐가 공백 상태입니다.\n");
	return q->data[(q->front + 1)% MAX_QUEUE_SIZE];
}

int main(void)
{
	int element;
	Queue_Type q;
	init(&q);
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		if (rand() % 5 == 0)
			enqueue(&q, rand() % 100);
		queue_print(&q);
		if (rand() % 10 == 0)
		{
			int data = dequeue(&q);
		}
		queue_print(&q);
	}
	return 0;
}