#include <stdlib.h>

int singleNumber(int A[], int n)
{
	if (!A || !n)
		abort();
	if (n == 1)
		return(A[0]);

	int result, i;

	for (result = 0, i = 0; i < n; i++) {
		result ^= A[i];
	}

	return(result);
}
