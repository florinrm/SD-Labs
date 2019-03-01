#include <stdio.h>

int produs (int a, int b)
{
	if ((b-1))
		return a+produs(a, b-1);
}

int main ()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int k = produs(a, b);
	printf("%d\n", k);
	return 0;
}