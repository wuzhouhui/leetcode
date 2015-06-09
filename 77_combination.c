#include <string.h>
#include <stdlib.h>

#define STEP 8

static int **res, *col, maxp, p, *ans;

static void do_init(int k)
{
	res = 0;
	col = 0;
	maxp = p = 0;
	ans = malloc(k * sizeof(int));
}

static void add_ans(int k)
{
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

	res[p] = malloc(k * sizeof(int));
	memcpy(res[p], ans, k * sizeof(int));
	col[p] = k;
	p++;
}

static void do_comb(int n, int k, int start)
{
	int	i;

	if (start >= k) {
		add_ans(k);
		return;
	}

	if (!start) {
		for (i = 1; i <= n; i++) {
			ans[start] = i;
			do_comb(n, k, start + 1);
		}
		return;
	}

	if ((k - start) > (n - ans[start - 1]))
		return;
	for (i = ans[start - 1] + 1; i <= n; i++) {
		ans[start] = i;
		do_comb(n, k, start + 1);
	}
}

int **combine(int n, int k, int **columnSizes, int *returnSize)
{
	if (k < 1 || n < 1 || k > n) {
		*columnSizes = 0;
		*returnSize = 0;
		return(0);
	}

	do_init(k);
	do_comb(n, k, 0);
	*columnSizes = col;
	*returnSize = p;
	free(ans);
	return(res);
}

int main(void)
{
	int	**res, *col, n;
	res = combine(4, 2, &col, &n);
	return(0);
}
