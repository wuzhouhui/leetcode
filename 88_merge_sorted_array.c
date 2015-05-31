#include <stdlib.h>
#include <string.h>

void merge(int *nums1, int m, int *nums2, int n)
{
	if (!n)
		return;
	if (!m) {
		memcpy(nums1, nums2, n * sizeof(int));
		return;
	}

	int *tmp, i, j, k;

	tmp = malloc((m + n) * sizeof(int));
	for (k = i = j = 0; i < m && j < n; ) {
		if (nums1[i] < nums2[j])
			tmp[k++] = nums1[i++];
		else 
			tmp[k++] = nums2[j++];
	}
	if (i < m)
		memcpy(tmp + k, nums1 + i, (m - i) * sizeof(int));
	if (j < n)
		memcpy(tmp + k, nums2 + j, (n - j) * sizeof(int));
	memcpy(nums1, tmp, (m + n) * sizeof(int));
	free(tmp);
}

int main(void)
{}
