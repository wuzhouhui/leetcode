#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows)
{
	if (numRows <= 1)
		return(strdup(s));
	int len = strlen(s);
	int constnum = 2 * numRows - 2;
	char *res = malloc((len + 1) * sizeof(*res));
	int p = 0, i, j, step, t;

	for (i = 0; i < numRows; i++) {
		if (i == 0 || i == numRows - 1) {
			for (j = i; j < len; j += constnum)
				res[p++] = s[j];
			continue;
		}
		step = constnum - 2 * i;
		for (j = i; j < len; j += constnum) {
			res[p++] = s[j];
			t = j + step;
			if (t < len)
				res[p++] = s[t];
		}
	}
	res[p] = 0;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", convert(argv[1], atoi(argv[2])));
	return(0);
}
