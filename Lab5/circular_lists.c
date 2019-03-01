#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
} Node;

typedef struct {
	Node *start;
	Node *current;
}

void insert_start (List *list, int data)
{
	if (list->start == NULL)
	{
		
	}
}