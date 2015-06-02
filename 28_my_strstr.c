#include <string.h>

int strStr(char *haystack, char *needle)
{
	if (!haystack || !needle)
		return(-1);

	int	l1, l2, i, j, k;

	l1 = strlen(haystack);
	l2 = strlen(needle);
	if (l1 < l2)
		return(-1);
	if (l2 == 0)
		return(0);
	for (i = 0; (l1 - i) >= l2; i++) {
		for (j = i, k = 0; needle[k]; j++, k++) {
			if (haystack[j] != needle[k])
				break;
		}
		if (needle[k] == 0)
			return(i);
	}
	return(-1);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", strStr(argv[1], argv[2]));
	return(0);
}
