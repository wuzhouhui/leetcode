int maxSubArray(int *nums, int numsSize)
{
	if (!numsSize)
		return(0);

	int	i, glo_max, loc_max, t;

	loc_max = glo_max = nums[0];
	for (i = 1; i < numsSize; i++) {
		t = loc_max + nums[i];
		loc_max = t > nums[i] ? t : nums[i];
		glo_max = glo_max > loc_max ? glo_max : loc_max;
	}

	return(glo_max);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	printf("%d\n", maxSubArray(x, sizeof(x) / sizeof(int)));
	return(0);
}
