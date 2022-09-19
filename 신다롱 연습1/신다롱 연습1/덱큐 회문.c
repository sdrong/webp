#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10

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
		error("ť�� ��ȭ �����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ���� �����Դϴ�.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[q->rear];
}

void Palindrome(char* data)
{
	int len = strlen(data);
	DequeType d;
	init_deque(&d);
	int rlen = len;
	char head;
	char tail;
	for (int i = 0; i < len; i++)
	{
		if ((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z'))
		{  
			data[i] = tolower(data[i]);
			add_rear(&d, data[i]);
		}
		else
			rlen--;
	}
	for (int i = 0; i < rlen / 2; i++)
	{
		head = delete_front(&d);
		tail = delete_rear(&d);
		printf("h:%c, t:%c\n", head, tail);
		if (head != tail)
		{
			printf("ȸ���� �ƴմϴ�.\n");
			exit(1);
		}
	}
	printf("ȸ���Դϴ�.\n");
}

int main(void)
{
	char* data = malloc(sizeof(char) * 51);
	printf("���ڿ� �Է�:");
	scanf("%[^\n]s", data);
	Palindrome(data);
	return 0;
}