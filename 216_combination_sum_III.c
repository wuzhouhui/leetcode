#include <stdlib.h>
#include <string.h>

#define STEP 8

static int **res, *ans, p, maxp, *col;

static void do_init(int k)
{
	res = 0;
	col = ans = 0;
	p = maxp = 0;
	ans = malloc(k * sizeof(int));
}

static void do_clean(void)
{
	if (ans)
		free(ans);
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

static void do_comb(int start, int k, int sum, int n)
{
	if (start >= k && sum == n) {
		add_ans(k);
		return;
	}

	if (start >= k)
		return;

	int	i;

	i = (start ? (ans[start - 1] + 1) : 1);
	for (; i <= 9; i++) {
		if ((sum + i) <= n) {
			ans[start] = i;
			do_comb(start + 1, k, sum + i, n);
			ans[start] = 0;
		}
	}
}

int **combinationSum3(int k, int n, int **columnSizes, int *returnSize)
{
	if (k <= 0 || k >= 10 || n <= 0) {
		*columnSizes = 0;
		*returnSize = 0;
		return(0);
	}

	do_init(k);
	do_comb(0, k, 0, n);
	do_clean();
	
	if (res) {
		*columnSizes = col;
		*returnSize = p;
		return(res);
	}

	*columnSizes = 0;
	*returnSize = 0;
	return(0);
}

int main(void)
{
	int	**res, n, *col;

	res = combinationSum3(3, 28, &col, &n);
	return(0);
}
