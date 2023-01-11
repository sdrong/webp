#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#define MAX_QUEUE_SIZE 20
#define INF 1000L

typedef int element2;

typedef struct {
	element2 data[MAX_QUEUE_SIZE];
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
		fprintf(stderr, "full");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element2 dequeue(QueueType* q)
{
	if (empty(q))
	{
		fprintf(stderr, "empty");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define SIZE 11

#define MAX_VERTICES 20
int TRUE = 1;
int FALSE = 0;

int visited[MAX_VERTICES];

typedef struct GraphType {
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
	int n;
}GraphType;

void init(GraphType* g)
{
	g->n = 0;
	for (int r = 0; r < MAX_VERTICES; r++)
	{
		for (int c = 0; c < MAX_VERTICES; c++)
		{
			g->adj_mat[r][c] = INF;
		}
	}
}

void insert_vertices(GraphType* g, int v)
{
	if (g->n + 1 > MAX_VERTICES)
	{
		fprintf(stderr, "�ʰ��Դϴ�.\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end, int num)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "��������\n");
		return;
	}
	g->adj_mat[start][end] = num;
	g->adj_mat[end][start] = num;
}

void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			if (g->adj_mat[i][j] == INF)
			{
				printf("INF ");
			}
			else {
				printf("%3d ", g->adj_mat[i][j]);
			}
		}
		printf("\n");
	}
}


void bfs_mat(GraphType* g, int v)
{
	int w;
	QueueType q;
	queue_init(&q);
	visited[v] = TRUE;
	printf("%d�湮 -> ", v);
	enqueue(&q, v);
	while (!empty(&q))
	{
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
		{
			if (g->adj_mat[v][w] != INF && !visited[w])
			{
				visited[w] = TRUE;
				printf("%d�湮 -> ", w);
				enqueue(&q, w);
			}
		}

	}
	srand(time(NULL));
	for (int i = 0; i < g->n; i++)
	{
		if (!visited[i])
		{
			int num = rand() % 100;
			printf("������� ���� ��� \n");
			insert_edge(g, v, i, num);
			bfs_mat(g, i);
		}
	}
}


int visited2[MAX_VERTICES];

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType2 {
	int n;
	GraphNode* list[MAX_VERTICES];
}GraphType2;

void init2(GraphType2* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		g->list[i] = NULL;
	}
}

void insert_vertices2(GraphType2* g, int v)
{
	if (g->n + 1 >= MAX_VERTICES)
	{
		fprintf(stderr, "�ʰ��Դϴ�.\n");
		return;
	}
	g->n++;
}

void insert_edge2(GraphType2* g, int u, int v)
{
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "��������\n");
		return;
	}
	GraphNode* node = malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->list[u];
	g->list[u] = node;
	GraphNode* node2 = malloc(sizeof(GraphNode));
	node2->vertex = u;
	node2->link = g->list[v];
	g->list[v] = node2;
}

void print_adj_mat2(GraphType2* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* node = g->list[i];
		printf("���� %d�� ���� ����Ʈ ", i);
		while (node)
		{
			printf("-> %d ", node->vertex);
			node = node->link;
		}
		printf("\n");
	}
}

void bfs_mat2(GraphType2* g, int v)
{
	GraphNode* w;
	QueueType q;
	queue_init(&q);
	visited2[v] = TRUE;
	printf("%d�湮 -> ", v);
	enqueue(&q, v);
	while (!empty(&q))
	{
		v = dequeue(&q);
		for (w = g->list[v]; w; w = w->link)
		{
			if (!visited2[w->vertex])
			{
				visited2[w->vertex] = TRUE;
				printf("%d�湮 -> ", w->vertex);
				enqueue(&q, w->vertex);
			}
		}
	}
	srand(time(NULL));
	for (int i = 0; i < g->n; i++)
	{
		if (!visited2[i])
		{
			printf("������� ���� ��� \n");
			insert_edge2(g, v, i, rand() % 100);
			bfs_mat(g, i);
		}
	}
}

