int findMin(int *nums, int numsSize)
{
	if (!numsSize)
		return(0);
	
	int	left, right, mid;

	left = 0;
	right = numsSize - 1;
	while (1) {
		if (nums[left] <= nums[right])
			return(nums[left]);
		mid = (left + right) / 2;
		/* left > right */
		if (nums[mid] > nums[right]) {
			left = mid + 1;
			continue;
		}
		right = mid;
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	int	x[] = {  2, 3, 1 };
	printf("%d\n", findMin(x, sizeof(x) / sizeof(x[0])));
	return(0);
}
