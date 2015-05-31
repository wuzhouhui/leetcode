#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int	*res, l, u, m;

	res = malloc(2 * sizeof(int));
	*returnSize = 2;
	if (numsSize == 0) {
		res[0] = res[1] = -1;
		return(res);
	}
	if (numsSize == 1) {
		if (nums[0] == target)
			res[0] = res[1] = 0;
		else 
			res[0] = res[1] = -1;
		return(res);
	}

	l = -1;
	u = numsSize;
	while ((l + 1) != u) {
		m = (l + u) / 2;
		if (nums[m] < target)
			l = m;
		else 
			u = m;
	}
	res[0] = u;
	if (u >= numsSize || nums[u] != target) {
		res[0] = res[1] = -1;
		return(res);
	}

	l = -1;
	u = numsSize;
	while ((l + 1) != u) {
		m = (l + u) / 2;
		if (nums[m] <= target)
			l = m;
		else 
			u = m;
	}
	res[1] = l;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	x[] = {5, 7, 7, 8, 8, 10 };
	int	i;
	int	*res = searchRange(x, 1, 11, &i);
	printf("%d %d\n", res[0], res[1]);
	return(0);
}
