#define RED	0
#define WHITE	1
#define BLUE	2

void sortColors(int *nums, int numsSize)
{
	if (!numsSize || numsSize == 1)
		return;

	int	color[3] = { 0, 0, 0 };
	int	i, j, p;

	for (i = 0; i < numsSize; i++)
		color[nums[i]]++;
	for (p = i = 0; i < 3; i++) {
		for (j = 0; j < color[i]; j++)
			nums[p++] = i;
	}
}

int main(void)
{}
