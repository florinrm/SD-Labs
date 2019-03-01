#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int weight;
	int v;
	struct node *next;
} Node;

typedef struct graph {
	Node **list;
	int n;	
} Graph;

Graph *init_list (int n)
{
	Graph *graf = malloc(sizeof(Graph));
	graf->n = n;
	graf->list = calloc(n, sizeof(Node));
}

int empty_list (Graph *g, int i)
{
	if (g->list[i] == NULL)
		return 0;
	return 1;
}

void print_list (Graph *g, int i)
{
	Node *list = g->list[i];
}

int main ()
{
	Graph *g = init_list(3);
	return 0;
}