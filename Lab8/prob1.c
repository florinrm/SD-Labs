#include <stdio.h>
#include <stdlib.h>

typedef struct graf {
	int n;
	int **mat;
	} graf;

graf *init (int n)
{
	graf * graph = (graf *)malloc(sizeof(graf));
	graph->n = n;
	graph->mat = (int **)malloc(n * sizeof(int *));
	int i;
	for (i = 0; i < n; i++)
		graph->mat[i] = (int *)calloc(n, sizeof(int));
	return graph;
}

void add_edge (graf *g, int i, int j)
{
	g->mat[i][j] = 1;
} 

void del_edge (graf *g, int i, int j)
{
	g->mat[i][j] = 0;
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

void dfs (graf *graph, int x, int v[])
{
	int i, n = graph->n;
	v[x] = 1;
	printf ("%d ", x);
	for (i = 0; i < n; i++)
	if (check_edge(graph, x, i) && v[i] == 0)
		dfs(graph, i, v);
}

typedef struct queue {
	int value;
	struct queue *next;
} Queue;


Queue *enqueue(Queue *q, int data)
{
	Queue *new, *aux;
	new = malloc(sizeof(Queue));
	new->value = data;
	new->next = NULL;
	if (q == NULL)
		return new;
	aux = q;
	while(aux->next)
		aux = aux->next;
	aux->next = new;
	return q;

}

Queue *dequeue(Queue *q)
{
	Queue *new;
	new = q;
	if (q == NULL)
		return NULL;
	q = new->next;
	free(new);
	return q;
}

int first (Queue *q)
{
	return q->value;
}

void bfs (graf *graph, int x)
{
	Queue *q = NULL;
	int n = graph->n;
	int i;
	int *v = calloc(20, sizeof(int));
	q = enqueue(q, x);
	v[x] = 1;
	while(q != NULL)
	{
		x = first(q);
		q = dequeue(q);
		for (i = 0; i < n; i++)
		{
			if (check_edge(graph, x, i) && v[i] == 0)
			{	
				printf("%d - %d\n", x, i);
				v[i] = 1;
				q = enqueue(q, i);
			}
		}
	}
}

int main ()
{
	graf *graph = init(5);
	add_edge(graph, 5, 0);
	add_edge(graph, 4, 0);
	add_edge(graph, 5, 2);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 1);
	add_edge(graph, 4, 1);
	print_graph(graph);
	return 0;
}