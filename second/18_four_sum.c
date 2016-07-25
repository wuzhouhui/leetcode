#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static int **res, p, maxp;

static void addans(int a, int b, int c, int d)
{
	int i;
	for (i = 0; i < p; i++)
		if (res[i][0] == a && res[i][1] == b && res[i][2] == c
				&& res[i][3] == d)
			return;
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(res[0]));
	}
	res[p] = malloc(4 * sizeof(res[0][0]));
	res[p][0] = a;
	res[p][1] = b;
	res[p][2] = c;
	res[p][3] = d;
	p++;
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize)
{
	qsort(nums, numsSize, sizeof(nums[0]), cmp);
	p = maxp = 0;
	res = 0;
	int i, j;

	for (i = 0; i < numsSize - 3; i++) {
		for (j = i + 1; j < numsSize - 2; j++) {
			int t = nums[i] + nums[j];
			int left = j + 1;
			int right = numsSize - 1;
			while (left < right) {
				int t2 = t + nums[left] + nums[right];
				if (t2 == target) {
					addans(nums[i], nums[j], nums[left],
							nums[right]);
					left++;
				} else if (t2 > target)
					right--;
				else
					left++;
			}
		}
	}
	*returnSize = p;
	return(res);
}

main(){}
