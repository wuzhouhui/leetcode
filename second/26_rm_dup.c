int removeDuplicates(int *nums, int numsSize)
{
	int i = 0, j = 0;
	int prev;
	while (i < numsSize) {
		prev = nums[i++];
		while (i < numsSize && nums[i] == prev)
			i++;
		nums[j++] = prev;
	}
	return(j);
}
main(){}
