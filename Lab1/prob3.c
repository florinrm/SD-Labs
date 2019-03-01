#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inverse (char buffer[], int start, int end)
{
	char aux;
	//int n = strlen(buffer) - 1;
	//int start = 0;
	if (start < end)
{
	aux = buffer[start];
	buffer[start] = buffer[end];
	buffer[end] = aux;
	inverse(buffer, start+1, end-1);
}
}

int main ()
{
	char s[100];
	fgets(s, 100, stdin);
	int start = 0;
	int end = strlen(s) - 1;
	inverse(s, start, end);
	printf("%s\n", s);
	return 0;
}