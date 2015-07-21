#include <stdlib.h>

int *majorityElement(int *nums, int numsSize, int *returnSize)
{
	int	i, e1, e2, c1, c2;
	int	e1vld, e2vld;
	int	*res;

	/*
	 * tell if e1 or e2 is validate
	 */
	e1vld = e2vld = 0;

	c1 = c2 = 0;
	for (i = 0; i < numsSize; i++) {
		if (e1vld && e1 == nums[i]) {
			c1++;
		} else if (e2vld && e2 == nums[i]) {
			c2++;
		} else if (c1 == 0) {
			e1vld = 1;
			e1 = nums[i];
			c1 = 1;
		} else if (c2 == 0) {
			e2vld = 1;
			e2 = nums[i];
			c2 = 1;
		} else {
			c1--;
			c2--;
		}
	}
	c1 = c2 = 0;
	for (i = 0; i < numsSize; i++) {
		if (e1vld && e1 == nums[i])
			c1++;
		else if (e2vld && e2 == nums[i])
			c2++;
	}
	res = malloc(2 * sizeof(int));
	i = 0;
	if (e1vld && c1 > numsSize / 3)
		res[i++] = e1;
	if (e2vld && c2 > numsSize / 3)
		res[i++] = e2;
	*returnSize = i;
	return(res);
}

int main(void)
{
}
