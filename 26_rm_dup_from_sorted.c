int removeDuplicates(int *nums, int numsSize)
{
	if (!numsSize || numsSize == 1)
		return(numsSize);

	int	prev, next;

	for (prev = 0, next = 1; next < numsSize; next++) {
		if (nums[prev] == nums[next])
			continue;
		nums[++prev] = nums[next];
	}
	return(prev + 1);
}

#include <stdio.h>

int main(void)
{
	int x[3] = { 1, 1, 2};
	printf("%d\n", removeDuplicates(x, 3));
	return(0);
}
