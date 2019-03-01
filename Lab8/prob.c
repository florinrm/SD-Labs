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
	g->mat[j][i] = 1;
} 

void del_edge (graf *g, int i, int j)
{
	g->mat[i][j] = 0;
	g->mat[j][i] = 0;
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

int grad (graf *g, int i)
{
	int n = g->n;
	int j;
	int count = 0;
	for (j = 0; j < n; j++)
	{
		if (g->mat[i][j] == 1)
			count++;
	}
	return count;
}

int check_edge (graf *graph, int i, int j)
{
	if (graph->mat[i][j] == 1)
		return 1;
	return 0;
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

void conex (graf *graph, int x, int *v)
{
	int i, n = graph->n;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (v[i] == 0)
		{
			printf("Conex \n");
			dfs(graph, i, v);
			count++;
			printf("\n");
		}
	}
	printf("Numarul de componente conexe %d\n", count);
}

typedef struct nod { 
	int val; 
	int cost;
	struct nod* leg; 
} nod;

typedef struct graph_list {
	int n;
	struct nod **a;
} graph_list;

graph_list *init_list (int n)
{
	nod *graph = (graph_list *) malloc(n * sizeof(graph_list));
	graph->val = n;
	graph->a = (nod **) calloc (n, sizeof(nod*));
	return graph;

} 

graph_list *add_list (graph_list *graph, int x, int y, int c)
{
	nod *new = (nod *) malloc(n * sizeof(nod));
	new->val = x;
	new->cost = c;
	return graph;
} 

int main ()
{
	graf *graph = init(3);
	add_edge(graph, 0, 1);
	add_edge(graph, 1, 2);
	add_edge(graph, 2, 1);
	add_edge(graph, 0, 2);
	print_graph(graph);
	printf("\n");
	int *v = calloc(10, sizeof(int));
	printf("%d\n", grad(graph, 2));
	//dfs(graph, 2, v);
	//bfs(graph, 2);
	conex(graph, 0, v);
	return 0;
}