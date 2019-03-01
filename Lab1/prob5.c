#include <stdio.h>

int f1 (int n);
int f2 (int n);

int main ()
{
	int a;
	scanf("%d", &a);
	int k = f1(a);
	int n = f2(a);
	printf("%d %d\n", k, n);
	return 0;
}

int f1 (int n)
{
	if (n!=1)
		return n * f2(n-1);
}

int f2 (int n)
{
	if (n!=1)
		return n + f1(n-1);
}