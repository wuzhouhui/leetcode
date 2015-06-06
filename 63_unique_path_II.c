
static int grid[100][100];

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridRowSize,
		int obstacleGridColSize)
{
	if (!obstacleGridRowSize || !obstacleGridColSize)
		return(0);

	int	i, j;

	for (i = 0; i < obstacleGridRowSize; i++) {
		for (j = 0; j < obstacleGridColSize; j++) {
			if (obstacleGrid[i][j]) {
				grid[i][j] = 0;
				continue;
			}
			if (!i && !j) {
				grid[0][0] = (obstacleGrid[0][0] ? 0 : 1);
				continue;
			}
			if (!i) {
				grid[0][j] = (obstacleGrid[0][j-1] ? 0:
						grid[0][j-1]);
				continue;
			}
			if (!j) {
				grid[i][0] = (obstacleGrid[i-1][0] ? 0:
						grid[i-1][0]);
				continue;
			}
			grid[i][j] = (obstacleGrid[i-1][j] ? 0 : grid[i-1][j])
				+ (obstacleGrid[i][j-1] ? 0 : grid[i][j-1]);
		}
	}
	return(grid[obstacleGridRowSize-1][obstacleGridColSize-1]);
}

#include <stdio.h>

int main(void)
{
}
