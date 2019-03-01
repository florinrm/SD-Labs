#include <stdio.h>
#include <stdlib.h>

int minim(int *A, int low, int high)
{
	int middle = (low + high) / 2;
	if ((high-low) <= 1)
		{
			if (A[high] > A[low])
				return A[low];
			else
				return A[high];
		}
		int min1 = minim(A, low, middle);
		int min2 = minim(A, middle + 1, high);
		if (min1 < min2)
			return min1;
		else
			return min2;

}

int main ()
{
	int v[] = {2, 3, -3, 6, 10};
	int n = 4;
	int k = minim(v, 0, n);
	printf("%d\n", k);
	return 0;
}