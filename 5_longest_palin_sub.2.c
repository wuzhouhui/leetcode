#include <string.h>

static int pal(const char *s, int l, int r, int *start)
{
	int len = 0;
	while (l >= 0 && s[r] && (s[l] == s[r])) {
		len += 2;
		l--, r++;
	}
	*start = l + 1;
	return(len);
}

char *longestPalindrome(char *s)
{
	if (s == NULL)
		return(strdup(""));
	if (s[0] == 0 || s[1] == 0)
		return(strdup(s));
	int max = 0;
	int start;
	int i;

	for (i = 0; s[i]; i++) {
		int t;
		int l = pal(s, i - 1, i + 1, &t) + 1;
		if (l > max) {
			max = l;
			start = t;
		}
		l = pal(s, i, i + 1, &t);
		if (l > max) {
			max = l;
			start = t;
		}
	}
	return(strndup(s + start, max));
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", longestPalindrome(argv[1]));
	return(0);
}
