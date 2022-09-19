#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

int visited[MAX_VERTICES];

typedef struct StackType
{
	int top;
	int data[MAX_VERTICES];
}StackType;

void init(StackType* s)
{
	s->top = -1;
}

int full(StackType* s)
{
	return (s->top == MAX_VERTICES-1);
}

int empty(StackType* s)
{
	return (s->top == -1);
}

void push(StackType* s, int x)
{
	if (full(s))
	{
		fprintf(stderr, "수고");
		return;
	}
	s->data[++s->top] = x;
}

int pop(StackType* s)
{
	if (empty(s))
	{
		fprintf(stderr, "진짜 수고");
		return;
	}
	int x = s->data[s->top--];
	return x;
}

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType
{
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		g->adj_list[i] = NULL;
	}
}

void insert_vertex(GraphType* g, int v)
{
	if (g->n + 1 > MAX_VERTICES)
	{
		fprintf(stderr, "노드개수 초과함");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start > g->n || end > g->n)
	{
		fprintf(stderr, "노드가 없습니다");
		return;
	}
	GraphNode* node = malloc(sizeof(GraphNode));
	node->vertex = end;
	node->link = g->adj_list[start];
	g->adj_list[start] = node;
}

void print_adj_list(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트", i);
		while (p != NULL)
		{
			printf("->%d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

void get_degree(GraphType* g, int num)
{
	if (num > g->n)
	{
		fprintf(stderr, "없어");
		return;
	}
	int i = 0;
	GraphNode* node = g->adj_list[num];
	while (node != NULL)
	{
		i++;
		node = node->link;
	}
	printf("%d 의 차수는 %d\n", num, i);
}

void dfs_list(GraphType* g, int v)
{
	GraphNode* w;
	visited[v] = TRUE;
	printf("정점 %d -> ", v);
	for (w = g->adj_list[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs_list(g, w->vertex);
}

void dfs_iterative(GraphType* g, int v)
{
	StackType* s;
	init(s);
	push(s, v);
	while (!empty(s))
	{
		v = pop(s);
		if (!visited[v])
		{
			printf("정점 %d -> ", v);
			for (GraphNode* u = g->adj_list[v]; u; u = u->link)
			{
				if (!visited[u->vertex])
					push(u);
			}
		}
	}
}

int main(void)
{
	GraphType* g;
	g = malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
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
	print_adj_list(g);
	for (int i = 0; i < 4; i++)
		get_degree(g, i);
	dfs_list(g, 2);
	printf("\n");
	
	free(g);
	return 0;
}