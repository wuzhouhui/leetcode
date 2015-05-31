int jump(int *nums, int numsSize)
{
	if (!numsSize || numsSize == 1)
		return(0);

	int	cur, next, max, res, i;

	cur = 0;
	res = 0;
	while (1) {
		max = -1;
		for (i = 1; i <= nums[cur]; i++) {
			if ((cur + i) >= (numsSize - 1))
				return(res + 1);
			if (nums[cur + i] == 0)
				continue;
			if ((cur + i + nums[cur + i]) > max) {
				next = i;
				max = cur + i + nums[cur + i];
			}
		}
		if (max < 0)
			return(0);
		cur += next;
		res++;
	}
	return(res);
}

#include <stdio.h>

int main(void)
{
	int x[] = { 1, 1, 1, 1 };
	printf("%d\n", jump(x, 4));
	return(0);
}
