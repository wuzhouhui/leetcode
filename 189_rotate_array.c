
#include <string.h>

void rotate(int nums[], int n, int k)
{
	if (!nums || !n || n == 1)
		return;

	int	tmp[n];
	int	i;

	for (i = 0; i < n; i++)
		tmp[(i + k) % n] = nums[i];

	memcpy(nums, tmp, n * sizeof(int));
}
