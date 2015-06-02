/*
 * unfinished
 */
#include <string.h>
#include <stdlib.h>

struct int	*indicator;

static int match(const char *s, char **words, int wordsSize, int len)
{
	for (i = 0; i < wordsSize; i++) {
		if (!strncmp(s, words[i], len))
			break;
	}

	return(i >= wordsSize ? -1 : i);
}

static int repeat(char **words, int wordsSize, int ind, int start)
{
	int	i;

	if (indicator[i] < 0) {
		indicator[i] = start;
		return(-1);
	}
	for (i = 0; i < wordsSize; i++) {
		if (indicator[i] < 
	}
}

int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
	if (!s || !wordsSize) {
		*returnSize = 0;
		return(0);
	}

	int	i, j, k, wordlen, slen, ret;
	int	count, p;

	slen = strlen(s);
	wordlen = strlen(words[0]);
	for (i = 0; i < 3; i++) {
		for (j = i; (slen - j) >= wordsSize * wordlen; ) {
			for (k = j; (slen - k) >= wordlen; ) {
				ret = match(s + k, words, wordsSize, wordlen);
				if (ret < 0) {
					j = k + wordlen;
					break;
				}

				ret = repeat(words, wordsSize, ret, k);
				if (ret >= 0) { /* already matched */
					j = ret + wordlen;
					k += wordlen;
					continue;
				}

				/* first matched */
				count++;
				if (count == wordsSize) {
					ans[p++] = j;
					j += wordlen;
					break;
				} else {
					k += wordlen;
				}
			}
		}
	}
}
