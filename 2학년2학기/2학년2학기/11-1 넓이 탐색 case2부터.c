#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void queue_init(QueueType* q)
{
	q->front = q->rear = 0;
}

int full(QueueType* q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int empty(QueueType* q)
{
	return q->front == q->rear;
}

void enqueue(QueueType* q, int item)
{
	if (full(q))
	{
		fprintf(stderr, "꽉찼네염");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (empty(q))
	{
		fprintf(stderr, "여백의 미");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// g1
int visited[MAX_VERTICES];

typedef struct GraphType1 {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType1;

void init1(GraphType1* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertex1(GraphType1* g, int v)
{
	if (g->n > MAX_VERTICES)
	{
		fprintf(stderr, "정점 개수 초과\n");
		return;
	}
	g->n++;
}

void insert_edge1(GraphType1* g, int start, int end)
{
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void print1(GraphType1* g)
{
	for (int r = 0; r < g->n; r++)
	{
		for (int c = 0; c < g->n; c++)
		{
			printf("%d ", g->adj_mat[r][c]);
		}
		printf("\n");
	}
}

void dfs_mat1(GraphType1* g1, int v)
{
	int w;
	visited[v] = TRUE;
	printf("정점 %d -> ", v);
	for (w = 0; w < g1->n; w++)
		if (g1->adj_mat[v][w] && !visited[w])
			dfs_mat1(g1, w);
	printf("\n");
}

void bfs_mat1(GraphType1* g1, int v)
{
	QueueType q;
	queue_init(&q);
	visited[v] = 1;
	printf("%d방문 -> ", v);
	enqueue(&q, v);
	while (!empty(&q))
	{
		int u = dequeue(&q);
		for (int i = 0; i < g1->n; i++)
		{
			if (g1->adj_mat[u][i] && !visited[i])
			{
				visited[i] = 1;
				printf("%d방문 -> ", i);
				enqueue(&q, i);
			}
		}
	}
	printf("\n");
}

//g2

int visited2[MAX_VERTICES];

typedef struct GraphNode2
{
	int vertex;
	struct GraphNode2* link;
}GraphNode2;

typedef struct GraphType2
{
	int n;
	GraphNode2* adj_list[MAX_VERTICES];
}GraphType2;

void init2(GraphType2* g2)
{
	g2->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
		g2->adj_list[i] = NULL;
}

void insert_vertex2(GraphType2* g2)
{
	if (g2->n >= MAX_VERTICES)
	{
		fprintf(stderr, "정점개수 초과");
		return;
	}
	g2->n++;
}

void insert_edge2(GraphType2 *g2, int u, int v)
{
	GraphNode2* node = malloc(sizeof(GraphNode2));
	if (u >= g2->n || v >= g2->n)
	{
		fprintf(stderr, "정점 번호 오류");
		return;
	}
	node->vertex = v;
	node->link = g2->adj_list[u];
	g2->adj_list[u] = node;

	GraphNode2* node2 = malloc(sizeof(GraphNode2));
	node2->vertex = u;
	node2->link = g2->adj_list[v];
	g2->adj_list[v] = node2;
}

void print2(GraphType2* g2)
{
	for (int i = 0; i <  g2->n; i++)
	{
		GraphNode2* node = g2->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (node)
		{
			printf("-> %d ", node->vertex);
			node = node->link;
		}
		printf("\n");
	}
}

void dfs_list2(GraphType2* g2, int v)
{
	GraphNode2* w;
	visited2[v] = TRUE;
	printf("정점 %d -> ", v);
	for (w = g2->adj_list[v]; w; w = w->link)
		if (!visited2[w->vertex])
			dfs_list2(g2, w->vertex);
	for (int i = 0; i < g2->n; i++)
	{
		if (!visited2[i])
		{
			printf("\n연결되있지 않음 다음 연결된 노드\n");
			dfs_list2(g2, i);
		}
	}
}  

void bfs_list2(GraphType2* g2, int v)
{
	GraphNode2* w;
	visited2[v] = 1;
	QueueType q;
	queue_init(&q);
	enqueue(&q, v);
	while (!empty(&q));
	{
		v = dequeue(&q);
		printf("정점 %d -> ", v);
		for (w = g2->adj_list[v]; w; w = w->link)
		{
			if (visited2[w->vertex] != 0)
			{
				visited2[w->vertex] = 1;
				enqueue(&q, w->vertex);
			}
		}
	}
	printf("끝\n");
}

//g3

int visited3[MAX_VERTICES];

void insert_edge3(GraphType2* g3, int u, int v)
{
	GraphNode2* node = malloc(sizeof(GraphNode2));
	if (u >= g3->n || v >= g3->n)
	{
		fprintf(stderr, "정점번호 오류");
		return;
	}

	node->vertex = v;
	node->link = g3->adj_list[u];
	g3->adj_list[u] = node;
}

void dfs_list3(GraphType2* g3, int v)
{
	GraphNode2* w;
	visited3[v] = TRUE;
	printf("정점 %d -> ", v);
	for (w = g3->adj_list[v]; w; w = w->link)
		if (!visited3[w->vertex])
			dfs_list3(g3, w->vertex);
	for (int i = 0; i < g3->n; i++)
	{
		if (!visited3[i])
		{
			printf("\n연결되있지 않음 다음 연결된 노드\n");
			dfs_list3(g3, i);
		}
	}
}

int main(void)
{
	GraphType1* g1 = malloc(sizeof(GraphType1));
	init1(g1);
	for (int i = 0; i < 4; i++)
		insert_vertex1(g1, i);
	insert_edge1(g1, 0, 1);
	insert_edge1(g1, 0, 2);
	insert_edge1(g1, 0, 3);
	insert_edge1(g1, 1, 2);
	insert_edge1(g1, 2, 3);
	print1(g1);
	dfs_mat1(g1, 0);
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		visited[i] = 0;
	}
	printf("넓이 우선\n");
	bfs_mat1(g1, 0);
	GraphType2* g2 = malloc(sizeof(GraphType2));
	init2(g2);
	for (int i = 0; i < 4; i++)
		insert_vertex2(g2, i);
	insert_edge2(g2, 0, 1);
	insert_edge2(g2, 0, 2);
	insert_edge2(g2, 0, 3);
	insert_edge2(g2, 1, 2);
	insert_edge2(g2, 2, 3);
	print2(g2);
	dfs_list2(g2, 0);
	printf("\n");
	for (int i = 0; i < MAX_VERTICES; i++)
		visited2[i] = 0;
	printf("넓이 우선\n");
	bfs_list2(g2, 0);
	GraphType2* g3 = malloc(sizeof(GraphType2));
	init2(g3);
	for (int i = 0; i < 4; i++)
		insert_vertex2(g3, i);
	insert_edge3(g3, 0, 1);
	insert_edge3(g3, 0, 2);
	insert_edge3(g3, 0, 3);
	insert_edge3(g3, 1, 2);
	insert_edge3(g3, 2, 3);
	print2(g3);
	dfs_list3(g3, 0);
	return 0;
}