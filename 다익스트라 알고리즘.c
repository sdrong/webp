#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType* g)
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++)
	{
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("found: ");
	for (int i = 0; i < g->n; i++)
		printf("%d ", found[i]);
	printf("\n\n");
}

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;
	distance[start] = 0;
	for (i = 0; i < g->n; i++)
	{
		print_status(g);
		w = choose(distance, g->n, found);
		found[w] = TRUE;
		for (int j = 0; j < g->n; j++)
		{
			if (!found[j])
			{
				if (distance[j] > distance[w] + g->weight[w][j]) {
					distance[j] = distance[w] + g->weight[w][j];
				}
			}
		}
	}
}

int main(void)
{
	GraphType g = { 5,
		{{0, 10, INF, 5, INF},
		{INF, 0, 1, 2, INF},
		{INF, INF, 0, INF, 4},
		{INF, 3, 9, 0, 2},
		{7, INF, 6, INF, 0}}
	};

	GraphType g2 = { 6,
		{{0, 50, 45, 10, INF, INF},
		{INF, 0, 10, 15, INF, INF},
		{INF, INF, INF, INF, 30, INF},
		{20, INF, INF, 0, 15, INF},
		{INF, 20, 35, INF, 0, INF},
		{INF, INF, INF, INF, 3, 0}}
	};
	shortest_path(&g2, 0);
	return 0;
}