#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct GraphType {
	int n;
	int list[MAX][MAX];
}GraphType;

int tmp[MAX];

void init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			g->list[i][j] = 0;
}

void insert_vertex(GraphType* g, int i)
{
	if (g->n >= MAX)
	{
		fprintf(stderr, "노드 개수 오류");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start > g->n || end > g->n)
	{
		fprintf(stderr, "노드의 번호 에러");
		return;
	}
	g->list[start][end] = 1;
	g->list[end][start] = 1;
}

void print(GraphType* g, int o)
{
	tmp[o] = TRUE;
	printf("%d노드->", o);
	for (int i = 0; i < g->n; i++)
	{
		if (g->list[o][i] && !tmp[i])
			print(g, i);
	}
}


int main(void)
{
	GraphType* g = malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	printf("깊이 우선 탐색\n");
	print(g, 0);
	printf("\n");
	free(g);
	return 0;
}