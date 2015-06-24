void reverseWords(char *s)
{
	if (!s || !s[0])
		return;

	int	i, j, l;
	char	prev;

	prev = ' ';
	for (l = -1, i = 0; s[i]; i++) {
		if (s[i] != ' ') {
			s[++l] = s[i];
			prev = s[i];
			continue;
		}
		/* s[i] == ' ' */
		if (prev == ' ') {
			continue;
		} else {
			s[++l] = ' ';
			prev = ' ';
		}
	}

	if (s[l] == ' ')
		s[l] = 0;
	else
		s[++l] = 0;
	
	for (i = 0; i < l / 2; i++) {
		prev = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = prev;
	}

	for (i = 0; s[i]; ) {
		if (s[i] == ' ') {
			i++;
			continue;
		}
		j = i;
		while (s[i] && s[i] != ' ')
			i++;
		/* reverse s[j, i - 1] */
		for (l = j; l < j + (i - j) / 2; l++) {
			prev = s[l];
			s[l] = s[i - l + j - 1];
			s[i - l + j - 1] = prev;
		}
	}
}

#include <stdio.h>

int main(int argc, char **argv)
{
	reverseWords(argv[1]);
	printf("%s\n", argv[1]);
	return(0);
}
