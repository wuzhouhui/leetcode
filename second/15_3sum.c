#include <stdlib.h>

static int **res, p, maxp;

static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void addans(int a, int b, int c)
{
	int i;

	for (i = 0; i < p; i++)
		if (res[i][0] == a && res[i][1] == b && res[i][2] == c)
			return;
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p] = malloc(3 * sizeof(res[p][0]));
	res[p][0] = a;
	res[p][1] = b;
	res[p][2] = c;
	p++;
}

int **threeSum(int *nums, int numsSize, int *returnSize)
{
	int i;

	p = maxp = 0;
	res = NULL;
	qsort(nums, numsSize, sizeof(nums[0]), cmp);
	for (i = 0; i < numsSize - 2 && nums[i] <= 0; i++) {
		int left = i + 1;
		int right = numsSize - 1;
		while (left < right) {
			int t = nums[i] + nums[left] + nums[right];
			if (t < 0)
				left++;
			else if (t > 0)
				right--;
			else {
				addans(nums[i], nums[left], nums[right]);
				left++;
			}
		}
	}
	*returnSize = p;
	return(res);
}
main()
{
	int i;
	int arr[] = { -2, 0, 1, 1, 2, };
	threeSum(arr, 5, &i);
}
