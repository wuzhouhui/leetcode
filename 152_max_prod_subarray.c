#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int maxProduct(int A[], int n)
{
	if (!A || !n)
		return(0);
	if (n == 1)
		return(A[0]);


	int	cur_max, cur_min, glo_max;
	int	i, tmp;

	cur_max = cur_min = glo_max = A[0];
	for (i = 1; i < n; i++) {
		tmp = cur_max;
		cur_max = max(A[i], max(cur_max * A[i], cur_min * A[i]));
		cur_min = min(A[i], min(tmp * A[i], cur_min * A[i]));
		glo_max = max(glo_max, cur_max);
	}
	return(glo_max);
}

#include <stdio.h>

int main(void)
{
	int a[] = { 2, 3, -2 , 4 };
	printf("%d\n", maxProduct(a, sizeof(a) / sizeof(int)));
	return(0);
}
