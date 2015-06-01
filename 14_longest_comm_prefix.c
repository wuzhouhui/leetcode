#include <string.h>
#include <stdlib.h>

static int commlen(const char *s1, const char *s2)
{
	int	i = 0;
	while (*s1 && *s2 && *s1 == *s2) {
		i++;
		s1++;
		s2++;
	}
	return(i);
}

char *longestCommonPrefix(char **strs, int strsSize)
{
	if (!strsSize) {
		return(strdup(""));
	}
	if (strsSize == 1)
		return(strdup(strs[0]));
	/* strsSize > 1 */
	int	max, ind, i, len;

	qsort(strs, strsSize, sizeof(char *), (int (*)(const void *, 
			const void *))strcmp);
	max = strlen(strs[0]);
	ind = 0;
	for (i = 0; i + 1 < strsSize; i++) {
		len = commlen(strs[i], strs[i + 1]);
		if (len < max) {
			max = len;
			ind = i;
		}
	}
	if (max == 0)
		return(strdup(""));
	return(strndup(strs[ind], max));
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%s\n", longestCommonPrefix(argv + 1, argc - 1));
	return(0);
}
