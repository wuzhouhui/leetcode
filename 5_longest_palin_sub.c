#include <string.h>

static int pal(char *s, int start, int end, int *left)
{
	while (start >= 0 && s[end]) {
		if (s[start] != s[end])
			break;
		start--;
		end++;
	}
	*left = ++start;
	return(end - start);
}

char *longestPalindrome(char *s)
{
	if (!s)
		return(0);

	int	slen, ansleft, anslen, left, len;
	int	i;

	slen = strlen(s);
	if (!slen || slen == 1)
		return(strdup(s));
	
	ansleft = 0;
	anslen = 1;
	for (i = 0; i < slen; i++) {
		len = pal(s, i, i, &left);
		if (len > anslen) {
			anslen = len;
			ansleft = left;
		}
		if ((i + 1) < slen) {
			len = pal(s, i, i + 1, &left);
			if (len > anslen) {
				anslen = len;
				ansleft = left;
			}
		}
	}
	return(strndup(s + ansleft, anslen));
}

#include<stdio.h>

int main(int argc, char **argv)
{
	if (argc > 1)
		printf("%s\n", longestPalindrome(argv[1]));
	return(0);
}
