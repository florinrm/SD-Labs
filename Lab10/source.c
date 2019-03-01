#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct graf {
	int n;
	int **mat;
	} graf;

graf *init (int n)
{
	graf * graph = (graf *)malloc(sizeof(graf));
	graph->n = n;
	graph->mat = (int **)malloc(n * sizeof(int *));
	int i, j;
	for (i = 0; i < n; i++)
		graph->mat[i] = (int *)calloc(sizeof(int), n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			graph->mat[i][j] = INT_MAX;
	}
	for (i = 0; i < n; i++)
		graph->mat[i][i] = 0;
	return graph;
}

void add_edge (graf *g, int i, int j, int cost)
{
	g->mat[i][j] = cost;
}

void del_edge (graf *g, int i, int j)
{
	g->mat[i][j] = 0;
}

int check_edge (graf *graph, int i, int j)
{
	if ((graph->mat[i][j] != INT_MAX) && (graph->mat[i][j] != 0))
		return 1;
	return 0;
}

void print_graph(graf *g)
{
	int i, j, n = g->n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", g->mat[i][j]);
		printf("\n");
	}
}

void print_matrix (int **a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void Floyd_Warshall (graf *g)
{
	int n = g->n;
	int i, j, k;
	int **dist = (int **) malloc (n * sizeof(int *));
	for (i = 0; i < n; i++)
		dist[i] = (int *) malloc (n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			dist[i][j] = g->mat[i][j];
	}
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[i][k] != INT_MAX) && (dist[k][j] != INT_MAX))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	print_matrix(dist, n);
	for (i = 0; i < n; i++)
		free(dist[i]);
	free(dist);
}

int minimum_distance (int *dist, int *visited, int n)
{
	int min = INT_MAX, position;
	int i;
	for (i = 0; i < n; i++)
	{
		if (visited[i] == 0 && dist[i] <= min)
		{
			min = dist[i];
			position = i;
		}
	}
	return position;
}

void Dijkstra (graf *graph, int src)
{
	int n = graph->n;
	int *visited = (int *) malloc (n * sizeof(int));
	int *dist = (int *) malloc (n * sizeof(int));
	int *prev = (int *) malloc (n * sizeof(int));
	int i;
	for (i = 0; i < n; i++)
	{
		visited[i] = 0;
		prev[src] = -1;
		dist[i] = graph->mat[src][i];
	}
	dist[src] = 0;
	visited[src] = 1;
	for (i = 0; i < n-1; i++)
	{
		int u = minimum_distance(dist, visited, n);
		visited[u] = 1;
		int v;
		for (v = 0; v < n; v++)
		{
			if ((visited[v] == 0) && (dist[u] != INT_MAX) && (dist[u] + graph->mat[u][v] < dist[v]) && (check_edge(graph, u, v)))
			{
				dist[v] = dist[u] + graph->mat[u][v];
				prev[v] = u;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", dist[i]);
	printf("\n");
	free(visited);
	free(dist);
	free(prev);
}

int main ()
{
	graf *graph = init(4);
	add_edge(graph, 1, 0, 4);
	add_edge(graph, 0, 2, -2);
	add_edge(graph, 2, 3, 2);
	add_edge(graph, 3, 1, -1);
	add_edge(graph, 1, 2, 3);
	print_graph(graph);
	printf("kek\n");
	Floyd_Warshall(graph);
	printf("kek\n");
	Dijkstra(graph, 1);
	//Dijkstra(graph, 1);
	//Dijkstra(graph, 2);
	//Dijkstra(graph, 3);
	int i;
	for (i = 0; i < 4; i++)
		free(graph->mat[i]);
	free(graph->mat);
	free(graph);
	return 0;
}
