#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 15

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
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
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
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void Fibo(int n)
{
	Queue_Type s;
	init(&s);
	int n1;
	int n2;
	if (n == 1)
	{
		printf("0\n");
		exit(1);
	}
	else if (n == 2)
	{
		printf("1\n");
		exit(1);
	}
	enqueue(&s, 0);
	enqueue(&s, 1);
	for (int i = 2; i < n; i++)
	{
		n1 = dequeue(&s);
		n2 = peek(&s);
		enqueue(&s, n1 + n2);
	}
	n1 = dequeue(&s);
	printf("%d", dequeue(&s));
}

int main(void)
{
	int n;
	printf("숫자입력:");
	scanf("%d", &n);
	Fibo(n);
	return 0;
}
// 0 1 1 2 3 5 8 13 21

/*
* 좀 더 짧음
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_DEQUE_SIZE 50
typedef int element;

typedef struct {
	element data[MAX_DEQUE_SIZE];
	int front;
	int rear;
}Deque_Type;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

int is_full(Deque_Type* q)
{
	return ((q->rear + 1) % MAX_DEQUE_SIZE == q->front);
}

int is_empty(Deque_Type* q)
{
	return (q->rear == q->front);
}

void init_deque(Deque_Type* q)
{
	q->front = q->rear = 0;
}

void Deque_print(Deque_Type* q)
{
	printf("front = %d, rear = %d\n", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % MAX_DEQUE_SIZE;
			printf("%d |", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(Deque_Type* q, element item)
{
	if (is_full(q))
		error("포화에러");
	q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
	q->data[q->rear] = item;
}

void add_front(Deque_Type* q, element item)
{
	if (is_full(q))
		error("포화에러");
	q->data[q->front] = item;
	q->front = (q->front -1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

int del_rear(Deque_Type* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("공복에러");
	q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	return q->data[prev];
}

int del_front(Deque_Type* q)
{
	if (is_empty(q))
		error("공복에러");
	q->front = (q->front + 1) % MAX_DEQUE_SIZE;
	return q->data[q->front];
}

int get_front(Deque_Type* q)
{
	if (is_empty(q))
		error("공복에러");
	return q->data[(q->front+1) % MAX_DEQUE_SIZE];
}

int get_rear(Deque_Type* q)
{
	if (is_full(q))
		error("포화에러");
	return q->data[q->rear];
}

void Fibo(Deque_Type* q, element n)
{
	if (n == 1)
	{
		printf("0\n");
		exit(1);
	}
	else if (n == 2)
	{
		printf("1\n");
		exit(1);
	}
	add_rear(q, 0);
	add_rear(q, 1);
	int n1, n2;
	for (int i = 0; i < n - 2; i++)
	{
		n2 = del_rear(q);
		n1 = del_rear(q);
		add_rear(q, n2);
		add_rear(q, n1 + n2);
	}
	printf("%d", del_rear(q));
}

int main(void)
{
	Deque_Type q;
	init_deque(&q);
	int n;
	printf("숫자를 입력하시오:");
	scanf("%d", &n);
	Fibo(&q, n);
	return 0;
}*/