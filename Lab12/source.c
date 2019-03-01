#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 10

typedef struct node{
	int key;
	char *string;
	struct node *next;
} Hash;

void init (Hash **hashing)
{
	for (int i = 0; i < DIM; i++)
		hashing[i] = NULL;
}

int hash (char * string)
{
	int i, sum = 0;
	for (i = 0; i < strlen(string); i++)
		sum += (i + 1) * string[i];
	return sum % DIM;
}

Hash *search (Hash **hashing, char *string)
{
	int k = hash(string);
	Hash *one;
	one = hashing[k];
	if (one == NULL)
        return NULL;
    while (one != NULL)
    {
        if (strcmp(one->string, string) == 0)
            return one;
        one = one->next;
    }
    return NULL;
}

void insert (Hash **hashing, char *string, int key)
{
	Hash *a = search (hashing, string), *b;
	int i;
    if (a != NULL)
        (a->key)++;
    else
    {
        b = (Hash *) malloc (sizeof(Hash));
        b->string = strdup(string);
        b->key = key;
        i = hash (string);
        b->next = hashing[i];
        hashing[i] = b;
    }

}

int get_key (Hash **hashing, char *string)
{
	Hash *found = search(hashing, string);
	if (found == NULL)
		return -1;
	else
		return found->key;
}

void print_hash (Hash **hashing)
{
	Hash *one;
    for (int i = 0; i < DIM; i++)
    {
        one = hashing[i];
        while (one != NULL)
        {
            printf("Element \"%s\" with key %d\n", one->string, one->key);
            one = one->next;
        }
    }
}

void free_memory (Hash **hashing)
{
	for (int i = 0; i < DIM; i++)
		free(hashing[i]);
	free(hashing);
}

void delete (Hash **hashing, char *string)
{
	int key = hash (string);
	hashing[key] = NULL;
} 

int elements (Hash **hashing)
{
	int i, nr = 0;
	for (i = 0; i < DIM; i++)
	{
		if (hashing[i] != NULL)
			nr++;
	}
	return nr;
}

void memory_realloc (Hash **hashing)
{
	int i, nr = elements(hashing);
	if (nr == DIM)
	{	
		nr *= 2;
		hashing = realloc (hashing, nr);
	}
	else
		return;
}


int main ()
{
	Hash **hashing = (Hash **) malloc (DIM * sizeof(Hash *));
	init(hashing);
	insert(hashing, "feck", 0);
	insert(hashing, "elth de cacat", 4);
	insert(hashing, "matamata69", 7);
	insert(hashing, "laba", 0);
	insert(hashing, "asfafef", 0);
	insert(hashing, "13fvea", 0);
	insert(hashing, "-", 0);
	insert(hashing, "ZZZZZZZZZZZ", 0);
	insert(hashing, "hyundai rullz", 3);
	insert(hashing, "bmw suckz", 8);
	insert(hashing, "mihu suge", 9);
	print_hash(hashing);
	delete(hashing, "feck");
	printf("\n");
	print_hash(hashing);
	printf("\n");
	delete(hashing, "ZZZZZZZZZZZ");
	print_hash(hashing);
	printf("\n");
	return 0;
}