int search(int *nums, int numsSize, int target)
{
	if (!numsSize)
		return(-1);
	if (numsSize == 1)
		return(nums[0] == target ? 0 : -1);

	int	l, u, m;

	l = 0;
	u = numsSize - 1;
	while (l <= u) {
		m = (l + u) / 2;
		if (nums[m] == target)
			return(m);
		if (target > nums[m]) {
			if (nums[m] > nums[u])
				l = m + 1;
			else {
				if (target <= nums[u])
					l = m + 1;
				else 
					u = m - 1;
			}
		} else {
			if (nums[m] > nums[u]) {
				if (target <= nums[u])
					l = m + 1;
				else 
					u = m - 1;
			} else {
				u = m - 1;
			}
		}
	}
	return(-1);
}

#include <stdio.h>

int main(void)
{
	int x[] = { 3, 1};
	int	i = 1;
	printf("%d\n", search(x, sizeof(x) / sizeof(x[0]), i));
	return(0);
}
