#include <stdlib.h> 
#include <string.h>

#define MAXN	512
#define STEP	16

static int	**res;
static int	perm[MAXN];
static int	p, maxp;
static char	occupy[MAXN];

#define initial() do {				\
	res = NULL;				\
	bzero(occupy, sizeof(occupy));		\
	p = maxp = 0;				\
} while (0)

static int avail(int n)
{
	int	i;

	for (i = 0; i < p; i++) {
		if (!memcmp(res[i], perm, n * sizeof(perm[0])))
			return(0);
	}
	return(1);
}

static void add_res(int n)
{
	if (!maxp) {
		maxp = STEP;
		res = malloc(maxp * sizeof(int *));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(int *));
	}
	res[p] = malloc(n * sizeof(int));
	memcpy(res[p], perm, n * sizeof(int));
	p++;
}

static void bktrack(int *nums, int n, int lev)
{
	int	i;

	if (!lev) {
		for (i = 0; i < n; i++) {
			perm[0] = nums[i];
			occupy[i] = 1;
			bktrack(nums, n, lev + 1);
			occupy[i] = 0;
		}
		return;
	}
	if (lev == (n - 1)) {
		for (i = 0; i < n; i++) {
			if (!occupy[i])
				break;
		}
		perm[lev] = nums[i];
		if (avail(n))
			add_res(n);
		return;
	}
	for (i = 0; i < n; i++) {
		if (occupy[i])
			continue;
		perm[lev] = nums[i];
		occupy[i] = 1;
		bktrack(nums, n, lev + 1);
		occupy[i] = 0;
	}
}

int **permute(int *nums, int numsSize, int *returnSize)
{
	initial();
	if (!numsSize) {
		*returnSize = 0;
		return(NULL);
	}
	if (numsSize == 1) {
		*returnSize = 1;
		res = malloc(sizeof(int *));
		res[0] = malloc(sizeof(int));
		res[0][0] = nums[0];
		return(res);
	}
	bktrack(nums, numsSize, 0);
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	**ret, n;
	int	x[] = { 1, 2, 3 };

	permute(x, sizeof(x) / sizeof(x[0]), &n);
	printf("%d\n", n);
	return(0);
}
