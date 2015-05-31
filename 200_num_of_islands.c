#define ACCESSED '\t'

static int maxrow, maxcol;

static void access(char **grid, int row, int col)
{
	if (row < 0 || row > maxrow || col < 0 || col > maxcol)
		return;
	if (grid[row][col] == '0' || grid[row][col] == ACCESSED)
		return;

	grid[row][col] = ACCESSED;
	access(grid, row - 1, col);
	access(grid, row + 1, col);
	access(grid, row, col - 1);
	access(grid, row, col + 1);
}

int numIslands(char **grid, int gridRowSize, int gridColSize)
{
	if (!gridRowSize || !gridColSize)
		return(0);

	int	i, j, c;

	maxrow = gridRowSize - 1;
	maxcol = gridColSize - 1;
	c = 0;
	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j] != '1')
				continue;
			c++;
			access(grid, i, j);
		}
	}
	return(c);
}

int main(void)
{
}
