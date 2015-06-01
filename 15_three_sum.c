#include <stdlib.h>

#define STEP	16

static int **res;
static int maxp, p;

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void add_ans(const int *nums, int left, int mid, int right)
{
	int	i;
	for (i = 0; i <= p - 1; i++) {
		if (res[i][0] == nums[left] &&
				res[i][1] == nums[mid] &&
				res[i][2] == nums[right])
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
	res[p] = malloc(3 * sizeof(int));
	res[p][0] = nums[left];
	res[p][1] = nums[mid];
	res[p][2] = nums[right];
	p++;
}

int **threeSum(int *nums, int numsSize, int *returnSize)
{
	if (numsSize < 3) {
		*returnSize = 0;
		return(0);
	}

	int	left, right, mid, t;

	res = 0;
	p = 0;

	qsort(nums, numsSize, sizeof(int), intcmp);
	left = 0;
	right = numsSize - 1;
	while ((right - left) >= 2) {
		for (mid = left + 1; mid < right;) {
			t = nums[left] + nums[mid] + nums[right];
			if (t > 0)
				right--;
			else if (t < 0)
				mid++;
			else {
				add_ans(nums, left, mid, right);
				mid++;
			}
		}
		left++;
		right = numsSize - 1;
	}

	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	x[] = {	-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6 };
	int	i;
	int	**res;
	res = threeSum(x, sizeof(x)/sizeof(int), &i);
	while (i-- > 0)
		printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
	return(0);
}
