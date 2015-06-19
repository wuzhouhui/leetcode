/*
 * time limit exceeded
 */
#include <string.h>

#ifndef bool 
#define bool int 
#endif

bool isMatch(char *s, char *p)
{
	int	i;
	int	slen, plen;

	if (!s) {
		if (!p || !p[0])
			return(1);
	}

	if (!p || !p[0]) {
		if (!s || !s[0])
			return(1);
		else 
			return(0);
	}

	slen = strlen(s);
	plen = strlen(p);
	for (i = slen - 1; i >= 0; i--) {
		if (p[i] != '?' && p[i] != '*' && p[i] != s[i])
			return(0);
	}

	switch (*p) {
	case '?':
		if (!s || !s[0])
			return(0);
		else 
			return(isMatch(s + 1, p + 1));
		break;
	case '*':
		if (!s)
			return(isMatch(s, p + 1));
		for (i = 0; s[i]; i++) {
			if (isMatch(s + i, p + 1))
				return(1);
		}
		return(isMatch(s + i, p + 1));
		break;
	default:
		if (!s)
			return(0);
		if (s[0] != p[0])
			return(0);
		return(isMatch(s + 1, p + 1));
	}
	return(0);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", isMatch(argv[1], argv[2]));
	return(0);
}
