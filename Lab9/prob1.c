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

int check_edge (graf *graph, int i, int j)
{
	if (graph->mat[i][j] == 1)
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

void sort (graf *g, int x, int v[])
{
	int i;
	v[x] = 1;
	printf("%d ", x);
	int n = g->n;
	for (i = 0; i < n; i++)
	{
		if (check_edge(g, x, i) && v[i] == 0)
			dfs(g, i, v);
	}
}

typedef struct cell {
	int value;
	struct cell *next;
} Stack;

Stack *push (Stack *top, int data)
{
	Stack *new;
	new = malloc (sizeof(Stack));
	if (new == NULL)
		return NULL;
	new->value = data;
	if (top == NULL)
	{
		new->next = NULL;
		top = new;
	}
	else
	{
		new->next = top;
		top = new;
	}
	return new;

}

Stack *pop (Stack *top)
{
	int data;
	Stack *new;
	new = top;
	if (top == NULL)
		return NULL;
	data = new->value;
	top = new->next;
	free(new);
	return top;
}

void sort_stack (graf *g, int x, int v[], Stack **list)
{
	int i;
	v[x] = 1;
	int n = g->n;
	for (i = 0; i < n; i++)
	{
		if (check_edge(g, x, i) && v[i] == 0)
			sort_stack(g, i, v, list);
	}
	*list = push(*list, x);
}

int beginning[10], ending[10];

void sort_time (graf *g, int x, int v[], Stack **list, int *count)
{
	int i;
	v[x] = 1;
	int n = g->n;
	beginning[x] = ++(*count);
	for (i = 0; i < n; i++)
	{
		if (check_edge(g, x, i) && v[i] == 0)
			sort_time(g, i, v, list, count);
	}
	ending[x] = ++(*count);
	*list = push(*list, x);
}

void transpose (graf *g)
{
	int i, j, n = g->n;
	int **a = malloc (n * sizeof(int *));
	for (i = 0; i < n; i++)
		a[i] = malloc (n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			a[i][j] = g->mat[j][i];
	}
	g->mat = a;
}
/*
void another_sort (graf *g, int x, int v[], Stack **list)
{
	int i;
	v[x] = 1;
	int n = g->n;
	for (i = 0; i < n; i++)
	{
		if (check_edge(g, x, i) && v[i] == 0)
			sort_stack(g, i, v, list);
	}
	*list = push(*list, x);
	transpose(g);

} */

int main ()
{
	graf *graph = init(6);
	add_edge(graph, 5, 0);
	add_edge(graph, 4, 0);
	add_edge(graph, 5, 2);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 1);
	add_edge(graph, 4, 1);
	print_graph(graph);
	printf("meh\n");
	int *v = calloc (36, sizeof(int));
	sort(graph, 5, v);
	Stack *stack = NULL;
	int *visited = calloc(36, sizeof(int));
	printf("\n");
	int count = 0;
	//sort_stack(graph, 5, visited, &stack);
	sort_time(graph, 5, visited, &stack, &count);
	while (stack != NULL)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	int n = graph->n;
	int i;
	for (i = 0; i < n; i++)
		printf("%d %d\n", beginning[i], ending[i]);
	//transpose(g);
	//while (stack != NULL)
	//	sort_stack(graph, 5, visited, &stack);
	return 0;
}