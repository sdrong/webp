#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100

typedef struct {
	short r;
	short c;
}element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}Stack_Type;

void init_stack(Stack_Type* s)
{
	s->top = -1;
}

int is_full(Stack_Type* s)
{
	return (s->top == MAX_STACK_SIZE - 1);
}

int is_empty(Stack_Type* s)
{
	return (s->top == -1);
}

void Push(Stack_Type* s, element n)
{
	if (is_full(s))
	{
		fprintf(stderr, "포화에러\n");
		return;
	}
	else
		s->data[++(s->top)] = n;
}

element Pop(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공백에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

element peek(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공백 에러");
		exit(1);
	}
	else
		return s->data[s->top];
}

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'}
};

element here = { 1,0 }, entry = { 1,0 };

void push_loc(Stack_Type* s, int r, int c)
{
	if (r < 0 || c < 0)
		return;
	if (maze[r][c] != '1' && maze[r][c] != '.')
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		Push(s, tmp);
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++)
	{
		for (int c = 0; c < MAZE_SIZE; c++)
		{
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void)
{
	int r, c;
	Stack_Type s;
	init_stack(&s);
	Stack_Type s2;
	init_stack(&s2);
	Stack_Type s3;
	init_stack(&s3);
	here = entry;
	while (maze[here.r][here.c] != 'x')
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s))
		{
			printf("실패\n");
			return 0;
		}
		else
		{
			here = Pop(&s);
			push_loc(&s2, here.r, here.c);
		}
	}
	element q;
	while (!is_empty(&s2))
	{
		q = Pop(&s2);
		Push(&s3, q);
	}
	while (!is_empty(&s3))
	{
		q = Pop(&s3);
		printf("(%d, %d)\n", q.r, q.c);
	}
	printf("성공\n");
	return 0;
}