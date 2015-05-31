// out if time for //
//void rotate(int nums[], int n, int k)
//{
//	if (!nums || !n || n == 1)
//		return;
//
//	int	i, tmp;
//
//	for ( ; k > 0; k--) {
//		tmp = nums[0];
//		for (i = n - 1; i > 0; i--)
//			nums[(i + 1) % n] = nums[i];
//		nums[1] = tmp;
//	}
//}

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
