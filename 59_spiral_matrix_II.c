#include <stdlib.h>

int **generateMatrix(int n)
{
	if (!n)
		return(NULL);

	int	**m, i, squ, l, u;

	m = malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		m[i] = malloc(n * sizeof(int));

	l = 0;
	u = n - 1;
	squ = 1;
	while (l < u) {
		for (i = l; i < u; i++)
			m[l][i] = squ++;
		for (i = l; i < u; i++)
			m[i][u] = squ++;
		for (i = u; i > l; i--)
			m[u][i] = squ++;
		for (i = u; i > l; i--)
			m[i][l] = squ++;
		l++;
		u--;
	}
	if (n % 2)
		m[n / 2][n / 2] = squ++;
	return(m);
}

int main(void)
{
	generateMatrix(2);
	return(0);
}
