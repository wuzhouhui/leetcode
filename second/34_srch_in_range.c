#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int *res = malloc(sizeof(*res) * 2);
	int left, right, mid;

	*returnSize = 2;
	left = -1;
	right = numsSize;
	while (left + 1 != right) {
		mid = (left + right) / 2;
		if (nums[mid] < target)
			left = mid;
		else
			right = mid;
	}
	if (right >= numsSize || nums[right] != target) {
		res[0] = res[1] = -1;
		return(res);
	} else
		res[0] = right;
	left = -1;
	right = numsSize;
	while (left + 1 != right) {
		mid = (left + right) / 2;
		if (nums[mid] <= target)
			left = mid;
		else
			right = mid;
	}
	res[1] = left;
	return(res);
}

int main(void)
{
	int arr[] = { 5, 7, 7, 8, 8, 10, };
	int *a, n;
	a = searchRange(arr, sizeof(arr) / sizeof(arr[0]), 8, &n);
	return(0);
}
