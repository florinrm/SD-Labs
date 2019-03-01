#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
	char value;
	struct cell *next;
} Stack;

Stack *push (Stack *top, char data)
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
	char data;
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

char top (Stack *head)
{
	Stack *aux;
	aux = head;
	return aux->value;
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

int is_pairing (char one, char two)
{
	if (one == '(' && two == ')')
		return 1;
	else if (one == '[' && two == ']')
		return 1;
	else if (one == '{' && two == '}')
		return 1;
	return 0;
}

int is_matched (char *expression)
{
	Stack *stack = NULL;
	int i = 0;
	while (expression[i])
	{
		if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
			stack = push (stack, expression[i]);
		if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
		{
			if (stack == NULL)
				return 0;
			else if (!is_pairing(top(stack), expression[i]))
				return 0;
			else
				stack = pop(stack);
		}
		i++;
	}
	if (stack == NULL)
		return 1;
	else 
		return 0;
}

int main ()
{
	char a[200];
	fgets(a, 200, stdin);
	if (is_matched(a))
		printf("Corect\n");
	else printf("Incorect\n");
	return 0;
}