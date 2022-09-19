#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 400

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType* q)
{
	printf("DEQUE(front=%d rear= %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		error("큐가 포화 상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백 상태입니다.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	DequeType d;
	init_deque(&d);
	for (int i = 1; i <= n; i++)
	{
		add_rear(&d, i);
	}
	int* data = malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &data[i]);
	}
	int count = 0;
	int tmp;
	int min, max;
	for (int i = 0; i < m; i++)
	{
		min = get_front(&d);
		max = get_rear(&d);
		int mid = (min + max) / 2;
		if (data[i] < mid && min < max)
		{
			do {
				tmp = delete_front(&d);
				if (data[i] != tmp)
				{
					add_rear(&d, tmp);
					count++;
				}
			} while (data[i] != tmp);
		}
		else if (data[i] < mid && min > max)
		{
			do {
				tmp = delete_rear(&d);
				add_front(&d, tmp);
				tmp = delete_front(&d);
				if (data[i] != tmp)
				{
					add_front(&d, tmp);
				}
				count++;
			} while (data[i] != tmp);
		}
		else if (data[i] > mid && min > max)
		{
			do {
				tmp = delete_front(&d);
				if (data[i] != tmp)
				{
					add_rear(&d, tmp);
					count++;
				}
			} while (data[i] != tmp);
		}
		else if (data[i] > mid && min < max)
		{
			do {
				tmp = delete_rear(&d);
				add_front(&d, tmp);
				tmp = delete_front(&d);
				if (data[i] != tmp)
				{
					add_front(&d, tmp);
				}
				count++;
			} while (data[i] != tmp);
		}
	}
	printf("%d", count);
	free(data);
	return 0;
}