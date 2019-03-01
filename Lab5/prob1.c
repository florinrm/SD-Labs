#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
} Node;

Node *append (Node *head, int data)
{
	Node *list;
	Node *new;
	if (head == NULL)
	{
		head = malloc(sizeof(Node));
		head->data = data;
		head->next = NULL;
		head->prev = NULL;
		return head;
	}
	list = head;
	while(list->next != NULL)
		list = list->next;
	//list->next = malloc(sizeof(Node));
	new = malloc(sizeof(Node));
	list->next = new;
	new->data = data;
	new->prev = list;
	new->next = NULL;
	return head;
}

Node * remove_list (Node *head, int data)
{
	if (head == NULL)
		return NULL;
	if (head->data == data)
	{
		Node *aux;
		aux = head;
		head = head->next;
		free(aux);
		return head;
	}
	Node *list;
	list = head;
	while(list->next != NULL)
	{
		if (list->next->data == data)
		{
			Node *aux1;
			aux1 = list->next;
			list->next = list->next->next;
			free(aux1);
			return head;
		}
		list = list->next;
	}
	return head;
}

void print_forward (Node *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}

void print_backwards (Node *head)
{
	while (head->next != NULL)
		head = head->next;
	while (head != NULL)
	{
		printf("%d\n", head->data);
		head = head->prev;
	}
}

int main ()
{
	Node *list = NULL;
	list = append(list, 5);
	list = append(list, 2);
	list = append(list, 8);
	list = append(list, 69);
	print_forward(list);
	//printf("lala\n");
	//list = remove_list(list, 2);
	//print_forward(list);
	printf("lala\n");
	print_backwards(list);
	return 0;
}