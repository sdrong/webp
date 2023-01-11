#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define INF 100000
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
int visited[MAX_VERTICES] = { 0, };


typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

GraphNode *root;

void graph_init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "그래프: 정점 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void insert_edge2(GraphNode* root, int v)
{
	GraphNode* node;
	node = malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = root;
	root = node;
}

void dfs(GraphType* g, int n)
{
	visited[n] = TRUE;
	GraphNode* node = g->adj_list[n];
	while (node != NULL)
	{
		int u = node->vertex;
		if (!visited[u])
			dfs(g, u);
		node = node->link;
	}
	GraphNode* newnode = malloc(sizeof(GraphNode));
	newnode->vertex = n;
	newnode->link = root;
	root = newnode;
}

void topo_sort(GraphType* g, int n)
{
	for (int i = 0; i < g->n; i++)
	{
		visited[i] = FALSE;
	}
	dfs(g, n);
	for (int i = 0; i < g->n; i++)
	{
		if (!visited[i])
			dfs(g, i);
	}
}

void S1(void)
{
	root = malloc(sizeof(root));
	root = NULL;
	GraphType g;
	graph_init(&g);
	for (int i = 0; i <= 10; i++)
		insert_vertex(&g, i);
	insert_edge(&g, 0, 1);
	insert_edge(&g, 0, 3);
	insert_edge(&g, 1, 2);
	insert_edge(&g, 1, 8);
	insert_edge(&g, 3, 4);
	insert_edge(&g, 3, 5);
	insert_edge(&g, 4, 5);
	insert_edge(&g, 4, 6);
	insert_edge(&g, 4, 10);
	insert_edge(&g, 5, 6);
	insert_edge(&g, 5, 7);
	insert_edge(&g, 6, 9);
	insert_edge(&g, 7, 9);
	int n;
	printf("시작정점 입력:");
	scanf("%d", &n);
	topo_sort(&g, n);
	while (root!= NULL)
	{
		printf("정점 %d ->", root->vertex);
		root = root->link;
	}
}

void S2(void)
{
	root = malloc(sizeof(root));
	root = NULL;
	GraphType g;
	graph_init(&g);
	for (int i = 0; i <= 7; i++)
		insert_vertex(&g, i);
	insert_edge(&g, 0, 1);
	insert_edge(&g, 1, 2);
	insert_edge(&g, 1, 3);
	insert_edge(&g, 1, 4);
	insert_edge(&g, 2, 7);
	insert_edge(&g, 3, 6);
	insert_edge(&g, 4, 5);
	insert_edge(&g, 4, 6);
	insert_edge(&g, 5, 7);
	insert_edge(&g, 6, 7);
	int n;
	printf("시작정점 입력:");
	scanf("%d", &n);
	topo_sort(&g, n);
	while (root != NULL)
	{
		printf("정점 %d ->", root->vertex);
		root = root->link;
	}
}

