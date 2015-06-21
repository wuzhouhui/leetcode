#include <limits.h>

int divide(int dividend, int divisor)
{
	if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
		return(INT_MAX);

	long long m, n, res, i;

	m = (dividend > 0 ? dividend : -(long long)dividend);
	n = (divisor > 0 ? divisor : -(long long)divisor);
	res = 0;
	while (m >= n) {
		i = 0;
		while ((m - (n << i)) >= 0)
			i++;
		res += 1L << (i - 1);
		m -= n << (i - 1);
	}
	if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
		return((int)res);
	return((int)(-res));
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", divide(2147483647, 2));
	return(0);
}
