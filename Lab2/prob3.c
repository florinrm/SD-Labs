#include <stdio.h>
#include <stdlib.h>

int apparitions (int *A, int n, int k)
{
	int nr = 0;
	int i;
	for (i)
}

int modified_binary_search(int *A, int low, int high)
{
	int middle = (low + high) / 2;
	if (low > high)
		return -1;
}

int main ()
{
	int A[] = {4, 4, 5, 5, 3, 3, 2, 1, 1, 6, 6};
	int n = 11;
	int k = modified_binary_search(A, 0, n - 1);
	printf("%d\n", k);
	return 0;
}