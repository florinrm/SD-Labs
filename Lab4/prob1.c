#include <stdio.h>
#include <stdlib.h>

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

int is_stack_empty (Stack *top)
{
	return (top == NULL);
}

void top (Stack *head)
{
	Stack *aux;
	aux = head;
	printf("THe top is: %d\n", aux->value);
}

void print_stack(Stack * top)
{
	Stack *new = top;
	if (new == NULL)
		return;
	while (new != NULL)
	{
		printf("%d\n", new->value);
		new = new->next;
	}
}

int main ()
{
	Stack *list;
	list = NULL;
	list = push(list, 4);
	list = push(list, 1);
	list = push(list, 9);
	print_stack(list);
	printf("fulala\n");
	top(list);
	printf("kek\n");
	list = pop(list);
	print_stack(list);
	return 0;

}