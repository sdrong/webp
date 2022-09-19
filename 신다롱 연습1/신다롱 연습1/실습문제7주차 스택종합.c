#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 10
typedef struct element {
	int r;
	int c;
}element;

typedef struct stacktype {
	element data[MAX_STACK_SIZE];
	int top;
}Stack_Type;

void init(Stack_Type* s)
{
	s->top = -1;
}

int is_empty(Stack_Type* s)
{
	return (s->top == -1);
}

int is_full(Stack_Type* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(Stack_Type* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "포화에러입니다.\n");
		exit(1);
	}
	s->data[++(s->top)] = item;
}

element pop(Stack_Type* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공복에러입니다.\n");
		exit(1);
	}
	return s->data[s->top--];
}

element peek(Stack_Type* s)
{
	if (is_full(s))
	{
		fprintf(stderr, "공복에러입니다.\n");
		exit(1);
	}
	return s->data[s->top];
}
element here = { 1,0 }, entry = { 1.0 };
const int DIR[4][2] = { {0,1},{1,0},{0,-1},{-1, 0} };
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

void print_maze(char maze[MAZE_SIZE][MAZE_SIZE])
{
	for (int r = 0; r < MAZE_SIZE; r++)
	{
		for (int c = 0; c < MAZE_SIZE; c++)
		{
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
	printf("(%d %d)\n", here.r, here.c);
	printf("\n");
}

element load(Stack_Type* s, int r, int c)
{
	if (r < 0 || c < 0)
		return;
	if (maze[r][c] != '1' && maze[r][c] != '.')
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}
int push_loc(Stack_Type* s, int r, int c)
{
	if (r < 0 || c < 0 || maze[r][c] == '.' || maze[r][c] == '1')
		return 0;
	push(s, (element) { r, c });
	return 1;
}
int is_beside(element s, element s2)
{
	for (int i = 0; i < 4; i++)
	{
		if ((s.r + DIR[i][0]) == s2.r && (s.c + DIR[i][1]) == s2.c)
		{
			return 1;
		}
	}
	return 0;
}
void S1(void)
{
	int r;
	int c;
	Stack_Type s;
	init(&s);
	Stack_Type s2;
	init(&s2);
	here = entry;
	while (maze[here.r][here.c] != 'x')
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		print_maze(maze);
		int brench = 0;
		for (int i = 0; i < 4; i++)
		{
			if (push_loc(&s, r + DIR[i][0], c + DIR[i][1]))
				brench++;
		}
		if (brench == 0)
		{
			while (!is_beside(peek(&s), peek(&s2)))
			{
				element tmp = pop(&s2);
				maze[tmp.r][tmp.c] = '0';
			}
		}
		if (is_empty(&s))
		{
			printf("실패\n");
			return 0;
		}
		else
		{
			here = pop(&s);
			push(&s2, here);
		}
	}
	Stack_Type s3;
	init(&s3);
	while (!is_empty(&s2))
	{
		push(&s3, pop(&s2));
	}

	printf("\n결과 출력\n\n");
	print_maze(maze);

	while (!is_empty(&s3))
	{
		element tmp = pop(&s3);
		printf("%d %d\n", tmp.r, tmp.c);
	}
	printf("성공입니다.\n");
}

char maze2[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1', '1', '1', 'x', '1'},
	{'e', '0', '1', '0', '0', '0', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '0', '0', '0', '1'},
	{'1', '0', '1', '0', '1', '0', '1', '1', '1', '1'},
	{'1', '0', '1', '0', '1', '1', '0', '0', '0', 'x'},
	{'1', '0', '1', '0', '1', '1', '0', '1', '1', '1'},
	{'1', '0', '1', '0', '1', '1', '0', '0', '0', '1'},
	{'1', '0', '1', '0', '1', '0', '0', '1', '0', '1'},
	{'0', '0', '1', '0', '0', '0', '1', '1', '0', 'x'},
	{'x', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

void print_maze2(char maze2[MAZE_SIZE][MAZE_SIZE])
{
	for (int r = 0; r < MAZE_SIZE; r++)
	{
		for (int c = 0; c < MAZE_SIZE; c++)
		{
			printf("%c", maze2[r][c]);
		}
		printf("\n");
	}
	printf("(%d %d)\n", here.r, here.c);
	printf("\n");
}

element load2(Stack_Type* s, int r, int c)
{
	if (r < 0 || c < 0 || c >= MAZE_SIZE || r >= MAZE_SIZE)
		return;
	if (maze2[r][c] != '1' && maze2[r][c] != '.')
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}
int push_loc2(Stack_Type* s, int r, int c)
{
	if (r < 0 || c < 0 || maze2[r][c] == '.' || maze2[r][c] == '1')
		return 0;
	push(s, (element) { r, c });
	return 1;
}
int is_beside2(element s, element s2)
{
	for (int i = 0; i < 4; i++)
	{
		if ((s.r + DIR[i][0]) == s2.r && (s.c + DIR[i][1]) == s2.c)
		{
			return 1;
		}
	}
	return 0;
}
void S2(void)
{
	int r;
	int c;
	Stack_Type s;
	init(&s);
	Stack_Type s2;
	init(&s2);
	int x = 0;
	for (int i = 0; i < MAZE_SIZE; i++)
	{
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			if (maze2[i][j] == 'x')
				x++;
		}
	}
	printf("찾아야 할 목적지의 개수:%d\n", x);
	int cnt = 0;
	for (int i = 0; i < x; i++)
	{
		here = entry;
		while (maze2[here.r][here.c] != 'x')
		{
			r = here.r;
			c = here.c;
			maze2[r][c] = '.';
			print_maze2(maze2);
			int brench = 0;
			for (int i = 0; i < 4; i++)
			{
				if (push_loc2(&s, r + DIR[i][0], c + DIR[i][1]))
					brench++;
			}
			if (brench == 0)
			{
				while (!is_beside2(peek(&s), peek(&s2)))
				{
					element tmp = pop(&s2);
					maze2[tmp.r][tmp.c] = '0';
				}
			}
			if (is_empty(&s))
			{
				printf("실패\n");
				return 0;
			}
			else
			{
				here = pop(&s);
				push(&s2, here);
			}
		}
		Stack_Type s3;
		init(&s3);
		while (!is_empty(&s2))
		{
			push(&s3, pop(&s2));
		}
		while (!is_empty(&s3))
		{
			element tmp = pop(&s3);
			if (maze2[tmp.r][tmp.c] == 'x')
				maze2[tmp.r][tmp.c] = '.';
			else
				maze2[tmp.r][tmp.c] = '0';
			if (is_empty(&s3))
				printf("(%d %d)\n", tmp.r, tmp.c);
			else
				printf("(%d %d) -> ", tmp.r, tmp.c);
		}
		printf("결과 출력\n");
		print_maze2(maze2);
		printf("%d번쨰 성공입니다.\n", i + 1);
		while (!is_empty(&s))
		{
			element tmp = pop(&s);
		}
	}
}

int main(void)
{
	int n;
	while (1)
	{
		printf("1.미로\n");
		printf("2.다중미로\n");
		printf("다른거 누르면 종료\n");
		printf("입력:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			S1();
			break;
		case 2:
			S2();
			break;
		default:
			printf("종료\n");
			return 0;
			break;
		}
	}
	printf("종료\n");
	return 0;
}