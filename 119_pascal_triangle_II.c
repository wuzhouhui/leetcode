#include <string.h>
#include <stdlib.h>

int *getRow(int rowIndex, int *returnSize)
{
	if (rowIndex < 0) {
		*returnSize = 0;
		return(NULL);
	}

	int	*row1, *row2;
	int	i, j;

	row1 = malloc((rowIndex + 1) * sizeof(int));
	row2 = malloc((rowIndex + 1) * sizeof(int));
	for (i = 0; i <= rowIndex; i++) {
		for (j = 0; j <= rowIndex; j++)
			if (j == 0 || j == i)
				row2[j] = 1;
			else 
				row2[j] = row1[j - 1] + row1[j];
		memcpy(row1, row2, (i + 1) * sizeof(int));
	}
	*returnSize = i;
	free(row1);
	return(row2);
}

int main(void)
{}
