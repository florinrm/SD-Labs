#include <stdio.h>
#include <stdlib.h>

int sum (int k)
{
	int s = 0;
	while (k)
	{
		int c = k % 10;
		s = s + c;
		k = k / 10;
	}
	return s;
}

long control (long n)
{
	if (n < 10)
		return n;
	else
		{long c = sum(n);
		return control(c);
}

}

int main ()
{
	long k;
	scanf("%ld", &k);
	long p = control(k);
	printf("%ld\n", p);
	return 0;
}