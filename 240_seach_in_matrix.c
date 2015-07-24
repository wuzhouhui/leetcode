#define bool int

static int bin_sch(int *x, int l, int u, int t)
{
	int	m;
	
	while (l <= u) {
		m = (l + u) / 2;
		if (x[m] == t)
			return(1);
		else if (x[m] < t)
			l = m + 1;
		else
			u = m - 1;
	}
	return(0);
}

bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize,
		int target)
{
	if (matrixRowSize == 0 || matrixColSize == 0)
		return(0);

	int	l, u, m, down, up;

	l = -1;
	u = matrixRowSize;
	while ((l + 1) != u) {
		m = (l + u) / 2;
		if (matrix[m][0] == target)
			return(1);
		else if (matrix[m][0] > target)
			u = m;
		else
			l = m;
	}
	if (l == -1)
		return(0);
	down = l;

	l = -1;
	u = matrixRowSize;
	while ((l + 1) != u) {
		m = (l + u) / 2;
		if (matrix[m][matrixColSize - 1] == target)
			return(1);
		else if (matrix[m][matrixColSize - 1] < target)
			l = m;
		else
			u = m;
	}
	if (u == matrixRowSize)
		return(0);
	up = u;

	for ( ; up <= down; up++) {
		if (bin_sch(matrix[up], 0, matrixColSize - 1, target))
			return(1);
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	int	r0[] = { 1, 4, 7, 11, 15 };
	int	r1[] = { 2, 5, 8, 12, 19 };
	int	r2[] = { 3, 6, 9, 16, 22 };
	int	r3[] = { 10, 13, 14, 17, 24 };
	int	r4[] = { 18, 21, 23, 26, 30 };
	int	*m[] = { r0, r1, r2, r3, r4 };

	printf("%d\n", searchMatrix(m, 5, 5, 20));
	return(0);
}
