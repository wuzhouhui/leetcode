#include <stdlib.h>

int mySqrt(int x)
{
	if (x <= 0)
		return(0);

	long long l, u, m, t;

	l = 0;
	u = x / 2 + 1;
	while (l <= u) {
		m = (l + u) / 2;
		t = m * m;
		if (t == x)
			return((int)m);
		if (t < x)
			l = m + 1;
		else 
			u = m - 1;
	}
	return((int)u);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", mySqrt(2147395599));
	return(0);
}
