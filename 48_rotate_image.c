void rotate(int **matrix, int matrixRowSize, int matrixColSize)
{
	if (matrixRowSize <= 1)
		return;

	int	i, l, k, t;

	i = 0;
	l = matrixRowSize - 1;
	while (l >= 1) {
		for (k = 0; k < l; k++) {
			t = matrix[i][i+k];
			matrix[i][i+k] = matrix[i+l-k][i];
			matrix[i+l-k][i] = matrix[i+l][i+l-k];
			matrix[i+l][i+l-k] = matrix[k+i][i+l];
			matrix[k+i][i+l] = t;
		}
		i++;
		l -= 2;
	}
}

int main(int argc, char **argv)
{
}
