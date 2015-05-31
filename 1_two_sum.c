#include <stdlib.h>

struct astru {
	int	val;
	int	ind;
};

static int strucmp(const void *a, const void *b)
{
	return(((struct astru *)a)->val - ((struct astru *)b)->val);
}

int *twoSum(int *nums, int numsSize, int target)
{
	if (numsSize < 2)
		return(0);

	int	*res, l, u, tmp;
	struct astru *arr;

	arr = malloc(numsSize * sizeof(struct astru));
	for (l = 0; l < numsSize; l++) {
		arr[l].val = nums[l];
		arr[l].ind = l;
	}

	qsort(arr, numsSize, sizeof(struct astru), strucmp);
	l = 0;
	u = numsSize - 1;
	while (l < u) {
		tmp = arr[l].val + arr[u].val;
		if (tmp > target)
			u--;
		else if (tmp < target)
			l++;
		else 
			break;
	}
	if (tmp != target)
		return(0);
	res = malloc(2 * sizeof(int));
	res[0] = arr[l].ind + 1;
	res[1] = arr[u].ind + 1;
	free(arr);
	if (res[0] > res[1]) {
		l = res[0];
		res[0] = res[1];
		res[1] = l;
	}
	return(res);
}

#include <stdio.h>

int main(void)
{
	int x[] = { 2, 7, 11, 15 };
	int	*res;
	res = twoSum(x, 4, 9);
	printf("%d %d\n", res[0], res[1]);
	return(0);
}
