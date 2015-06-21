
int rob(int num[], int n)
{
	if (!num || !n)
		return 0;
	if (n == 1)
		return num[0];
	if (n == 2)
		return (num[0] > num[1] ? num[0] : num[1]);

	int	buf[n];
	int	i, a;

	buf[0]	= num[0];
	buf[1]	= num[0] > num[1] ? num[0] : num[1];

	for (i = 2; i < n; i++) {
		a = num[i] + buf[i - 2];
		buf[i] = a > buf[i - 1] ? a : buf[i - 1];
	}

	return buf[n - 1];
}
