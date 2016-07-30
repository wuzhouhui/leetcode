#include <string.h>

int strStr(char *haystack, char *needle)
{
	if (!haystack || !needle)
		return(-1);
	if (needle[0] == 0)
		return(0);

	int l1 = strlen(haystack);
	int l2 = strlen(needle);
	int i, j;
	for (i = 0; i <= l1 - l2; i++) {
		for (j = 0; j < l2 && haystack[i + j] == needle[j]; j++)
			;
		if (j >= l2)
			return(i);
	}
	return(-1);
}

main(){}
