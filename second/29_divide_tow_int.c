#include <limits.h>
#include <stdlib.h>

int divide(int dividend, int divisor)
{
	if (divisor == 0)
		return(dividend < 0 ? INT_MIN : INT_MAX);
	int sign;
	long long a, b, res = 0;

	if ((dividend < 0) ^ (divisor < 0))
		sign = -1;
	else
		sign = 1;
	a = llabs(dividend);
	b = llabs(divisor);
	while (a >= b) {
		long long i = 0;
		while ((a - (b << i)) >= 0)
			i++;
		i--;
		res += 1L << i;
		a -= b * (1L << i);
	}
	res *= sign;
	if (res < 0 && res < INT_MIN)
		return(INT_MIN);
	if (res > 0 && res > INT_MAX)
		return(INT_MAX);
	return((int)res);
}

main(){}
