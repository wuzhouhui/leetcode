#include <string.h>
#include <stdlib.h>

static char buf[512];
static char **res;
static int p, maxp;

static void addans(int n)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = strndup(buf, n);
}

static int avail(int n)
{
	int c = 0;
	while (n-- > 0) {
		if (buf[n] == ')') {
			c++;
			continue;
		}
		if (--c < 0)
			return(0);
	}
	return(c == 0);
}

static void do_gen(int n, int level)
{
	if (level >= n) {
		if (avail(n))
			addans(n);
		return;
	}
	buf[level] = '(';
	do_gen(n, level + 1);
	buf[level] = ')';
	do_gen(n, level + 1);
}

char **generateParenthesis(int n, int *returnSize)
{
	res = NULL;
	p = maxp = 0;
	n <<= 1;
	do_gen(n, 0);
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int n;
	char **res = generateParenthesis(3, &n);
	while (n-- > 0)
		printf("%s\n", res[n]);
	return(0);
}
