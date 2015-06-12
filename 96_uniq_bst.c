#include <strings.h>

int numTrees(int n)
{
	if (!n || n == 1)
		return(1);

	int	c[n + 1];
	int	i, j;

	bzero(c, sizeof(c));
	c[0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			c[i] += c[j - 1] * c[i - j];
		}
	}
	return(c[n]);
}

#include <stdio.h>

