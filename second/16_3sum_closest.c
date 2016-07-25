#include <limits.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	qsort(nums, numsSize, sizeof(nums[0]), cmp);
	int sum = 0, min = INT_MAX;
	int i;
	for (i = 0; i < numsSize - 2; i++) {
		int left = i + 1;
		int right = numsSize - 1;
		while (left < right) {
			int t = nums[i] + nums[left] + nums[right];
			long int diff = labs(t - target);
			if (diff < min) {
				min = diff;
				sum = t;
			}
			if (t > target)
				right--;
			else if (t < target)
				left++;
			else
				return(sum);
		}
	}
	return(sum);
}

#include <stdio.h>

int main(void)
{
	int arr[] = { 0, 2, 1, -3, };
	printf("%d\n", threeSumClosest(arr, 4, 0));
}
