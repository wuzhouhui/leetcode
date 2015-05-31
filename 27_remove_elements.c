int removeElement(int *nums, int numsSize, int val)
{
	int	i, j;

	i = -1;
	j = numsSize;
	while (1) {
		while (++i < j && nums[i] != val)
			;
		if (i >= j)
			break;
		while (--j > i && nums[j] == val)
			;
		if (i >= j)
			break;
		nums[i] = nums[j];
		nums[j] = val;
	}
	return(i);
}

int main(void)
{
	int	num[] = { 4, 5 };
	int	a = removeElement(num, 2, 4);
	return(0);
}
