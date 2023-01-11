#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n)// 정점위치쪽 다 -1
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
	}
}

int set_find(int curr) //curr 이 소속된 집합을 반환함
{
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1)
		curr = parent[curr];
	return curr;
}

void set_union(int a, int b) // 두개의 원소가 속한 집합을 합침
{
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}

struct Edge {
	int start, end, weight;
};

typedef struct GraphType {
	int n;
	int nvertex;
	struct Edge edges[2 * MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g)
{
	g->n = g->nvertex = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++)
	{
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(GraphType* g)
{
	int edge_accepted = 0; // 현재까지 선택된 간선의 수
	int uset, vset;
	struct Edge e;
	set_init(g->nvertex);
	qsort(g->edges, g->n, sizeof(struct Edge), compare); //가중치 순의로 정렬

	printf("쿠르스칼 최소 신장 트리 알고리즘 \n");
	int i = 0;
	while (edge_accepted < g->nvertex - 1)
	{
		e = g->edges[i];
		uset = set_find(e.start); //뿌리 끝까지 찾아감
		vset = set_find(e.end); // 뿌리 끝까지 찾아감
		if (uset != vset)
		{
			printf("간선 (%d, %d) %d 선택 \n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
			for (int i = 0; i < g->nvertex; i++)
			{
				printf("%2d ", i);
			}
			printf("\n");
			for (int i = 0; i < g->nvertex; i++)
			{
				printf("%2d ", parent[i]);
			}
			printf("\n");
		}
		i++;
	}
}

int main(void)
{
	GraphType* g;
	g = malloc(sizeof(GraphType));
	graph_init(g);

	g->nvertex = 7;
	insert_edge(g, 0, 1, 8);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);

	GraphType* g2;
	g2 = malloc(sizeof(GraphType));
	graph_init(g2);

	g2->nvertex = 7;
	insert_edge(g2, 0, 2, 8);
	insert_edge(g2, 0, 1, 18);
	insert_edge(g2, 0, 3, 2);
	insert_edge(g2, 0, 5, 10);
	insert_edge(g2, 1, 3, 12);
	insert_edge(g2, 1, 4, 4);
	insert_edge(g2, 2, 5, 5);
	insert_edge(g2, 3, 4, 14);
	insert_edge(g2, 3, 5, 3);
	insert_edge(g2, 3, 6, 30);
	insert_edge(g2, 4, 6, 26);
	insert_edge(g2, 5, 6, 16);

	kruskal(g2);
	free(g);
	return 0;
}