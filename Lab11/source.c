#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
	int array[100];
	int n;
} Heap;

int valmin (Heap *a, int k)
{
	int st = 2 * k;
	int dr = st++;
	int m = k;
	if (st <= a->n && a->array[st] < a->array[m])
		m = st;
	if (dr <= a->n && a->array[dr] < a->array[m])
		m = dr;
	return m;

}

void addPQ (Heap *a, int x)
{
	int k = ++(a->n);
	a->array[k] = x;
	while (k > 1 && a->array[k / 2] > a->array[k])
	{
		int aux = a->array[k / 2];
		a->array[k / 2] = a->array[k];
		a->array[k] = aux;
		k = k / 2;
	}
}

void heapify (Heap *a, int k)
{
	int m = valmin(a, k);
	if (a->array[m] != a->array[k])
	{
		int aux = a->array[k];
		a->array[k] = a->array[m];
		a->array[m] = aux;
		heapify(a, m);
	}

}

int delPQ (Heap *a)
{
	int x = a->array[0];
	a->array[0] = a->array[a->n--];
	heapify(a, 0);
	return x;
}

int is_empty (Heap *a)
{
	return (a->n == 0);
}

void print (Heap *a)
{
	int i;
	for (i = 1; i < a->n + 1; i++)
		printf("%d ", a->array[i]);
}

typedef struct node {
	char ch;
	int freq;
	struct node *left;
	struct node *right;
} Node;

Node *insertPQ (Node **a, char ch)
{
	int k = ++(a->n);
	a->array[k] = x;
	while (k > 1 && a->array[k / 2] > a->array[k])
	{
		int aux = a->array[k / 2];
		a->array[k / 2] = a->array[k];
		a->array[k] = aux;
		k = k / 2;
	}
}


Node *deletePQ (Node **a)
{
	int x = a->array[0];
	a->array[0] = a->array[a->n--];
	heapify(a, 0);
	return x;
}

Node *valmin_tree (Node **a, int k, int *p)
{
	int st = 2 * k;
	int dr = st++;
	int m = k;
	if (st <= *p && a[st]->freq < a[m]->freq)
		m = st;
	if (dr <= *p && a[dr]->freq < a[m]->freq)
		m = dr;
	return m;

}

void heapify_tree (Node **a, int k)
{
	int m = valmin(a, k);
	if (a->array[m] != a->array[k])
	{
		int aux = a->array[k];
		a->array[k] = a->array[m];
		a->array[m] = aux;
		heapify(a, m);
	}

}

Node *make (char ch, short freq, Node *left, Node *right)
{
	Node *tree = (Node *) malloc (sizeof(Tree));
	tree->left = left;
	tree->right = right;
	tree->ch = ch;
	tree->freq = freq;
	return tree;
}

int main ()
{
	Heap *a = (Heap *) malloc (sizeof(Heap));
	a->n = 0;
	int i;
	for (i = 0; i < 100; i++)
		a->array[i] = 0;
	addPQ(a, 700);
	addPQ(a, 500);
	addPQ(a, 100);
	addPQ(a, 800);
	addPQ(a, 200);
	addPQ(a, 400);
	addPQ(a, 900);
	addPQ(a, 1000);
	print(a);
	printf("\n");
	int p = delPQ(a);
	printf("%d\n", p);
	print(a);
	printf("\n");
	char ch[] = {'a','b','c','d','e','f'};
	char freq[] = {36, 14, 12, 10, 20, 8};
	Node *q = NULL;
	return 0;
}