typedef struct cell {
	int value;
	struct cell *next;
} Queue;

int is_queue_empty (Queue *q)
{
	return (q == NULL);
}

Queue *enqueue(Queue *q, int data)
{
	Queue *new, *aux;
	new = malloc(sizeof(Queue));
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

Queue *dequeue(Queue *q)
{
	int data;
	Queue *new;
	new = q;
	if (q == NULL)
		return NULL;
	data = new->value;
	q = new->next;
	free(new);
	return q;
}

void print_list(Queue *q)
{
	Queue *aux;
	aux = q;
	if (aux == NULL)
		return;
	while (aux != NULL)
	{
		printf("%d\n", aux->value);
		aux = aux->next;
	}
}
