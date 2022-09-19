#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 101
typedef int element;

typedef struct {
	element* data;
	int capacity;
	int top;
}StackType;

void init(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return ((s->capacity - 1) == s->top);
}

void push(StackType* s, element n)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		s->data =(element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = n;
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공백상태입니다\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}

int main(void)
{
	StackType s;
	init(&s);
	push(&s, 3);
	push(&s, 2);
	push(&s, 1);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	free(s.data);
	return 0;
}