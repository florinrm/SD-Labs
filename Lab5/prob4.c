#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
	//struct node *prev;
} Node;

typedef struct {
	Node *start;
	Node *current;
} List;

//Node *current;

Node* insert_start(Node *list, int data)
{
	if (list != NULL)
	{
		list = malloc(sizeof(Node));
		list->data = data;
		list->next = NULL;
		return list;
	};
	Node *start = list;
	Node *new = malloc(sizeof(Node));
	new->data = data;
	new->next = start;
	return list;

}
/*
void remove_list (List *list, int data)
{

}

void advance_n (List *list, int n)
{

}
*/

void print_forward (Node *head)
{
	Node *start = head;
	while (head->next != start)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

int main ()
{
	Node *list = NULL;
	list = insert_start(list, 1);
	list = insert_start(list, 2);
	list = insert_start(list, 3);
	print_forward(list);
	return 0;

}