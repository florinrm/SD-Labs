#include <stdio.h>

int suma (int n)
{
	if (n)
		return n + suma (n-1);
}

int main ()
{
	int n;
	scanf("%d", &n);
	int k = suma(n);
	printf("%d\n", k);
	return 0;
}