/* runtime error */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SINGBUFSZ	1024

static int cmp(int, int);

char *largestNumber(int *num, int n)
{
	int	i, j, k, len, bufsz, tmp;
	static char singbuf[SINGBUFSZ];
	char	*buf = malloc(1);

	buf[0] = 0;
	bufsz  = 0;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = k + 1; j < n; j++) {
			if (cmp(num[j], num[k]) > 0)
				k = j;
		}
		if (k != i) {
			tmp	= num[i];
			num[i]	= num[k];
			num[k]	= tmp;
		}

		if (i == 0 && num[i] == 0)
			break;
		sprintf(singbuf, "%d", num[i]);
		len = strlen(singbuf);
		bufsz += len;
		buf = realloc(buf, bufsz);
		strncat(buf, singbuf, len);
	}
	sprintf(singbuf, "%d", num[i]);
	len = strlen(singbuf);
	bufsz += len;
	buf = realloc(buf, bufsz);
	strncat(buf, singbuf, len);

	return buf;
}

static int cmp(int i, int j) 
{
	static char bufi[SINGBUFSZ], bufj[SINGBUFSZ];
	int	k, leni, lenj;

	sprintf(bufi, "%d", i);
	sprintf(bufj, "%d", j);
	leni = strlen(bufi);
	lenj = strlen(bufj);

	if ((k = strncmp(bufi, bufj, (leni < lenj ? leni : lenj))) != 0)
		return k;

	/* same prefix */
	if (leni == lenj)
		return 0;

	for (k = 0; k < leni; k++)
		bufi[k + leni] = bufi[k];
	bufi[k + leni] = 0;
	for (k = 0; k < lenj; k++)
		bufj[k + lenj] = bufj[k];
	bufj[k + lenj] = 0;
	return strcmp(bufi, bufj);
}
