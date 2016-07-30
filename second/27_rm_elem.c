int removeElement(int *nums, int numsSize, int val)
{
	int i, j;
	for (i = j = 0; i < numsSize; i++)
		if (nums[i] == val)
			continue;
		else
			nums[j++] = nums[i];
	return(j);
}
main(){}
