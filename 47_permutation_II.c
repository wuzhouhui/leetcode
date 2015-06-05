/*
 * accepted, but too slow.
 */
#include <stdlib.h>
#include <string.h>

#define STEP	8

static int **res, *ans, maxp, p;
static char *occupy;

static void init(int n)
{
	ans = malloc(n * sizeof(int));
	occupy = calloc(n, sizeof(char));
	res = 0;
	maxp = p = 0;
}

static void deinit(void)
{
	free(ans);
	free(occupy);
}

static void add_ans(int n)
{
	int	i;

	for (i = 0; i <= (p - 1); i++) {
		if (!memcmp(res[i], ans, n * sizeof(int)))
			return;
	}

	if (!res) {
		maxp = STEP;
		res = malloc(maxp * sizeof(int *));
		p = 0;
	}

	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(int *));
	}
	res[p] = malloc(n * sizeof(int));
	memcpy(res[p], ans, n * sizeof(int));
	p++;
}

static void do_perm(const int *nums, int n, int start)
{
	int	i;

	if (n == start) {
		add_ans(n);
		return;
	}

	for (i = 0; i < n; i++) {
		if (occupy[i])
			continue;
		occupy[i] = 1;
		ans[start] = nums[i];
		do_perm(nums, n, start + 1);
		occupy[i] = 0;
	}
}

int **permuteUnique(int *nums, int numsSize, int *returnSize)
{
	if (!numsSize) {
		*returnSize = 0;
		return(0);
	}

	init(numsSize);
	do_perm(nums, numsSize, 0);
	deinit();
	*returnSize = p;
	return(res);
}

int main(void)
{
	int	**res, ret;
	int	x[] = {1, 1, 2};

	res = permuteUnique(x, 3, &ret);
	return(0);
}
