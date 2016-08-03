int searchInsert(int *nums, int numsSize, int target)
{
	int left, right, mid;
	left = -1;
	right = numsSize;
	while (left + 1 != right) {
		mid = (left + right) / 2;
		if (nums[mid] <= target)
			left = mid;
		else
			right = mid;
	}
	if (left < 0)
		return(0);
	if (nums[left] != target && right >= numsSize)
		return(numsSize);
	return(nums[left] == target ? left : left + 1);
}

main(){}
