#ifndef bool 
#define bool int 
#endif

bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize,
		int target)
{
	if (!matrixRowSize || !matrixColSize)
		return(0);

	int	l, u, m, t;
	
	l = 0;
	u = matrixRowSize * matrixColSize - 1;
	while (l <= u) {
		m = (l + u) / 2;
		t = matrix[m / matrixColSize][m % matrixColSize];
		if (t == target)
			return(1);
		if (target < t)
			u = m - 1;
		else 
			l = m + 1;
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	int m[1][1] = { 1 };
	printf("%d\n", searchMatrix((int **)m, 1, 1, 1));
	return(0);
}
