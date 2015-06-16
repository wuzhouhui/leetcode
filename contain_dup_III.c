/*
 * time limit exceeded.
 */
#include <stdlib.h>

#ifndef bool 
#define bool int 
#endif

bool containsNearbyAlmostDuplicate(int *nums, int numsSize, int k, int t)
{
	if (numsSize < 2)
		return(0);

	int	i, j;
	long long diff;

	for (i = 0; i < numsSize - 1; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if ((j - i) > k)
				break;

			diff = (long long)nums[i] - (long long)nums[j];
			if (diff < 0)
				diff = -diff;
			if (diff <= (long long)t)
				return(1);
		}
	}
	return(0);
}

int main(void)
{

}
