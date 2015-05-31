#include <stdlib.h>

int **generate(int numRows, int **columnSizes, int *returnSize)
{
	if (numRows <= 0) {
		*columnSizes = 0;
		*returnSize = 0;
		return(0);
	}

	int	**res, i, j;

	res = malloc(numRows * sizeof(int *));
	*returnSize = numRows;
	*columnSizes = malloc(numRows * sizeof(int));
	for (i = 0; i < numRows; i++) {
		res[i] = malloc((i + 1) * sizeof(int));
		(*columnSizes)[i] = i + 1;
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				res[i][j] = 1;
				continue;
			}
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}
	return(res);
}

int main(void)
{}
