#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int top = -1;
int *array;

void push (int x)
{
	if (top == SIZE - 1)
		array = (int *) realloc (array, 2 * top);
	array[++top] = x;
}

void pop ()
{
	if (top == -1)
		return;
	top--;
}

int main ()
{
	array = (int *) malloc (SIZE * sizeof(int));
	push(56);
	push(69);
	push(21);
	int i;
	for (i = 0; i <= top; i++)
		printf("%d\n", array[i]);
	free(array);
	return 0;
}