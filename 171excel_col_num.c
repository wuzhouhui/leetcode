#include <string.h>

int titleToNumber(char *s)
{
	if (!s)
		return 0;

	int n, l;

	for (n = 0, l = 0; l < strlen(s); l++) {
		n = n*26 + s[l] - 'A' + 1;
	}

	return n;
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", titleToNumber("AB"));
	return 0;
}
