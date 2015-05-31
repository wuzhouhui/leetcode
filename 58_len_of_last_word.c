#include <string.h>

int lengthOfLastWord(char *s)
{
	int	len;
	int	i, l;

	if (!s || (len = strlen(s)) == 0)
		return(0);
	

	for (i = len - 1; i >= 0 && s[i] == ' '; i--)
		;
	if (i < 0)
		return(0);
	for (len = i - 1; len >= 0 && s[len] != ' '; len--)
		;
	return(i - len);
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", lengthOfLastWord("hello world"));
	return(0);
}
