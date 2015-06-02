#include <stdlib.h>
#include <string.h>

#define STEP 16

static int	p, maxp;
static char	**res;

static void add_ans(const char *s)
{
	if (!res) {
		maxp = STEP;
		p = 0;
		res = malloc(maxp * sizeof(char *));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(char *));
	}
	res[p++] = strdup(s);
}

static int avail(const char *s, int n)
{
	int	i, l;
	l = strlen(s);
	for (i = 0; *s; s++) {
		if (*s == '(')
			i++;
		else 
			i--;
		if (i < 0)
			return(0);
	}
	if ((2 * n - l) < i)
		return(0);
	return(1);
}

static void do_gen(char *s, int n)
{
	int	l;

	l = strlen(s);
	if (!l) {
		s[0] = '('; s[1] = 0;
		do_gen(s, n);
	} else if (l == (2 * n)) {
		add_ans(s);
	} else {
		s[l] = '('; s[l + 1] = 0;
		if (avail(s, n))
			do_gen(s, n);
		s[l] = ')'; s[l + 1] = 0;
		if (avail(s, n))
			do_gen(s, n);
		s[l] = 0;
	}
}

char **generateParenthesis(int n, int *returnSize)
{
	if (!n) {
		*returnSize = 0;
		return(0);
	}

	res = 0;
	p = 0;

	char	*s = malloc((2 * n + 1) * sizeof(char));
	s[0]	 = 0;
	do_gen(s, n);
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	n;
	char	**res;
	res = generateParenthesis(1, &n);
	return(0);
}
