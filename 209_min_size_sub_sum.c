int minSubArrayLen(int s, int *nums, int numsSize)
{
	if (!numsSize)
		return(0);
	if (numsSize == 1)
		return(nums[0] >= s ? 1 : 0);
	
	int	left, right, minlen, sum;

	left = 0;
	sum = 0;
	right = -1;
	minlen = numsSize;
	while (right < numsSize) {
		while (sum < s && ++right < numsSize)
			sum += nums[right];
		if (sum >= s) {
			if ((right - left + 1) < minlen)
				minlen = right - left + 1;
			sum -= nums[left++];
		}
		if (left > right)
			break;
	}
	return(minlen >= numsSize ? 0 : minlen);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 2, 3, 1, 2, 4, 3};
	printf("%d\n", minSubArrayLen(7, x, sizeof(x) / sizeof(x[0])));
	return(0);
}
