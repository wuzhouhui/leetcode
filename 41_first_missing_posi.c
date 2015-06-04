int firstMissingPositive(int *nums, int numsSize)
{
	if (!numsSize)
		return(1);

	int	i, t;

	i = 0; 
	while (i < numsSize) {
		if ((nums[i] != (i + 1)) && (nums[i] >= 1)
				&& (nums[i] <= numsSize)
				&& (nums[i] != nums[nums[i] - 1])) {
			t = nums[nums[i] - 1];
			nums[nums[i] - 1] = nums[i];
			nums[i] = t;
		} else {
			i++;
		}
	}
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != (i + 1))
			return(i + 1);
	}
	return(numsSize + 1);
}

#include <stdio.h>

int main(void) 
{
	int x[] = { 1, 2, 0};
	printf("%d\n", firstMissingPositive(x, sizeof(x) / sizeof(int)));
	return(0);
}
