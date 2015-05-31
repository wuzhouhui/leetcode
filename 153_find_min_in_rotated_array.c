int findMin(int num[], int n)
{
	if (n == 1)
		return(num[0]);
	if (n == 2)
		return(num[0] < num[1] ? num[0] : num[1]);

	int	l, h, m;
	int	left, right;

	l = 0;
	h = n - 1;
	while (1) {
		m = (l + h) / 2;
		left = m - 1;
		if (left < 0)
			left = n - 1;
		right = (m + 1) % n;

		if (num[left] > num[m] && num[m] < num[right])
			return(num[m]);
		if (num[left] < num[m] && num[m] > num[right])
			return(num[right]);
		if (num[l] > num[right]) {
			h = m - 1;
			continue;
		}
		if (num[l] < num[right]) {
			l = m + 1;
			continue;
		}
	}

	return(-1);
}

#include <stdio.h>

int main(void)
{
	int	n[] = {4, 5, 6, 7, 0, 1, 2};
	printf("%d\n", findMin(n, sizeof(n) / sizeof(int)));
	return(0);
}
