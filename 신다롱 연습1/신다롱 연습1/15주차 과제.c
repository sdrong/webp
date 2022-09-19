#include<stdio.h>
#include<stdbool.h>
#define MAX_ELEMENT 30

typedef struct {
	char id[20];
	int amount;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

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

	while ((i != 1) && (item.amount > h->heap[i / 2].amount)) {
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
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].amount) < h->heap[child + 1].amount)
			child++;
		if (temp.amount >= h->heap[child].amount)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void print(HeapType* h)
{
	for (int i = 1; i <= h->heap_size; i++)
	{
		printf("[id: %s, 후원금액: %d] ->", h->heap[i].id, h->heap[i].amount);
	}
	printf("\n");
}

int main(void)
{
	HeapType* h;
	h = create();
	init(h);
	element e1 = { "aaa", 123 };
	element e2 = { "bbb", 223 };
	element e3 = { "ccc", 323 };
	element e4 = { "ddd", 133 };
	element e5 = { "eee", 143 };
	insert_max_heap(h, e1);
	print(h);
	insert_max_heap(h, e2);
	print(h);
	insert_max_heap(h, e3);
	print(h);
	insert_max_heap(h, e4);
	print(h);
	insert_max_heap(h, e5);
	print(h);
	for (int i = 0; i < 5; i++)
	{
		element e = delete_max_heap(h);
		printf("후원자 id: %s, 후원액수: %d\n", e.id, e.amount);
		printf("큐의 현재 상태\n");
		print(h);
	}
	int choice;
	bool b = true;
	while (b)
	{
		printf("1.삽입 \n2.삭제 \n그 외.종료\n입력:");
		scanf("%d", &choice);
		element data;
		switch (choice)
		{
		case 1:
			printf("후원자의 ID와 액수를 입력:");
			scanf("%s %d:", data.id, &data.amount);
			insert_max_heap(h, data);
			printf("큐의 상태\n");
			print(h);
			break;
		case 2:
			printf("가장 돈 많은 후원자 삭제\n");
			data = delete_max_heap(h);
			printf("후원자 id: %s, 후원액수: %d\n", data.id, data.amount);
			printf("큐의 상태\n");
			print(h);
			break;
		default:
			printf("종료\n");
			b = false;
			break;
		}
	}
	return 0;
}