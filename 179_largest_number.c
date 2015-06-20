#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int cmpfun(const void *a, const void *b)
{
	static char buf1[32], buf2[32];
	int	i;

	sprintf(buf1, "%d%d", *(int *)a, *(int *)b);
	sprintf(buf2, "%d%d", *(int *)b, *(int *)a);
	for (i = 0; buf1[i] && buf2[i]; i++) {
		if (buf1[i] > buf2[i])
			return(-1);
		else if (buf1[i] < buf2[i])
			return(1);
	}
	return(0);
}

char *largestNumber(int *nums, int numsSize)
{
	static char buf[16];
	int	i, total, len;
	char	*res;

	if (!numsSize) {
		return(strdup("0"));
	}
	qsort(nums, numsSize, sizeof(int), cmpfun);
	res	= 0;
	total	= 1;
	for (i = 0; i < numsSize; i++) {
		len = sprintf(buf, "%d", nums[i]);
		if (!res) {
			res = malloc((len + 1));
			res[0] = 0;
		} else {
			res = realloc(res, total + len);
		}
		strcat(res, buf);
		if (i == 0 && nums[i] == 0)
			break;
		total += len;
	}
	return(res);
}

int main(void)
{
	int	x[] = { 824, 938, 1399, 5607, 6973, 5703, 9609, 4398,
		8247};
	printf("%s\n", largestNumber(x, sizeof(x) / sizeof(int)));
	return(0);
}
