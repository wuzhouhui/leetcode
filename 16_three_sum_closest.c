#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
	return((*(int *)a) - (*(int *)b));
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	int	i, j, k, diff, min, sum, t;

	qsort(nums, numsSize, sizeof(int), cmp);
	sum = nums[0] + nums[1] + nums[2];
	min = abs(sum - target);
	for (i = 0; i < numsSize; i++) {
		j = i + 1;
		k = numsSize - 1;
		while (j < k) {
			t = nums[i] + nums[j] + nums[k];
			if (t > target)
				k--;
			else if (t < target)
				j++;
			else
				return(t);
			diff = abs(t - target);
			if (diff < min) {
				min = diff;
				sum = t;
			}

		}
	}
	return(sum);
}

#include <stdio.h>

int main(void)
{
	int x[] = {0, 1, 2};
	printf("%d\n", threeSumClosest(x, 3, 3));
	return(0);
}
