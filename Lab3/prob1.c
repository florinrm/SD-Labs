#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
	int value;
	struct nod *next;
}Node;

void list_print(Node *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->value);
		list = list->next;
	}
}

Node *list_append(Node *head, int data)
{
	Node *list;
	if (head == NULL)
	{
		head = malloc(sizeof(Node));
		head->value = data;
		head->next = NULL;
		return head;
	}
	list = head;
	while (list->next != NULL)
		list = list->next;
	list->next = malloc(sizeof(Node));
	list = list->next;
	list->value = data;
	list->next = NULL;
	return head;
}

Node *list_prepend(Node *head, int data)
{
	Node *list;
	if (head == NULL)
	{
		head = malloc(sizeof(Node));
		head->value = data;
		head->next = NULL;
		return head;
	}
	list = malloc(sizeof(Node));
	list->value = data;
	list->next = head;
	return list;
}

Node *list_remove_first(Node *head)
{
	Node *aux;
	aux = head;
	head = head->next;
	free(aux);
	return head;
}

Node *list_remove(Node *head, int data)
{
	if (head == NULL)
		return NULL;
	if (head->value == data)
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
		if (list->next->value == data)
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

Node *remove_max(Node *head)
{
	int max = head->value;
	Node *list;
	list = head->next;
	while (list != NULL)
	{
		if (list->value > max)
			max = list->value;
		list = list->next;
	}
	head = list_remove(head, max);
	return head;
}

Node *list_reverse(Node *head)
{
	Node *prev = NULL;
	Node *succ;
	Node *list = head;
	while (list != NULL)
	{
		succ = list->next;
		list->next = prev;
		prev = list;
		list = succ;
	}
	return prev;
}

int sum_list(Node *head)
{
	int s = 0;
	while (head != NULL)
	{
		s = s * 10 + head->value;
		head = head->next;
	}
	return s;
}

int number_reverse (int n)
{
	int cn = n, inv = 0;
	while (cn)
	{
		inv = inv * 10 + (cn % 10);
		cn = cn / 10;
	}
	return inv;
}

Node *sum(Node *head1, Node *head2)
{
	int s1 = sum_list(head1);
	int s2 = sum_list(head2);
	int a = number_reverse(s1);
	int b = number_reverse(s2);
	int suma = a + b; 
   
	Node *head;
	head = NULL;
	while (suma)
	{
		int c = suma % 10;
		head = list_append(head, c);
		suma = suma / 10;
	}
	return head;
}

int main ()
{
	Node *list;
	list = NULL;
	list = list_append(list, 1);
	list = list_append(list, 3);
	list = list_append(list, 9);
	list = list_prepend(list, 2);
	//list = list_remove_first(list);
	//list = list_remove(list, 3);
	//list = remove_max(list);
	//list = list_reverse(list);
	Node *kek;
	kek = NULL;
	kek = list_append(kek, 3);
	kek = list_append(kek, 1);
	kek = list_append(kek, 7);
	list_print(list);
	printf("Alta lista\n");
	list_print(kek);
	//int k = sum_list(list);
	//printf("lala %d\n", k);
	Node *meh;
	meh = sum(list, kek);
	printf("lala\n");
	list_print(meh);
	return 0;
}