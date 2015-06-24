int findMin(int *nums, int numsSize)
{
	if (!numsSize)
		return(0);

	int	left, right, mid;

	left = 0;
	right = numsSize - 1;
	while (1) {
		if (left == right || nums[left] < nums[right])
			return(nums[left]);

		mid = (left + right) / 2;

		/* nums[left] >= nums[right] */
		if (nums[left] == nums[right]) {
			if (nums[mid] > nums[right])
				left = mid + 1;
			else if (nums[mid] < nums[right])
				right = mid;
			else 
				left++;
			continue;
		}
		
		/* nums[left] > nums[right] */
		if (nums[mid] > nums[left])
			left = mid + 1;
		else if (nums[mid] < nums[left]) {
			if (nums[mid] > nums[right])
				left = mid + 1;
			else 
				right = mid;
		} else
			left = mid + 1;
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 2, 0, 1, 1, 1,};
	printf("%d\n", findMin(x, sizeof(x) / sizeof(int)));
	return(0);
}
