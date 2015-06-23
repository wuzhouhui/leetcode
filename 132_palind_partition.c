#include <string.h>
#include <strings.h>

int minCut(char *s)
{
	int	len, i, j;

	if (!s || (len = strlen(s)) <= 1)
		return(0);

	int	cuts[len];
	char	is_palind[len][len];

	bzero(is_palind, sizeof(is_palind));
	for (i = 0; i < len; i++)
		cuts[i] = i;

	for (i = 0; i < len; i++) {
		for (j = 0; j <= i; j++) {
			if (!(s[j] == s[i] &&
				((i - j) <= 1
				 || is_palind[j + 1][i - 1])))
				continue;
			is_palind[j][i] = 1;
			if (j == 0)
				cuts[i] = 0;
			else 
				cuts[i] = (cuts[j - 1] + 1) < cuts[i] ?
					(cuts[j - 1] + 1) : cuts[i];
		}
	}
	i = cuts[len - 1];
	return(i);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", minCut(argv[1]));
	return(0);
}
