#include <stdlib.h>

struct answer {
	int	cnt;
	int	val;
};

static int **res, *cols;
static int p, maxp;
static struct answer *ans;

#define STEP	16
#define init_globs() do {						\
	res = NULL;							\
	cols = NULL;							\
	p = maxp = 0;							\
	ans = malloc(candidatesSize * sizeof(struct answer));		\
	int	i;							\
	for (i = 0; i < candidatesSize; i++) {				\
		ans[i].cnt = 0;						\
		ans[i].val = candidates[i];				\
	}								\
} while (0)

#define clean_globs() do {						\
	if (ans)							\
		free(ans);						\
} while (0)

static int int_cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void add_ans(int n)
{
	int	i, j, s;

	if (!res) {
		maxp = STEP;
		p = 0;
		res = malloc(maxp * sizeof(int *));
		cols = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(int *));
		cols = realloc(cols, maxp * sizeof(int));
	}
	for (s = i = 0; i <= n; i++) {
		s += ans[i].cnt;
	}
	cols[p] = s;
	res[p] = malloc(s * sizeof(int));
	for (s = i = 0; i <= n; i++) {
		if (ans[i].cnt == 0)
			continue;
		for (j = 0; j < ans[i].cnt; j++)
			res[p][s++] = ans[i].val;
	}
	p++;
}

static void do_comb(int *nums, int n, int tgt, int sum, int start)
{
	int	i, tmp; 

	for (i = start; i < n; i++) {
		tmp = sum + nums[i];
		if (tmp > tgt)
			break;

		ans[i].cnt++;
		if (tmp == tgt) {
			add_ans(i);
			ans[i].cnt--;
			continue;
		}
		do_comb(nums, n, tgt, tmp, i);
		ans[i].cnt--;
	}
}

int **combinationSum(int *candidates, int candidatesSize, int target,
		int **columnSizes, int *returnSize)
{
	if (!candidatesSize) {
		*columnSizes = NULL;
		*returnSize = 0;
		return(NULL);
	}

	qsort(candidates, candidatesSize, sizeof(int), int_cmp);
	init_globs();
	do_comb(candidates, candidatesSize, target, 0, 0);
	*columnSizes = cols;
	*returnSize = p;
	clean_globs();
	return(res);
}

int main(void)
{
	int	x[] = {8, 7, 4, 3}, *col, size, **res;
	res = combinationSum(x, sizeof(x) / sizeof(x[0]), 11, &col, &size);
	return(0);
}
