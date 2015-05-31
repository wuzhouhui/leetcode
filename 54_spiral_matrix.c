#include <stdlib.h>

int *spiralOrder(int **matrix, int matrixRowSize, int matrixColSize)
{
	if (!matrixRowSize || !matrixColSize)
		return(NULL);

	int	*seq, i;
	int	p, rowstart, rowend, colstart, colend;

	rowstart = colstart = 0;
	rowend = matrixRowSize - 1;
	colend = matrixColSize - 1;
	matrixRowSize *= matrixColSize;
	seq = malloc(matrixRowSize * sizeof(int));
	p = 0;
	while (rowstart < rowend && colstart < colend) {
		for (i = colstart; i < colend; i++)
			seq[p++] = matrix[rowstart][i];
		for (i = rowstart; i < rowend; i++)
			seq[p++] = matrix[i][colend];
		for (i = colend; i > colstart; i--)
			seq[p++] = matrix[rowend][i];
		for (i = rowend; i > rowstart; i--)
			seq[p++] = matrix[i][colstart];
		rowstart++;
		rowend--;
		colstart++;
		colend--;
	}

	if (p == matrixRowSize)
		return(seq);

	if (rowend == rowstart)
		for (i = colstart; i <= colend; i++)
			seq[p++] = matrix[rowend][i];
	else if (colend == colstart)
		for (i = rowstart; i <= rowend; i++)
			seq[p++] = matrix[i][colend];
	return(seq);
}

int main(void)
{}
