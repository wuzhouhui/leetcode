void nextPermutation(int *nums, int numsSize)
{
	if (!numsSize || numsSize == 1)
		return;

	int	i, chan_ind, part_ind, j;

	chan_ind = part_ind = -1;
	for (i = numsSize - 2; i >= 0; i--) {
		if (nums[i] < nums[i + 1]) {
			part_ind = i;
			break;
		}
	}
	for (i = numsSize - 1; i >= 0; i--) {
		if (nums[i] > nums[part_ind]) {
			chan_ind = i;
			break;
		}
	}
	if (part_ind >= 0) {
		i = nums[part_ind];
		nums[part_ind] = nums[chan_ind];
		nums[chan_ind] = i;
	}
	i = part_ind + 1;
	j = numsSize - 1;
	chan_ind = (i + j) / 2;
	for ( ; i <= chan_ind; i++, j--) {
		part_ind = nums[i];
		nums[i] = nums[j];
		nums[j] = part_ind;
	}
	return;
}

int main(void)
{
	int	x[] = { 1, 1, 5 };
	nextPermutation(x, 3);
	return(0);
}
