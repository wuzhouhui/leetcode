#include <stdlib.h>
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	if (numsSize <= 1) {
		*returnSize = 0;
		return(NULL);
	}

	int	*res, *tmp;
	int	i;

	tmp = malloc(numsSize * sizeof(nums[0]));
	tmp[0] = 1;
	for (i = 1; i < numsSize; i++)
		tmp[i] = tmp[i - 1] * nums[i - 1];

	res = malloc(numsSize * sizeof(nums[0]));
	res[numsSize - 1] = 1;
	for (i = numsSize - 2; i >= 0; i--)
		res[i] = res[i + 1] * nums[i + 1];
	for (i = 0; i < numsSize; i++)
		res[i] *= tmp[i];
	free(tmp);
	*returnSize = numsSize;
	return(res);
}

int main(void)
{
}