void visite(int v[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%2d ", v[i]);
	}
	printf("\n");
}

int selected[MAX_VERTICES]; // ���� �� �� ����
int distance[MAX_VERTICES]; // ����� �Ÿ� ����ġ

int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
	{
		if (!selected[i])
		{
			v = i;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;
	}
	return (v);
}

void prime(GraphType* g, int s)
{
	int count = 0;
	int i, u, v;
	printf("%d %d\n", g->n, INF);
	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF)
			return;
		printf("���� %d�߰�\n", u);
		count += distance[u];
		for (v = 0; v < g->n; v++)
			if (g->adj_mat[u][v] != 0)
				if (!selected[v] && g->adj_mat[u][v] < distance[v])
					distance[v] = g->adj_mat[u][v];
		for (int j = 0; j < g->n; j++)
		{
			printf("%3d ", j);
		}
		printf("\n");
		for (int j = 0; j < g->n; j++)
		{
			printf("%3d ", selected[j]);
		}
		printf("\n");
		for (int j = 0; j < g->n; j++)
		{
			if (distance[j] == INF)
			{
				printf("INF ");
			}
			else
				printf("%3d ", distance[j]);
		}
		printf("\n");
	}
	printf("�ּҰ�� ���� %d\n", count);
}

int main(void)
{
	srand(time(NULL));
	GraphType* g = malloc(sizeof(GraphType));
	init(g);
	GraphType2* g2 = malloc(sizeof(GraphType2));
	init2(g2);
	printf("������ ������ �Է��Ͻÿ�");
	int v, trunk;
	scanf("%d", &v);
	printf("������ ������ �Է��Ͻÿ�");
	scanf("%d", &trunk);

	for (int i = 0; i < v; i++)
	{
		insert_vertices(g, i);
		insert_vertices2(g2, i);
	}
	int s, e;
	for (int i = 0; i < trunk; i++)
	{
		s = rand() % v;
		e = rand() % v;
		while (s == e || g->adj_mat[s][e] != INF)
		{
			s = rand() % v;
			e = rand() % v;
		}
		int num = rand() % 100;
		insert_edge(g, s, e, num);
		insert_edge2(g2, s, e);
	}


	bool b = true;
	while (b)
	{
		printf("1.������� ������� �׷���g1\n");
		printf("2.������� ���� ����Ʈg2\n");
		printf("3.���� �˰���g1\n");
		printf("�Է�");
		int u;
		int s;
		scanf("%d", &u);
		switch (u)
		{
		case 1:
			print_adj_mat(g);
			printf("Ž�� ������ ��� �Է��Ͻÿ�:");
			scanf("%d", &s);
			while (s >= g->n)
			{
				printf("�ٽ� �Է��Ͻÿ�:");
				scanf("%d", &s);
			}
			printf("���� �켱 Ž��\n");
			bfs_mat(g, s);
			printf("\n");
			for (int i = 0; i < MAX_VERTICES; i++)
				visited[i] = NULL;
			break;
		case 2:
			print_adj_mat2(g2);
			printf("Ž�� ������ ��� �Է��Ͻÿ�:");
			scanf("%d", &s);
			while (s >= g->n)
			{
				printf("�ٽ� �Է��Ͻÿ�:");
				scanf("%d", &s);
			}
			printf("���� �켱 Ž��\n");
			bfs_mat2(g2, s);
			printf("\n");
			for (int i = 0; i < MAX_VERTICES; i++)
				visited2[i] = NULL;
			break;
		case 3:
			printf("Ž�� ������ ��� �Է��Ͻÿ�:");
			scanf("%d", &s);
			while (s >= g->n)
			{
				printf("�ٽ� �Է��Ͻÿ�:");
				scanf("%d", &s);
			}
			prime(g, s);
			for (u = 0; u < g->n; u++)
			{
				distance[u] = INF;
				selected[u] = FALSE;
			}
			break;
		default:
			b = false;
			break;
		}
	}
	return 0;
}
