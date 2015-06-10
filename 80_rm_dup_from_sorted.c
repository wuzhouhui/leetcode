int removeDuplicates(int *nums, int numsSize)
{
	if (numsSize < 2)
		return(numsSize);
	int	i, j, c;

	i = -1;
	for (j = 0; j < numsSize; j++) {
		if (i < 0 || nums[i] != nums[j]) {
			nums[++i] = nums[j];
			c = 1;
			continue;
		}
		if (c < 2) {
			nums[++i] = nums[j];
			c++;
		}
	}

	return(i + 1);
}

#include <stdio.h>
int main(void)
{
	int x[] = { 1, 1, 1, 2, 2, 3};
	printf("%d\n", removeDuplicates(x, 6));
	return(0);
}
