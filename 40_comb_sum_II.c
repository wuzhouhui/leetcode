/*
 * accepted, but too slow.
 */
#include <stdlib.h>
#include <string.h>

#define STEP	8

static int **res, *col, maxp, p;
static int *occup;

static void initial(int n)
{
	res = 0;
	col = occup = 0;
	maxp = p = 0;
	occup = calloc(n, sizeof(int));
}

static deinit()
{
	if (occup)
		free(occup);
}

static void add_ans(int *cand, int n)
{
	int	i, j;
	int	*tmp;

	tmp = calloc(n, sizeof(int));
	for (j = i = 0; i < n; i++) {
		if (occup[i])
			tmp[j++] = cand[i];
	}

	for (i = 0; i <= (p - 1); i++) {
		if (!memcmp(res[i], tmp, n * sizeof(int))) {
			free(tmp);
			return;
		}
	}

	if (!res) {
		maxp = STEP;
		p = 0;
		res = malloc(maxp * sizeof(int *));
		col = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(int *));
		col = realloc(col, maxp * sizeof(int));
	}
	res[p] = tmp;
	col[p] = j;
	p++;
}

static void do_comb(int *cand, int n, int tgt, int sum)
{
	int	i;

	if (sum == tgt) {
		add_ans(cand, n);
		return;
	}

	for (i = 0; i < n; i++) {
		if (occup[i])
			continue;
		if ((sum + cand[i]) > tgt)
			break;
		occup[i] = 1;
		do_comb(cand, n, tgt, sum + cand[i]);
		occup[i] = 0;
	}
}

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int **combinationSum2(int *candidates, int candidatesSize, int target,
		int **columnSizes, int *returnSize)
{
	if (!candidatesSize) {
		*columnSizes = 0;
		*returnSize = 0;
		return(0);
	}
	initial(candidatesSize);
	qsort(candidates, candidatesSize, sizeof(int), intcmp);
	do_comb(candidates, candidatesSize, target, 0);
	if (!p) {
		*columnSizes = 0;
		*returnSize = 0;
		deinit();
		return(0);
	}
	*columnSizes = col;
	*returnSize = p;
	deinit();
	return(res);
}

int main(void)
{
	int	**res, *col, ret;
	int	x[] = {10, 1, 2, 7, 6, 1, 5 };
	res = combinationSum2(x, 7, 8, &col, &ret);
	return(0);
}
