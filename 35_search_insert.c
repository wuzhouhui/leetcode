int searchInsert(int *nums, int numsSize, int target)
{
	if (!numsSize)
		return(0);
	int res, l, u, m;

	res = -1;
	l = 0;
	u = numsSize - 1;
	while (l <= u) {
		m = (l + u) / 2;
		if (nums[m] < target)
			l = m + 1;
		else if (nums[m] > target)
			u = m - 1;
		else {
			res = m;
			break;
		}
	}
	if (res >= 0)
		return(res);

	if (target < nums[m])
		return(m);
	else 
		return(m + 1);
}

#include <stdio.h>
int main(void)
{
	int x[] = { 1, 3, 5, 6 };
	printf("%d\n", searchInsert(x, sizeof(x) / sizeof(int), 0));
	return(0);
}
