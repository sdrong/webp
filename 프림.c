#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES]; // 연결 된 길 유무
int distance[MAX_VERTICES]; // 연결될 거리 가중치

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
	int sum = 0;
	int i, u, v;
	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (int i = 0; i < g->n; i++)
	{
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF)
			return;
		printf("정점%c추가\n", u+'a');
		sum += distance[u];
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
	printf("\n%d\n", sum);
}

int main(void)
{
	GraphType g = { 6,
		{{0, 3, INF, 2, 4, INF},
		{3, 0, 1, 4, INF, 2},
		{INF, 1, 0, INF, INF, 1},
		{2, 4, INF, 0, 5, 7},
		{4, INF, INF, 5, 0, 9},
		{INF, 2, 1, 7, 9, 0}
	} };
	prime(&g, 2);
	return 0;
}