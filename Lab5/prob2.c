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

void insert_mean (Node *head)
{
	Node *list = head;
	while (list->next != NULL)
	{
		int x = 0;
		if (((list->data % 2) == 0)&&((list->next->data % 2) == 0))
		{
			Node * new = malloc(sizeof(Node));
			x = (list->data + list->next->data) / 2;
			new->data = x;
			new->prev = list;
			new->next = list->next;
			list->next = new;
			list->next->prev = new;
			list = list->next->next;
		}
		else if (((list->data % 2) == 1)&&((list->next->data % 2) == 1))
		{
			Node * new = malloc(sizeof(Node));
			x = (list->data + list->next->data) / 2;
			new->data = x;
			new->prev = list;
			new->next = list->next;
			list->next = new;
			list->next->prev = new;
			list = list->next->next;
		}
		else
			list = list->next;

	}
}

void do_stuff (Node *head)
{
	Node * list = head;
	Node * aux;
	int n;
	while (list->next != NULL)
	{
		if (list->data % 2 != 0 && list != NULL)
		{
			printf ("%d\n",list->data);
			aux = list;
			list->data = n;
			list = list->prev;
			head = remove_list(head, aux->data);
			while(n != 0 && list != NULL)
			{
				list = list-> prev;
				printf("%d\n",list->data);
				n--;
			}
		}
		printf("%d\n",list->data);
		list = list->next;
	}
}

int main ()
{
	Node *list = NULL;
	list = append(list, 2);
	list = append(list, 4);
	list = append(list, 6);
	list = append(list, 3);
	list = append(list, 1);
	list = append(list, 2);
	print_forward(list);
	printf("lala\n");
	//insert_mean(list);
	list = remove_list(list, 6);
	list = remove_list(list, 2);
	print_forward(list);
	//printf("lala\n");
	//do_stuff(list);
	return 0;
}