#include <string.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
	return(strcmp(*(char **)a, *(char **)b));
}

static int commlen(const char *a, const char *b)
{
	int l = 0;
	while (*a && *a++ == *b++)
		l++;
	return(l);
}

char *longestCommonPrefix(char **strs, int strsSize)
{
	if (strsSize <= 0)
		return(strdup(""));

	int min, i;

	qsort(strs, strsSize, sizeof(strs[0]), cmp);
	min = strlen(strs[0]);
	for (i = 1; i < strsSize; i++) {
		int t = commlen(strs[i - 1], strs[i]);
		if (t <= 0) 
			return(strdup(""));
		if (t < min)
			min = t;
	}
	return(strndup(strs[0], min));
}

int main(void)
{
	return(0);
}
