#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap (int a, int b)
{
	int aux = a;
	a = b;
	b = aux;
}

void permute (char A[], int l, int r)
{
   if (l == r)
     printf("%s\n", A);
   else
   {
   	   int i;
       for (i = l; i < r; i++)
       {
          swap(A[l], A[i]);
          permute(A, l+1, r);
          swap(A[l], A[i]);
       }
   }
}

int main ()
{
	char set[50];
	int k, n;
	fgets(set, 50, stdin);
	k = strlen(set);
	permute(set, 0, 3);
	return 0;
}