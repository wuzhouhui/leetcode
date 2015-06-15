#include <stdlib.h>
#include <string.h>

#ifndef bool 
#define bool int
#endif

#define DIFF ('a' - 'A')

bool isPalindrome(char *s)
{
	int	i, j, l;
	char	*sptr;
	if ((l = strlen(s)) <= 1)
		return(1);

	sptr = malloc(l);
	for (i = j = 0; i < l; i++) {
		if (!((s[i] >= 'a' && s[i] <= 'z') ||
				(s[i] >= 'A' && s[i] <= 'Z') ||
				(s[i] >= '0' && s[i] <= '9')))
			continue;
		sptr[j++] = s[i];
	}
	l = j;
	for (i = 0; i <= (l / 2 - 1); i++) {
		j = l - i - 1;
		if ((sptr[i] == sptr[j]) || 
				((sptr[i] + DIFF) == sptr[j]) ||
				(sptr[i] == (sptr[j] + DIFF)))
			continue;
		else {
			free(sptr);
			return(0);
		}
	}
	free(sptr);
	return(1);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", isPalindrome(argv[1]));
	return(0);
}
