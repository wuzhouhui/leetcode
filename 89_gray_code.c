#include <stdint.h>
#include <stdlib.h>

static int *res, p, maxp;

static void add_ans(uint32_t n)
{
	if (!res) {
		maxp = 8;
		p = 0;
		res = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(int));
	}
	res[p++] = (int)n;
}

int *grayCode(int n, int *returnSize)
{
	if (!n) {
		*returnSize = 1;
		res = malloc(sizeof(int));
		res[0] = 0;
		return(res);
	}

	uint32_t i, j;

	res = 0;
	j = (uint32_t)1 << n;
	for (i = 0; i < j; i++)
		add_ans((i >> 1) ^ i);

	*returnSize = p;
	return(res);
}

#include <stdio.h>
int main(void)
{
	int *res, n;
	res = grayCode(1, &n);
	return(0);
}
