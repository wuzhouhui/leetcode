/*
 * 704 ms, it's too slow although accepted,
 * 4 ms for other's answer.
 */
#include <stdlib.h>
#include <string.h>

char *shortestPalindrome(char *s)
{
	if (!s)
		return(strdup(""));

	int	slen, u, i, j, k, start;
	int	t, flag, maxlen;
	char	*res;

	if ((slen = strlen(s)) == 1)
		return(strdup(s));

	u = slen / 2 - 1;
	if (slen % 2)
		u++;
	maxlen = 0;
	for (i = 0; i <= u; i++) {
		for (t = 1, j = -1, k = 1; (i + j) >= 0; j--, k++) {
			if (s[i + j] == s[i + k])
				t += 2;
			else
				break;
		}
		if ((i + j) < 0 && t > maxlen) {
			maxlen = t;
			start = i;
			flag = 0;
		}

		if (i == u && (slen % 2))
			continue;
		for (t = 0, j = i, k = i + 1; j >= 0; j--, k++) {
			if (s[j] == s[k])
				t += 2;
			else 
				break;
		}
		if (j < 0 && t > maxlen) {
			maxlen = t;
			start = i;
			flag = 1;
		}
	}

	res = malloc(slen + slen - maxlen + 8);
	k = 0;
	if (flag) {
		for (j = slen - 1; j > 2 * start + 1; j--)
			res[k++] = s[j];
		res[k] = 0;
	} else {
		for (j = slen - 1; j > 2 * start; j--)
			res[k++] = s[j];
		res[k] = 0;
	}
	strcat(res, s);
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", shortestPalindrome(argv[1]));
	return(0);
}
