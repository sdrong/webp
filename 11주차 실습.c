#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#define KEY_SIZE 11
#define TABLE_SIZE 11
#define MAX_QUEUE_SIZE 10
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


typedef struct
{
	int key;
}element;

struct list
{
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE];
element hash_table2[TABLE_SIZE];

int hash_function(int key)
{
	return key % TABLE_SIZE;
}

#define empty(item) (item == NULL)
#define equal(item1, item2) (item1.key == item2.key))

void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {
		if (node->item.key == item.key)
		{
			fprintf(stderr, "이미 탐색키가 저장되어 있음\n");
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[hash_value] = ptr;
}

void hash_lp_add(element item, element ht[])//선형조사법
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);

	while (!empty(ht[i].key)) {
		if (item.key == ht[i].key) {
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value)
		{
			fprintf(stderr, "테이블이 가득찼습니다.\n");
			exit(1);
		}
	}
	ht[i] = item;
}

void hash_qp_add(element item, element ht[])//이차조사법
{
	int i, hash_value, inc = 1;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i].key))
	{
		if (item.key == ht[i].key)
		{
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);
		}
		i = (hash_value + inc * inc) % TABLE_SIZE;
		inc = inc + 1;
		if (i == hash_value) {
			fprintf(stderr, "테이블에 가득찼습니다.\n");
			exit(1);
		}
	}
	ht[i] = item;
}

void hash_dh_add(element item, element ht[])//
{
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = 1;
	while (!empty(ht[i].key)) {
		if (item.key == ht[i].key) {
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);
		}
		i = (item.key + inc * (7 - (item.key % 7))) % TABLE_SIZE;
		inc += 1;
		if (i == hash_value)
		{
			fprintf(stderr, "테이블이 가득참\n");
			exit(1);
		}
	}
	ht[i] = item;
}

void hash_chain_print(struct list* ht[])
{
	struct list* node;
	int i;
	printf("\n======================================\n");
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("%d->", i);
		for (node = ht[i]; node; node = node->link) {
			printf("%d->", node->item.key);
		}
		printf("\n");
	}
	printf("\n======================================\n");
}

void hash_print(element ht[])
{
	int i;
	printf("\n======================================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d] %d\n", i, ht[i].key);
	printf("\n======================================\n");
}

void null_hash(element ht[])
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		ht[i].key = NULL;
	}
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
			g->adj_mat[r][c] = 0;
		}
	}
}

