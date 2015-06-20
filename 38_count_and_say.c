#include <stdlib.h>

#define STEP	8

static char *res;
static int p, maxp;

static void add_one(char c)
{
	if (!res) {
		maxp = STEP;
		p = 0;
		res = malloc(maxp);
	}
	if ((p + 1) >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp);
	}
	res[p++] = c;
}

char *countAndSay(int n)
{
	int	i, j, k;
	char	*prev, c;

	res = 0;
	for (i = 1; i <= n; i++) {
		if (i == 1) {
			add_one('1');
			res[p] = 0;
			prev = res;
			continue;
		}
		res = 0;
		j = 0;
		while (prev[j]) {
			c = prev[j];
			j++;
			for (k = 1; prev[j] && prev[j] == prev[j-1]; j++)
				k++;

			add_one(k + '0');
			add_one(c);
		}
		free(prev);
		res[p] = 0;
		prev = res;
	}
	return(res);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int	n = atoi(argv[1]);
	printf("%s\n", countAndSay(n));
	return(0);
}
