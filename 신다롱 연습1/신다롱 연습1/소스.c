#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* list[MAX];
}GraphType;

void init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < MAX; i++)
	{
		g->list[i] = NULL;
	}
}

void insert_vertex(GraphType* g)
{
	if (g->n >= MAX)
	{
		fprintf(stderr, "정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	if (g->n < u || g->n < v)
	{
		fprintf(stderr, "정점의 번호 에러");
		return;
	}
	GraphNode* node = malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->list[u];
	g->list[u] = node;
}

void print(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* p = g->list[i];
		printf("%d의  인접 리스트", i);
		while (p != NULL)
		{
			printf("->%d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

int main(void)
{
	GraphType* g = malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);
	print(g);
	free(g);
	return 0;
}