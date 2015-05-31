int findPeakElement(int num[], int n)
{
	if (!num || !n)
		return(-1);
	if (n == 1)
		return(0);
	if (n == 2)
		return(num[0] > num[1] ? 0 : 1);
	int	m, l, h;
	l = 0;
	h = n - 1;
	while (l <= h) {
		m = (l + h) / 2;
		if (m == 0 && num[0] > num[1])
			return(0);
		if (m == (n - 1) && num[n - 1] > num[n - 2])
			return(n - 1);
		if (num[m] > num[m + 1] && num[m] > num[m - 1])
			return(m);
		if (num[m] < num[m + 1]) {
			l = m + 1;
			continue;
		}
		if (num[m] < num[m - 1]) {
			h = m - 1;
			continue;
		}
	}

	return(-1);
}

#include <stdio.h>

int main(void)
{
	int	num[] = { 1, 2, 3, 1 };
	printf("%d\n", findPeakElement(num, sizeof(num) / sizeof(int)));
	return(0);
}
