#include <stdlib.h>
#define STEP	16

static int **res;
static int p, maxp;

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void add_ans(const int *nums, int a1, int a2, int a3, int a4)
{
	int	i;

	for (i = 0; i <= (p - 1); i++) {
		if (res[i][0] == nums[a1]
				&& res[i][1] == nums[a2]
				&& res[i][2] == nums[a3]
				&& res[i][3] == nums[a4])
			return;
	}
	if (!res) {
		maxp = STEP;
		p = 0;
		res = malloc(maxp * sizeof(int *));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(int *));
	}
	res[p] = malloc(4 * sizeof(int));
	res[p][0] = nums[a1];
	res[p][1] = nums[a2];
	res[p][2] = nums[a3];
	res[p][3] = nums[a4];
	p++;
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize)
{
	if (numsSize < 4) {
		*returnSize = 0;
		return(0);
	}

	int	a1, a2, a3, a4;
	int	t;

	res = 0;
	p = 0;

	qsort(nums, numsSize, sizeof(int), intcmp);
	a1 = 0;
	a2 = 1;
	a4 = numsSize - 1;
	while ((a4 - a1) >= 3) {
		while ((a4 - a2) >= 2) {
			for (a3 = a2 + 1; a3 < a4; ) {
				t = nums[a1] + nums[a2] + nums[a3] + nums[a4];
				if (t > target) {
					a4--;
					continue;
				}
				if (t == target)
					add_ans(nums, a1, a2, a3, a4);
				a3++;
			}
			a2++;
			a4 = numsSize - 1;
		}
		a1++;
		a2 = a1 + 1;
		a4 = numsSize - 1;
	}

	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	x[] = {	1, 0, -1, 0, -2, 2 };
	int	i;
	int	**res;
	res = fourSum(x, sizeof(x)/sizeof(int), 0, &i);
	while (i-- > 0)
		printf("%d %d %d %d\n", res[i][0], res[i][1], res[i][2],
				res[i][3]);
	return(0);
}
