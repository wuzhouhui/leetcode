#define bool int

bool isPowerOfTwo(int n)
{
	int	i, m = sizeof(int) * 8;
	int	t;

	for (i = 0; i < m; i++) {
		t = 1 << i;
		if (n == t)
			return(1);
		if (n < t)
			return(0);
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", isPowerOfTwo(1));
	return(0);
}
