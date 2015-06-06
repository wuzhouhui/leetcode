
static int grid[100][100];

int uniquePaths(int m, int n)
{
	if (!m || !n)
		return(0);
	if (m == 1 || n == 1)
		return(1);

	int	i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (!i || !j) {
				grid[i][j] = 1;
				continue;
			}
			grid[i][j] = grid[i-1][j] + grid[i][j-1];
		}
	}
	return(grid[m-1][n-1]);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", uniquePaths(3, 3));
	return(0);
}
