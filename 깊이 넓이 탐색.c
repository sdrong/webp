#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTiCES 50

#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct QueueType
{
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void queue_init(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화된 상태");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

typedef struct Graph_Node {
	int n;
	int adj_mat[MAX_VERTiCES][MAX_VERTiCES];
}Graph_Node;


int visited[MAX_VERTiCES] = { 0, };

void init(Graph_Node* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTiCES; r++)
	{
		for (c = 0; c < MAX_VERTiCES; c++)
		{
			g->adj_mat[r][c] = 0;
		}
	}
}

void insert_vertex(Graph_Node *g)
{
	if (g->n < MAX_VERTiCES)
		g->n++;
}

void insert_edge(Graph_Node* g, int s, int e)
{
	if (s < 0 || s >= g->n || e < 0 || e >= g->n) {
		fprintf(stderr, "오류");
		return;
	}
	g->adj_mat[s][e] = 1;
	g->adj_mat[e][s] = 1;
}

void dfs(Graph_Node* g, int n)
{
	visited[n] = 1;
	printf("[%d]방문-> ", n);
	for (int i = 0; i < g->n; i++)
	{
		if (g->adj_mat[n][i] != 0 && !visited[i])
			dfs(g, i);
	}
}

void bfs(Graph_Node* g, int n)
{
	QueueType q;
	queue_init(&q);
	visited[n] = 1;
	printf("[%d]방문-> ", n);
	enqueue(&q, n);
	while (!is_empty(&q))
	{
		n = dequeue(&q);
		for (int i = 0; i < g->n; i++)
		{
			if (g->adj_mat[n][i] != 0 && !visited[i])
			{
				visited[i] = 1;
				printf("%d방문->", i);
				enqueue(&q, i);
			}
		}
	}
}


int visited2[MAX_VERTiCES];

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType2 {
	int n;
	GraphNode* list[MAX_VERTiCES];
}GraphType2;

void init2(GraphType2* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTiCES; i++)
	{
		g->list[i] = NULL;
	}
}

void insert_vertices2(GraphType2* g, int v)
{
	if (g->n + 1 >= MAX_VERTiCES)
	{
		fprintf(stderr, "초과입니다.\n");
		return;
	}
	g->n++;
}

void insert_edge2(GraphType2* g, int u, int v)
{
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "정점오류\n");
		return;
	}
	GraphNode* node = malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->list[u];
	g->list[u] = node;
}

void print_adj_mat2(GraphType2* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* node = g->list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (node)
		{
			printf("-> %d ", node->vertex);
			node = node->link;
		}
		printf("\n");
	}
}

void dfs_mat2(GraphType2* g, int v)
{
	GraphNode* w;
	visited2[v] = TRUE;
	printf("정점%d -> ", v);
	for (w = g->list[v]; w; w = w->link)
	{
		if (w->vertex && !visited2[w->vertex])
			dfs_mat2(g, w->vertex);
	}
}

void bfs_mat2(GraphType2* g, int n)
{
	QueueType q;
	queue_init(&q);
	visited[n] = 1;
	printf("[%d]방문-> ", n);
	enqueue(&q, n);
	while (!is_empty(&q))
	{
		n = dequeue(&q);
		for (GraphNode* w = g->list[n]; w; w = w->link)
		{
			if (!visited[w->vertex])
			{
				visited[w->vertex] = 1;
				printf("%d방문->", w->vertex);
				enqueue(&q, w->vertex);
			}
		}
	}
}


int main(void)
{
	Graph_Node* g = malloc(sizeof(Graph_Node));
	init(g);
	for (int i = 0; i < 7; i++)
	{
		insert_vertex(g);
	}
	insert_edge(g, 0, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 1, 2);
	insert_edge(g, 3, 5);
	insert_edge(g, 4, 5);
	insert_edge(g, 5, 6);

	GraphType2* g2 = malloc(sizeof(GraphType2));
	init2(g2);
	for (int i = 0; i < 10; i++)
	{
		insert_vertices2(g2, i);
	}
	insert_edge2(g2, 1, 4);
	insert_edge2(g2, 4, 3);
	insert_edge2(g2, 2, 6);
	insert_edge2(g2, 6, 5);
	insert_edge2(g2, 7, 9);
	insert_edge2(g2, 9, 8);
	insert_edge2(g2, 8, 0);
	insert_edge2(g2, 7, 8);

	GraphType2* g3 = malloc(sizeof(GraphType2));
	init2(g3);
	for (int i = 0; i < 7; i++)
	{
		insert_vertices2(g3, i);
	}
	insert_edge2(g3, 0, 2);
	insert_edge2(g3, 0, 2);
	insert_edge2(g3, 0, 1);
	insert_edge2(g3, 1, 5);
	insert_edge2(g3, 1, 4);
	insert_edge2(g3, 1, 0);
	insert_edge2(g3, 2, 5);
	insert_edge2(g3, 2, 1);
	insert_edge2(g3, 3, 5);
	insert_edge2(g3, 3, 0);
	insert_edge2(g3, 4, 6);
	insert_edge2(g3, 4, 1);
	insert_edge2(g3, 5, 6);
	insert_edge2(g3, 5, 3);
	insert_edge2(g3, 5, 2);
	insert_edge2(g3, 5, 1);
	insert_edge2(g3, 6, 5);
	insert_edge2(g3, 6, 4);
	
	GraphType2* g4 = malloc(sizeof(GraphType2));
	init2(g4);
	for (int i = 0; i < 10; i++)
	{
		insert_vertices2(g4, i);
	}
	insert_edge2(g4, 0, 1);
	insert_edge2(g4, 1, 3);
	insert_edge2(g4, 1, 2);
	insert_edge2(g4, 1, 0);
	insert_edge2(g4, 2, 4);
	insert_edge2(g4, 2, 1);
	insert_edge2(g4, 3, 5);
	insert_edge2(g4, 3, 4);
	insert_edge2(g4, 3, 1);
	insert_edge2(g4, 4, 3);
	insert_edge2(g4, 4, 2);
	insert_edge2(g4, 5, 7);
	insert_edge2(g4, 5, 6);
	insert_edge2(g4, 5, 3);
	insert_edge2(g4, 6, 7);
	insert_edge2(g4, 6, 5);
	insert_edge2(g4, 7, 9);
	insert_edge2(g4, 7, 8);
	insert_edge2(g4, 7, 6);
	insert_edge2(g4, 7, 5);
	insert_edge2(g4, 8, 7);
	insert_edge2(g4, 9, 7);
	dfs_mat2(g4, 6);

	return 0;
}