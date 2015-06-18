static void swap(int *x, int i, int j)
{
	int	t = x[i];
	x[i] = x[j];
	x[j] = t;
}

int findKthLargest(int *nums, int numsSize, int k)
{
	if (numsSize <= 1)
		return(numsSize ? nums[0] : 0);

	int	l, u, i, j;

	l = 0;
	u = numsSize - 1;
	while (1) {
		i = l;
		for (j = l + 1; j <= u; j++) {
			if (nums[j] <= nums[l])
				swap(nums, ++i, j);
		}
		swap(nums, l, i);
		if ((numsSize - i) == k)
			return(nums[i]);
		if ((numsSize - i) > k)
			l = i + 1;
		else 
			u = i - 1;
	}
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 3, 2, 1, 5, 6, 4 };
	printf("%d\n", findKthLargest(x, sizeof(x)/sizeof(x[0]), 2));
	return(0);
}
