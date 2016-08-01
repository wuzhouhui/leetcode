int search(int *nums, int numsSize, int target)
{
	if (numsSize <= 0)
		return(-1);
	int left = 0, right = numsSize - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target)
			return(mid);
		if (nums[left] < nums[right]) {
			if (nums[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
			continue;
		}
		if (nums[mid] < nums[right]) {
			if (target < nums[mid])
				right = mid - 1;
			else if (target <=  nums[right])
				left = mid + 1;
			else
				right = mid - 1;
			continue;
		}
		if (target > nums[mid])
			left = mid + 1;
		else if (target >= nums[left])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return(nums[left] == target ? left : -1);
}

main(){}
