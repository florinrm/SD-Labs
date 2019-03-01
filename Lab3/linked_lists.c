#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node * next
} Node;

void init (Node **list)
{
	*list = NULL;
}

void show (Node *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->val);
		list = list->next;
	}
}

int is_empty(Node *list)
{
	return (list->next == NULL);
}

void push (Node *list, int x)
{
	Node *new_list = (Node *)malloc(sizeof(Node));
	new_list->val = x;
	new_list->next = list->next;
	list->next = new_list;
}

int pop (Node *list) //primul element
{
	Node *buffer_list;
	int x;
	buffer_list = list->next;
	x = buffer_list->val;
	list->next = buffer_list->next;
	free(buffer_list);
	return x;
}