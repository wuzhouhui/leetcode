#ifndef bool 
#define bool int 
#endif 

bool canJump(int *nums, int numsSize)
{
	if (!numsSize || numsSize == 1)
		return(1);

	int	i, cur, next, max;

	cur = 0;
	while (1) {
		max = -1;
		for (i = 1; i <= nums[cur]; i++) {
			if ((i + cur) >= (numsSize - 1))
				return(1);
			if (nums[i + cur] == 0)
				continue;
			if ((cur + i + nums[cur + i]) > max) {
				max = cur + i + nums[cur + i];
				next = cur + i;
			}
		}
		if (max == -1)
			return(0);
		if (max >= (numsSize - 1))
			return(1);
		cur = next;
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 2, 0 };
	printf("%d\n", canJump(x, sizeof(x) / sizeof(int)));
	return(0);
}
