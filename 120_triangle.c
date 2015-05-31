#include <stdlib.h>

int minimumTotal(int **triangle, int numRows)
{
	if (!numRows)
		return(0);

	int	*pre, *next, *t;
	int	i, j, min;

	pre = malloc(numRows * sizeof(int));
	next = malloc(numRows * sizeof(int));
	for (i = 0; i < numRows; i++) {
		if (i == 0) {
			pre[0] = triangle[0][0];
			min = pre[0];
			continue;
		}
		for (j = 0; j <= i; j++) {
			if (j == 0) {
				next[0] = pre[0] + triangle[i][0];
				min = next[0];
			} else if (j == i) {
				next[j] = pre[j - 1] + triangle[i][j];
				if (next[j] < min)
					min = next[j];
			} else {
				next[j] = triangle[i][j] + (pre[j - 1]
						< pre[j] ? pre[j - 1] :
						pre[j]);
				if (next[j] < min)
					min = next[j];
			}
		}
		t = pre;
		pre = next;
		next = t;
	}
	free(pre);
	free(next);
	return(min);
}

#include <stdio.h>

int main(void)
{
	int **x = malloc(4 * sizeof(int *));
	x[0] = malloc(1 * sizeof(int));
	x[1] = malloc(2 * sizeof(int));
	x[2] = malloc(3 * sizeof(int));
	x[3] = malloc(4 * sizeof(int));
	x[0][0] = 2;
	x[1][0] = 3; x[1][1] = 4;
	x[2][0] = 6; x[2][1] = 5; x[2][2] = 7;
	x[3][0] = 4; x[3][1] = 1; x[3][2] = 8; x[3][3] = 3;
	printf("%d\n", minimumTotal(x, 4));
	free(x[0]);
	free(x[1]);
	free(x[2]);
	free(x[3]);
	free(x);
	return(0);
}
