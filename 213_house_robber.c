int rob(int *nums, int numsSize)
{
	if (!numsSize)
		return(0);
	if (numsSize == 1)
		return(nums[0]);
	if (numsSize == 2)
		return(nums[0] > nums[1] ? nums[0] : nums[1]);

	int	money[numsSize];
	int	i, first, last, t;
	int	r1, r2;

	first = last = 0;
	for (i = 0; i < numsSize; i++) {
		if (i == 0) {
			money[i] = nums[0];
			first = 1;
			continue;
		}
		if (i == 1) {
			if (nums[1] > nums[0]) {
				money[i] = nums[1];
				first = 0;
			} else {
				money[i] = money[i - 1];
			}
			continue;
		}
		t = nums[i] + money[i - 2];
		if (t > money[i - 1]) {
			money[i] = t;
			if (i == (numsSize - 1))
				last = 1;
			if ((i - 2) == 0)
				first = 1;
		} else {
			money[i] = money[i - 1];
			if (i == (numsSize - 1))
				last = 0;
		}
	}

	if (!first || !last)
		return(money[numsSize - 1]);

	first = money[numsSize - 1] - nums[0];
	last = money[numsSize - 1] - nums[numsSize - 1];
	for (i = 1; i < numsSize; i++) {
		if (i == 1) {
			money[i] = nums[i];
			continue;
		}
		if (i == 2) {
			money[i] = nums[2] > nums[1] ? nums[2] : nums[1];
			continue;
		}
		t = nums[i] + money[i - 2];
		money[i] = t > money[i - 1] ? t : money[i - 1];
	}
	r1 = money[numsSize - 1];
	for (i = 0; i < (numsSize - 1); i++) {
		if (i == 0) {
			money[i] = nums[i];
			continue;
		}
		if (i == 1) {
			money[i] = nums[1] > nums[0] ? nums[1] : nums[0];
			continue;
		}
		t = nums[i] + money[i - 2];
		money[i] = t > money[i - 1] ? t : money[i - 1];
	}
	r2 = money[numsSize - 2];
	if (last > first)
		first = last;
	if (r1 > first)
		first = r1;
	if (r2 > first)
		first = r2;
	return(first);
}

#include <stdio.h>

int main(void)
{
	int x[] = { 8, 2, 8, 9, 2 };
	printf("%d\n", rob(x, sizeof(x)/sizeof(x[0])));
	return(0);
}
