#include <string.h>
#include <strings.h>

int numDistinct(char *s, char *t)
{
	int	l1 = strlen(s), l2 = strlen(t);
	int	c[l1 + 1][l2 + 1];
	int	i, j;

	bzero(c, sizeof(c));
	for (i = 0; i <= l1; i++)
		c[i][0] = 1;
	for (i = 1; i <= l1; i++) {
		for (j = 1; j <= l2; j++) {
			c[i][j] = c[i-1][j];
			if (s[i-1] == t[j-1])
				c[i][j] += c[i-1][j-1];
		}
	}
	return(c[l1][l2]);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", numDistinct(argv[1], argv[2]));
	return(0);
}
