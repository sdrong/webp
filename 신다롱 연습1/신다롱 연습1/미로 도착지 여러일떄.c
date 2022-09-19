#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAZE_SIZE 10
#define MAX_STACK_SIZE 100

typedef struct {
	int r;
	int c;
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
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '0', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '1', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '0', '1', '0', '1', '1', '1', '1'},
	{'1', '0', '1', '0', '1', '1', '0', '0', '0', '1'},
	{'1', '0', '1', '0', '1', '1', '0', '1', '1', '1'},
	{'1', '0', '1', '0', '1', '1', '0', '0', '0', '1'},
	{'1', '0', '1', '0', '1', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '1', '1', '0', 'x'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

element here = { 1,0 }, entry = { 1,0 };

const int DIR[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			printf("%c", maze[i][j]);
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
	int x = 0;
	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			if (maze[i][j] == 'x')
				x++;
		}
	}
	printf("찾아야 할 목적지의 개수:%d\n", x);
	int cnt = 0;
	while (1)
	{
		if (maze[here.r][here.c] == 'x')
		{
			cnt++;
			Push(&s2, (element) { -3, -3 });
			printf("%d개 찾음ㅋ\n", cnt);
			maze[here.r][here.c] = '.';
		}
		if (cnt == x)
			break;
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		for (int i = 0; i < 4; i++)
		{
			push_loc(&s, r + DIR[i][0], c + DIR[i][1]);
		}
		if (is_empty(&s))
		{
			printf("핳핳 경로가 없넹\n");
			return 0;
		}
		else
		{
			here = Pop(&s);
			printf("%d %d\n\n", here.r, here. c);
			push_loc(&s2, here.r, here.c);
		}	
	}
	element q;
	while (!is_empty(&s2))
	{
		q = Pop(&s2);
		Push(&s3, q);
	}
	int re = 1;
	while (!is_empty(&s3))
	{
		q = Pop(&s3);
		if (q.r == -3 && q.c == -3)
		{
			printf("%d개 찾았습니다.\n", re);
			re++;
		}
		else
			printf("(%d, %d)\n", q.r, q.c);
	}
	printf("성공입니다.\n");
	return 0;
}