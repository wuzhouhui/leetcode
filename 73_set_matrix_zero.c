#include <string.h>

void setZeroes(int **matrix, int matrixRowSize, int matrixColSize)
{
	if (!matrixRowSize || !matrixColSize)
		return;

	int	i, j, rowflag, colflag;

	for (rowflag = 1, i = 0; i < matrixColSize; i++)
		if (matrix[0][i] == 0) {
			rowflag = 0;
			break;
		}
	for (colflag = 1, i = 0; i < matrixRowSize; i++)
		if (matrix[i][0] == 0) {
			colflag = 0;
			break;
		}
	for (i = 1; i < matrixRowSize; i++) {
		for (j = 1; j < matrixColSize; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				break;
			}
		}
	}
	for (i = 1; i < matrixColSize; i++) {
		for (j = 1; j < matrixRowSize; j++) {
			if (matrix[j][i] == 0) {
				matrix[0][i] = 0;
				break;
			}
		}
	}

	for (i = 1; i < matrixRowSize; i++) {
		if (matrix[i][0] == 0)
			memset(matrix[i], 0, matrixColSize * sizeof(int));

	}
	for (i = 1; i < matrixColSize; i++) {
		if (matrix[0][i])
			continue;
		for (j = 1; j < matrixRowSize; j++)
			matrix[j][i] = 0;
	}
	if (rowflag == 0)
		memset(matrix[0], 0, matrixColSize * sizeof(int));
	if (colflag == 0)
		for (i = 0; i < matrixRowSize; i++)
			matrix[i][0] = 0;
}

int main(void)
{

}
