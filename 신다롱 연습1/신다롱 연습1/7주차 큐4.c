#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>
#define MAX_QUEUE_SIZE 10

typedef struct
{
	int id;
	int arrival_time;
	int service_time;
}element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
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

int main(void)
{
	int minite = 60;
	int total_wait = 0;
	int total_customer = 0;
	int service_time1 = 0;
	int service_customer1;
	int service_time2 = 0;
	int service_customer2;
	Queue_Type q;
	init(&q);

	srand(time(NULL));
	for (int clock = 0; clock < minite; clock++)
	{
		printf("현재시간 %d\n", clock);
		if (rand() % 10 < 5)
		{
			element customer;
			customer.id = ++total_customer;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&q, customer);
			printf("고객%d가 %d분에 들어옵니다. 업무처리시간%d\n",
				customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time1 > 0 && service_time2 > 0)
		{
			printf("One에서 고객 %d Two에서 고객 %d가 업무 처리중입니다.\n", service_customer1, service_customer2);
			service_time1--, service_time2--;
		}
		else if(service_time2>0 && !(service_time1>0)){
			if (!is_empty(&q)) {
				element customer1 = dequeue(&q);
				service_customer1 = customer1.id;
				service_time1 = customer1.service_time;
				printf("One에서 고객%d가 %d분에 업무를 실시합니다. 대기시간은 %d분이였습니다.\n",
					customer1.id, clock, clock - customer1.arrival_time);
				total_wait += clock - customer1.arrival_time;
			}
		}
		else if (service_time1 > 0 && !(service_time2>0)) {
			if (!is_empty(&q)) {
				element customer2 = dequeue(&q);
				service_customer2 = customer2.id;
				service_time2 = customer2.service_time;
				printf("Two에서 고객%d가 %d분에 업무를 실시합니다. 대기시간은 %d분이였습니다.\n",
					customer2.id, clock, clock - customer2.arrival_time);
				total_wait += clock - customer2.arrival_time;
			}
		}
		else
		{
			if (!is_empty(&q)) {
				element    customer1 = dequeue(&q);
				service_customer1 = customer1.id;
				service_time1 = customer1.service_time;
				printf("One에서 고객%d가 %d분에 업무를 실시합니다. 대기시간은 %d분이였습니다.\n",
					customer1.id, clock, clock - customer1.arrival_time);
				total_wait += clock - customer1.arrival_time;
			}
			if (!is_empty(&q)) {
				element customer2 = dequeue(&q);
				service_customer2 = customer2.id;
				service_time2 = customer2.service_time;
				printf("Two에서 고객%d가 %d분에 업무를 실시합니다. 대기시간은 %d분이였습니다.\n",
					customer2.id, clock, clock - customer2.arrival_time);
				total_wait += clock - customer2.arrival_time;
			}
		}
		Sleep(30);
	}
	printf("전체 대기시간 %d분\n", total_wait);
	return 0;
}