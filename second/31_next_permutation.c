static inline void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void nextPermutation(int *nums, int numsSize)
{
	if (numsSize <= 1)
		return;
	int ind1, ind2;
	int i;

	ind1 = ind2 = -1;
	for (i = numsSize - 2; i >= 0; i--)
		if (nums[i] < nums[i + 1]) {
			ind1 = i;
			break;
		}
	for (i = numsSize - 1; i >= 0; i--)
		if (nums[i] > nums[ind1]) {
			ind2 = i;
			break;
		}
	if (ind1 >= 0)
		swap(&nums[ind1], &nums[ind2]);
	i = ind1 + 1;
	numsSize--;
	while (i < numsSize)
		swap(&nums[i++], &nums[numsSize--]);
	return;
}
main(){}
