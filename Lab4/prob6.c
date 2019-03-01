#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
	int value;
	struct cell *next;
} Stack;

typedef struct queue {
	Stack *stack1;
	Stack *stack2;
} Queue;

Stack *push (Stack *top, int data) //doar stiva adaugare
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

int peek (Stack *top)
{
	Stack *aux = top;
	return aux->value;
}

Stack *pop (Stack *top) // merge la stiva si la coada
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
/*
Stack *enqueue(Stack *q, int data) //coada adaugare
{
	Stack *new, *aux;
	new = malloc(sizeof(Stack));
	new->value = data;
	new->next = NULL;
	if (q == NULL)
		return new;
	aux = q;
	while(aux->next)
		aux = aux->next;
	aux->next = new;
	return q;

}

int first_queue(Stack *list)
{
	Stack *aux;
	aux = list;
	if (aux == NULL)
		return 0;
	return aux->value;
}


Stack *create_queue(Stack *a, Stack *b) //creare coada
{
	Stack *c;
	c = NULL;
	while (a != NULL)
	{
		c = enqueue(c, first_queue(a));
		a = pop(a);
	}
	while (b != NULL)
	{
		c = enqueue(c, first_queue(b));
		b = pop(b);
	}
	return c;
}



void enqueue (Queue *queue, int x)
{
	*queue->stack1 = push(*queue->stack1, x);
} */

Queue *dequeue (Queue *q)
{
	int x;
	if (q->stack1 == NULL && q->stack2 == NULL)
	    return NULL;
 
	if (q->stack2 == NULL)
	{
    	while(q->stack1 != NULL)
    	{
    		x = peek (q->stack1);
        	q->stack1 = pop(q->stack1);
        	q->stack2 = push(q->stack2, x);
         
    	}
	}
 	
	q->stack2 = pop(q->stack2);
	return q;
	}

int is_stack_empty (Stack *top)
{
	return (top == NULL);
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
	Queue *pula;
	pula->stack1 = push(pula->stack1, 2);
	pula->stack1 = push(pula->stack1, 9);
	pula->stack1 = push(pula->stack1, 7);
	print_stack(pula->stack1);
	return 0;
}