typedef struct GraphType2{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType2;

int distance[MAX_VERTICES];
int prev[MAX_VERTICES];
int S[MAX_VERTICES];

int nextVertex(GraphType2 *g)
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < g->n; i++)
	{
		if (distance[i] < min && !S[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void print_step(int *step, GraphType2 *g)
{
	*step += 1;
	printf("STEP %d\n", *step);
	printf("distance: ");
	for (int i = 0; i < g->n; i++)
	{
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("prev:     ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", prev[i]);
	printf("\n");
	printf("visited: ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", S[i]);
	printf("\n\n");
}

void shortest_path(GraphType2 *g, int start)
{
	int i, u, w, step = 0;
	for (i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i];
		S[i] = FALSE;
		prev[i] = -1;
		if (distance[i] != INF)
			prev[i] = start;
	}
	S[start] = TRUE;
	distance[start] = 0;
	prev[start] = start;
	u = nextVertex(g);
	prev[u] = start;

	for (int i = 0; i < g->n; i++)
	{
		print_step(&step, g);
		u = nextVertex(g);
		if (prev[u] != -1)
			S[u] = TRUE;
		for (w = 0; w < g->n; w++)
		{
			if (!S[w])
			{
				if (distance[u] + g->weight[u][w] < distance[w])
				{
					distance[w] = distance[u] + g->weight[u][w];
					prev[w] = u;
				}
			}
		}
	}
}

int nextVertex2(GraphType2* g)
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < g->n; i++)
	{
		if (distance[i] < min && !S[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void shortest_path2(GraphType2* g, int start)
{
	int i, u, w, step = 0;
	for (i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i];
		S[i] = FALSE;
		prev[i] = -1;
		if (distance[i] != INF)
			prev[i] = start;
	}
	S[start] = TRUE;
	distance[start] = 0;
	prev[start] = start;
	u = nextVertex2(g);
	prev[u] = start;

	for (int i = 0; i < g->n; i++)
	{
		u = nextVertex2(g);
		if (prev[u] != -1)
			S[u] = TRUE;
		for (w = 0; w < g->n; w++)
		{
			if (!S[w])
			{
				if (distance[u] + g->weight[u][w] < distance[w])
				{
					distance[w] = distance[u] + g->weight[u][w];
					prev[w] = u;
				}
			}
		}
	}
	print_step(&step, g);
}


int main(void)
{
	GraphType2 g = { 8,
		{{0, 10, 7, 4, INF, INF, INF, INF},
		{INF, 0, INF, INF, 8, INF, INF, INF},
		{INF, 2, 0, 2, 8, INF, INF, INF},
		{INF, INF, INF, 0, INF, INF, 8, 20},
		{INF, INF, INF, INF, 0,12 ,INF, INF},
		{INF, INF, INF, INF, INF , 0, INF, 4},
		{INF, INF, 12, INF, INF, 7, 0, INF},
		{INF, INF, INF, INF, INF, INF, 3,0 } }
	};

	GraphType2 g2 = { 8,
		{{0, 8, INF, 11, 9, INF, INF, INF},
		{INF, 0, 10, INF, 8, INF, INF, INF},
		{INF, INF, 0, INF, INF, 2, INF, INF},
		{INF, INF, INF, 0, INF, INF, 8, 8},
		{INF, 6, 1, 3, 0, INF ,INF, INF},
		{INF, INF, INF, INF, INF , 0, INF, 4},
		{INF, INF, INF, INF, 12, 5, 0, INF},
		{INF, INF, INF, INF, INF, INF, 7,0 } }
	};
	bool b = true;
	while (b)
	{
		printf("1.깊이우선탐색 위상정렬 그래프1\n");
		printf("2.깊이우선탐색 위상정렬 그래프2\n");
		printf("3.다익스트라 최단경로G1\n");
		printf("4.다익스트라 최단경로G2\n");
		printf("5.다익스트라 최단경로G1의 모든 쌍\n");
		printf("6.다익스트라 최단경로G2의 모든 쌍\n");
		printf("입력");
		int u;
		int s;
		scanf("%d", &u);
		switch (u)
		{
		case 1:
			S1();
			printf("\n");
			for (int i = 0; i < 11; i++)
				visited[i] = NULL;
			break;
		case 2:
			S2();
			printf("\n");
			for (int i = 0; i < 8; i++)
				visited[i] = NULL;
			break;
		case 3:
			printf("탐색 시작할 노드 입력하시오:");
			scanf("%d", &s);
			shortest_path(&g, s);
			printf("\n");
			for (int i = 0; i < g.n; i++)
			{
				distance[i] = 0;
				prev[i] = 0;
				S[i] = 0;
			}
			break;
		case 4:
			printf("탐색 시작할 노드 입력하시오:");
			scanf("%d", &s);
			shortest_path(&g2, s);
			printf("\n");
			for (int i = 0; i < g2.n; i++)
			{
				distance[i] = 0;
				prev[i] = 0;
				S[i] = 0;
			}
			break;
		case 5:
			for (int j = 0; j < g.n; j++)
			{
				printf("정점 %d 시작일떄\n", j);
				shortest_path2(&g, j);
				printf("\n");
				for (int i = 0; i < g.n; i++)
				{
					distance[i] = 0;
					prev[i] = 0;
					S[i] = 0;
				}
			}
			break;
		case 6:
			for (int j = 0; j < g2.n; j++)
			{
				printf("정점 %d 시작일떄\n", j);
				shortest_path2(&g2, j);
				printf("\n");
				for (int i = 0; i < g2.n; i++)
				{
					distance[i] = 0;
					prev[i] = 0;
					S[i] = 0;
				}
			}
			break;
		default:
			b = false;
			break;
		}
	}
	return 0;
}
