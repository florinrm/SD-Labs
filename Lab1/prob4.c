#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int distance(char *s1, char *s2, int *distanta)
{
	if (strlen(s1) != strlen(s2))
		return -1;
			else if (s1 == NULL)
			return *distanta;
		else
		{
			if (s1[0] != s2[0])
			{
				*distanta = *distanta + 1;
				return distance(s1+1, s2+1, distanta);}
			else
				return distance(s1+1, s2+1, distanta);
		}
}

int main ()
{
	char *s1, *s2;
	s1 = malloc (100 * sizeof(char));
	s2 = malloc (100 * sizeof(char));
	fgets(s1, 100, stdin);
	fgets(s2, 100, stdin);
	int distanta = 0;
	distance(s1, s2, &distanta);
	printf("%d\n", distanta);
	return 0;
}