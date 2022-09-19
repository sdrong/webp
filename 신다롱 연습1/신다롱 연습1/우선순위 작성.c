#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_ELEMENT 200
typedef struct {
	char data[20];
	int key;
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
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
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

element choice_del(HeapType* h, element del)
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

void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++)
	{
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--)
	{
		a[i] = delete_max_heap(h);
	}
	free(h);
}

int main(void)
{
	HeapType* heap;
	bool b = true;
	heap = create();
	init(heap);
	while (b)
	{
		element e;
		char use;
		printf("삽입(i), 삭제(d)");
		scanf("%c", &use);
		getchar();
		switch (use)
		{
		case 'i':
			printf("할일: ");
			scanf("%[^\n]s", e.data);
			getchar();
			printf("우선순위: ");
			scanf("%d", &e.key);
			getchar();
			insert_max_heap(heap, e);
			break;
		case 'd':
			e = delete_max_heap(heap);
			printf("제일 우선 순위가 높은 일은 \"%s\"", e.data);
			break;
		case 'c':
			printf("삭제하고자 하는 데이터 명을 입력하시오:");
			scanf("%[^\n]s", e.data);
			choice_del(heap, e);
		default:
			printf("종료\n");
			b = false;
			break;
		}
	}

	
	return 0;
}