#include <string.h>

#define DIFF ('a' - 'A')
#ifndef bool 
#define bool int 
#endif

bool isPalindrome(char *s)
{
	int	i, j, l;

	if ((l = strlen(s)) <= 1)
		return(1);

	j = -1;
	for (i = 0; i < l; i++) {
		if (!((s[i] >= 'a' && s[i] <= 'z') ||
				(s[i] >= 'A' && s[i] <= 'Z') ||
				(s[i] >= '0' && s[i] <= '9')))
			continue;
		s[++j] = s[i];
	}
	l = j + 1;
	for (i = 0; i <= (l / 2 - 1); i++) {
		j = l - i - 1;
		if ((s[i] == s[j]) || 
				((s[i] + DIFF) == s[j]) ||
				(s[i] == (s[j] + DIFF)))
			continue;
		else
			return(0);
	}
	return(1);
}
#include <stdio.h>


int main(int argc, char **argv)
{
	printf("%d\n", isPalindrome(argv[1]));
	return(0);
}
