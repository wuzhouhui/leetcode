int trailingZeroes(int n)
{
	if (n < 5)
		return 0;

	int	c;

	c = 0;
	while (n > 0) {
		n /= 5;
		c += n;
	}

	return c;
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", trailingZeroes(10));
	return 0;
}
