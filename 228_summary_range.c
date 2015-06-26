#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STEP	8

static char **res;
static int p, maxp;

static void add_ans(int *nums, int start, int end)
{
	static char	buf[32];

	if (res == 0) {
		maxp = STEP;
		p = 0;
		res = malloc(maxp * sizeof(char *));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(char *));
	}
	if (start == end)
		sprintf(buf, "%d", nums[start]);
	else 
		sprintf(buf, "%d->%d", nums[start], nums[end]);
	res[p++] = strdup(buf);
}

char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
	if (numsSize == 0) {
		*returnSize = 0;
		return(0);
	}

	int	start, i;

	res = 0;
	start = 0;
	for (i = 1; i < numsSize; i++) {
		if (nums[i] == nums[i - 1] + 1)
			continue;
		add_ans(nums, start, i - 1);
		start = i;
	}
	add_ans(nums, start, numsSize - 1);
	*returnSize = p;
	return(res);
}

int main(void)
{
	int	x[] = { 0, 5};
	char	**res;
	int	i;
	res = summaryRanges(x, sizeof(x) / sizeof(int), &i);
	return(0);
}
