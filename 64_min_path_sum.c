//#define ind(i, j) ((i) * gridColSize + (j))
int minPathSum(int **grid, int gridRowSize, int gridColSize)
{
	if (!gridRowSize || !gridColSize)
		return(0);

	int	i, j;
	int	*m;

	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (!i && !j)
				continue;
			if (!i)
				grid[0][j] += grid[0][j - 1];
			else if (!j)
				grid[i][0] += grid[i - 1][0];
			else 
				grid[i][j] += (grid[i-1][j] < grid[i][j-1] ?
					grid[i-1][j] : grid[i][j-1]);
		}
	}
	return(grid[gridRowSize - 1][gridColSize - 1]);
	//m = (int *)grid;
	/*
	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (!i && !j)
				continue;
			if (!i)
				m[ind(0, j)] += m[ind(0, j - 1)];
			else if (!j)
				m[ind(i, 0)] += m[ind(i - 1, 0)];
			else 
				m[ind(i, j)] += (m[ind(i - 1, j)] < 
					m[ind(i, j - 1)] ? m[ind(i - 1, j)]
					: m[ind(i, j - 1)]);
		}
	}
	*/
	//return(m[ind(gridRowSize - 1, gridColSize - 1)]);
}

#include <stdio.h>

int main(void)
{
	int m[2][2] = {
		{ 1, 2 },
		{ 1, 1 },
	};
	printf("%d\n", minPathSum((int **)m, 2, 2));
	return(0);
}
