#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue {
	int data;
	char operator;
	queue *next;
}

struct stack {
	char operator;
	stack *next;
}

stack *push (stack *node, char c)
{
	stack *new = malloc(sizeof(stack));
	new->operator = c;
	new->next = node;
	return new;
}

stack *pop (stack *node, char *c)
{
	if (node)
	{
		*c = node->operator;
		stack *new = node;
		node = node->next;
		free(new);
		return node;
	}
	return node;
}

queue *put (queue *node, int n, char c)
{
	queue *new = malloc(sizeof(queue));
	new->data = n;
	new->operator = c;
	new->next = NULL;
	if(!node)
		return new;
	else
	{
		queue *list = node;
		while (list->next)
			list = list->next;
		list->next = new;
		return node;
	}
}

int priority (char c)
{
	switch(c)
	{
		case '(':
			return 1;
		case ')':
			return 2;
		case '+':
		case '-':
			return 3;
		case '*':
		case '/':
			return 4;
		default:
			return 5;
	}
}

int main ()
{
	stack *list_stack = NULL;
	queue *list_queue = NULL;
	char infix[100];
	fgets(infix, 100, stdin);
	char postfix[100], o;
	int n, m = 0;
	int i = 0;
	while (infix[i] != '\0')
	{
		int k = 0;
		if ((infix[i] > 47) && (infix[i] < 58))
		{
			while ((infix[i] > 47) && (infix[i] < 58))
			{
				postfix[k] = infix[i];
				i++;
				k++;
			}
			postfix[k] = '\0';
			n = 1;
		}
		else
		{
			postfix[k] = infix[i];
			postfix[k+1] = '\0';
			i++;
			n = 0;
		}
		if (n)
		{
			o = 0;
			list_queue = put(list_queue, atoi(postfix), o);
		}
		else
		{
			if (postfix[0] == '(')
				list_stack = push(list_stack, postfix[0]);
			else
			{
				if (postfix[0] == ')')
				{
					list_stack = push(list_stack, &o);
					while (o != '(')
					{
						list_queue = put(list_queue, 0, o);
						list_stack = pop(stack, &o);
					}
				}
				else
				{
					if (priority(postfix[0]) < 5)
					{
						if (list_stack)
						{
							while ((list_stack != NULL) && (priority(list_stack->operator) > priority(postfix[0])))
							{
								list_stack = pop (list_stack, &o);
								list_queue = put (list_queue, 0, o);
							}
						}
						list_stack = push(list_stack, postfix[0]);
					}
					else
					{
						printf("error!\n");
						m = 1;
					}
				}
			}
		}
	}
	while (list_stack != NULL)
	{
		list_stack = pop (list_stack, &o);
		list_queue = push (list_queue, 0, o);
	}
	queue *aux;
	if (!m)
	{
		aux = list_queue;
		while (aux != NULL)
		{
			if (aux->data)
				printf("%d ", aux->data);
			else
				printf("%c ", aux->operator);
			aux = aux->next;
		}
	}

	return 0;
}