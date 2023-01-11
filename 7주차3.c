#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

#define MAX_SIZE 100
typedef struct {
	char name[10];
	int num;
}element;
typedef struct {
	element data[MAX_SIZE];
	int front, rear;
}Queue_Type;

void init(Queue_Type* q)
{
	q->front = q->rear = 0;
}

int is_full(Queue_Type* q)
{
	return (q->front == (q->rear + 1) % MAX_SIZE);
}

int is_empty(Queue_Type* q)
{
	return (q->front == q->rear);
}

void enqueue(Queue_Type* q, element item)
{
	if (is_full(q))
	{
		fprintf(stderr, "포화에러\n");
		exit(1);
	}
	q->rear = (q->rear + 1) %MAX_SIZE;
	q->data[q->rear] = item;
}

element dequeue(Queue_Type* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "공복에러\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_SIZE;
	return q->data[q->front];
}

element peek(Queue_Type* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "공복에러\n");
		exit(1);
	}
	return q->data[q->front];
}

int main(void)
{
	Queue_Type male;
	init(&male);
	Queue_Type famale;
	init(&famale);
	int man_num = 0;
	int woman_num = 0;
	srand(time(NULL));
	for (int i = 0; i < 60; i++)
	{
		if (rand() % 2 == 0)
		{
			element man;
			man.num = ++man_num;
			sprintf(man.name, "남%d", man.num);
			enqueue(&male, man);
			if (!is_empty(&famale))
			{
				element m=dequeue(&male);
				element w= dequeue(&famale);
				printf("%s %s 매치\n", m.name, w.name);
			}
			else
				printf("%s대기\n", man.name);
		}
		else
		{
			element woman;
			woman.num = ++woman_num;
			sprintf(woman.name, "여%d", woman.num);
			enqueue(&famale, woman);
			if (!is_empty(&male))
			{
				element m = dequeue(&male);
				element w = dequeue(&famale);
				printf("%s %s 매치\n", m.name, w.name);
			}
			else
				printf("%s대기\n", woman.name);
		}
	}Sleep(100);
	return 0;
}