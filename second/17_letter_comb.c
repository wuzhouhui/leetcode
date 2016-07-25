#include <stdlib.h>
#include <string.h>

static char *tbl[] = {
	"",
	"", "abc", "def",
	"ghi", "jkl", "mno",
	"pqrs", "tuv", "wxyz",
};

static char **res;
static int p, maxp;
static char buf[512];

static void addans(int len)
{
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(res[0]));
	}
	res[p++] = strndup(buf, len);
}

static void do_comb(const char *digits, int lev)
{
	if (*digits == 0) {
		if (buf[0])
			addans(lev);
		return;
	}
	int i;
	if (tbl[*digits - '0'][0] == 0)
		do_comb(digits + 1, lev);
	else {
		for (i = 0; tbl[*digits - '0'][i]; i++) {
			buf[lev] = tbl[*digits - '0'][i];
			do_comb(digits + 1, lev + 1);
		}
	}
}

char **letterCombinations(char *digits, int *returnSize)
{
	p = maxp = 0;
	res = NULL;
	buf[0] = 0;
	do_comb(digits, 0);
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	char **strs = letterCombinations(argv[1], &i);
	while (i-- > 0)
		printf("%s\n", strs[i]);
}
