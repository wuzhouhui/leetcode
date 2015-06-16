#include <stdlib.h>

#ifndef bool 
#define bool int 
#endif 

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

bool containsDuplicate(int *nums, int numsSize)
{
	if (!numsSize || numsSize == 1)
		return(0);

	int	i;
	qsort(nums, numsSize, sizeof(int), intcmp);
	for (i = 1; i < numsSize; i++) {
		if (nums[i] == nums[i - 1])
			return(1);
	}

	return(0);
}

int main(void)
{

}
