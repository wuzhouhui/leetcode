#ifndef bool 
#define bool int 
#endif 

bool search(int *nums, int numsSize, int target)
{
	if (!numsSize)
		return(0);
	if (numsSize == 1)
		return(nums[0] == target ? 1 : 0);

	int	l, r, m;

	l = 0;
	r = numsSize - 1;
	while (l <= r) {
		m = (l + r) / 2;
		if (nums[m] == target)
			return(1);
		if (nums[l] < nums[m]) {
			if (target < nums[m] && target >= nums[l])
				r = m - 1;
			else 
				l = m + 1;
		} else if (nums[l] > nums[m]) {
			if (target > nums[m] && target <= nums[r])
				l = m + 1;
			else
				r = m - 1;
		} else {
			l++;
		}
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 1, 3, 5 };
	printf("%d\n", search(x, sizeof(x) / sizeof(int), 1));
	return(0);
}