void insert_vertices(GraphType* g, int v)
{
	if (g->n + 1 > MAX_VERTICES)
	{
		fprintf(stderr, "초과입니다.\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end)
{
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "정점오류\n");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void print_adj_mat(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		for (int j = 0; j < g->n; j++)
		{
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

void dfs_mat(GraphType* g, int v)
{
	visited[v] = TRUE;
	printf("정점%d -> ", v);
	for (int i = 0; i < g->n; i++)
	{
		if (g->adj_mat[v][i] && !visited[i])
			dfs_mat(g, i);
	}
}

void bfs_mat(GraphType* g, int v)
{
	int w;
	QueueType q;
	queue_init(&q);
	visited[v] = TRUE;
	printf("%d방문 -> ", v);
	enqueue(&q, v);
	while (!empty(&q))
	{
		v = dequeue(&q);
		for (w = 0; w < g->n; w++)
		{
			if (g->adj_mat[v][w] && !visited[w])
			{
				visited[w] = TRUE;
				printf("%d방문 -> ", w);
				enqueue(&q, w);
			}
		}
	}
	for (int i = 0; i < g->n; i++)
	{
		if (!visited[i])
		{
			printf("연결되지 않은 노드 \n");
			bfs_mat(g, i);
		}
	}
}


void No_connect_check(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		TRUE++;
		if (!visited[i])
		{
			printf("\n");
			printf("방문하지 않은 노드 \n");
			dfs_mat(g, i);
		}
	}
	TRUE = 1;
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

void bfs_mat2(GraphType2* g, int v)
{
	GraphNode* w;
	QueueType q;
	queue_init(&q);
	visited[v] = TRUE;
	printf("%d방문 -> ", v);
	enqueue(&q, v);
	while (!empty(&q))
	{
		v = dequeue(&q);
		for (w = g->list[v]; w; w = w->link)
		{
			if (!visited2[w->vertex])
			{
				visited2[w->vertex] = TRUE;
				printf("%d방문 -> ", w->vertex);
				enqueue(&q, w->vertex);
			}
		}
	}
	for (int i = 0; i < g->n; i++)
	{
		if (!visited[i])
		{
			printf("연결되지 않은 노드 \n");
			bfs_mat(g, i);
		}
	}
}

void No_connect_check2(GraphType2* g)
{
	for (int i = 0; i < g->n; i++)
	{
		if (!visited2[i])
		{
			TRUE++;
			printf("\n");
			printf("방문하지 않은 노드: ");
			dfs_mat2(g, i);
		}
	}
	TRUE = 1;
}


void insert_edge3(GraphType2* g, int u, int v)
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

int main(void)
{
	int num[SIZE] = { 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5 };
	element e;
	GraphType* g = malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 10; i++)
	{
		insert_vertices(g, i);
	}
	insert_edge(g, 0, 8);
	insert_edge(g, 9, 8);
	insert_edge(g, 9, 7);
	insert_edge(g, 3, 8);
	insert_edge(g, 4, 3);
	insert_edge(g, 1, 4);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 6);
	insert_edge(g, 6, 5);
	insert_edge(g, 5, 8);
	insert_edge(g, 3, 6);
	insert_edge(g, 1, 6);

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
	for (int i = 0; i < 10; i++)
	{
		insert_vertices2(g3, i);
	}
	insert_edge3(g3, 0, 3);
	insert_edge3(g3, 0, 1);
	insert_edge3(g3, 1, 6);
	insert_edge3(g3, 2, 0);
	insert_edge3(g3, 4, 0);
	insert_edge3(g3, 4, 7);
	insert_edge3(g3, 5, 0);
	insert_edge3(g3, 6, 7);
	insert_edge3(g3, 7, 8);
	insert_edge3(g3, 8, 9);
	insert_edge3(g3, 9, 5);
	insert_edge3(g3, 9, 6);
	bool b = true;
	while (b)
	{
		printf("1.선형조사법\n");
		printf("2.이차조사법\n");
		printf("3.더블해싱법\n");
		printf("4.체이닝 방법\n");
		printf("5.방향없는 인접행렬 그래프g1\n");
		printf("6.방향없는 연결 되지 않은 인접 리스트g2\n");
		printf("7.방향있는 인접리스트 g3\n");
		printf("입력");
		int u;
		int s;
		scanf("%d", &u);
		switch (u)
		{
		case 1:
			for (int i = 0; i < SIZE; i++)
			{
				e.key = num[i];
				hash_lp_add(e, hash_table2);
			}
			hash_print(hash_table2);
			null_hash(hash_table2);
			break;
		case 2:
			for (int i = 0; i < SIZE; i++)
			{
				e.key = num[i];
				hash_qp_add(e, hash_table2);
			}
			hash_print(hash_table2);
			null_hash(hash_table2);
			break;
		case 3:
			for (int i = 0; i < SIZE; i++)
			{
				e.key = num[i];
				hash_dh_add(e, hash_table2);
			}
			hash_print(hash_table2);
			null_hash(hash_table2);
			break;
		case 4:
			for (int i = 0; i < SIZE; i++)
			{
				e.key = num[i];
				hash_chain_add(e, hash_table);
			}
			hash_chain_print(hash_table);
			break;
		case 5:
			print_adj_mat(g);
			printf("탐색 시작할 노드 입력하시오:");
			scanf("%d", &s);
			printf("깊이 우선 탐색\n");
			dfs_mat(g, s);
			No_connect_check(g);
			printf("\n");
			printf("visited 그룹\n");
			visite(visited, g->n);
			break;
		case 6:
			print_adj_mat2(g2);
			printf("탐색 시작할 노드 입력하시오:");
			scanf("%d", &s);
			printf("깊이 우선 탐색\n");
			dfs_mat2(g2, s);
			No_connect_check2(g2);
			printf("\n");
			printf("visited 그룹\n");
			visite(visited2, g2->n);
			for (int i = 0; i < MAX_VERTICES; i++)
				visited2[i] = NULL;
			printf("넓이 우선 탐색\n");
			bfs_mat2(g2, s);
			printf("\n");
			for (int i = 0; i < MAX_VERTICES; i++)
				visited2[i] = NULL;
			break;
		case 7:
			print_adj_mat2(g3);
			printf("탐색 시작할 노드 입력하시오:");
			scanf("%d", &s);
			printf("깊이 우선 탐색\n");
			dfs_mat2(g3, s);
			No_connect_check2(g3);
			printf("\n");
			printf("visited 그룹\n");
			visite(visited2, g3->n);
			for (int i = 0; i < MAX_VERTICES; i++)
				visited2[i] = NULL;
			printf("넓이 우선 탐색\n");
			bfs_mat2(g3, s);
			for (int i = 0; i < MAX_VERTICES; i++)
				visited2[i] = NULL;
			break;
		default:
			b = false;
			break;
		}
	}
	return 0;
}
