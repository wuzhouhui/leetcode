#include <stdlib.h>

int singleNumber(int A[], int n)
{
	if (!A || !n)
		abort();
	if (n == 1)
		return(A[0]);

	int	ones, twos, common;
	int	i;

	for (ones = twos = i = 0; i < n; i++) {
		twos |= ones & A[i];
		ones ^= A[i];
		common = ~(ones & twos);
		ones &= common;
		twos &= common;
	}

	return(ones);
}

void main(void)
{}
