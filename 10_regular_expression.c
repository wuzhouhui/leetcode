#ifndef bool 
#define bool int 
#endif

bool isMatch(char *s, char *p)
{
	int	i;

	if (!p || !p[0]) {
		if (!s || !s[0])
			return(1);
		return(0);
	}

	if (p[0] == '.') {
		if (p[1] != '*') {
			if (!s || !s[0])
				return(0);
			return(isMatch(s + 1, p + 1));
		}
		/* p = ".*" */
		for (i = 0; ; i++) {
			if (!i) {
				if (isMatch(s, p + 2))
					return(1);
				continue;
			}
			if (s[i - 1]) {
				if (isMatch(s + i, p + 2))
					return(1);
				continue;
			}
			break;
		}
		return(0);
	}

	/* p[0] is alpha */

	if (p[1] != '*') {
		if (s[0] == p[0]) {
			return(isMatch(s + 1, p + 1));
		}
		return(0);
	}

	/* p[1] is '*' */
	for (i = 0; ; i++) {
		if (!i) {
			if (isMatch(s, p + 2))
				return(1);
			else
				continue;
		}
		/* i > 0 */
		if (s[i - 1] == p[0]) {
			if (isMatch(s + i, p + 2))
				return(1);
		} else {
			break;
		}
	}
	return(0);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", isMatch(argv[1], argv[2]));
	return(0);
}
