#include <string.h>
#include <stdlib.h>

char *convert(char *s, int numRows)
{
	if (!s)
		return(0);

	char *res;
	int i, j, l, step1, step2, flag, p, k;


	l = strlen(s);
	if (l <= 2 || numRows == 1)
		return(strdup(s));
	res = malloc(l + 1);
	k = 2 * numRows - 2;
	p = 0;
	for (i = 0; i < numRows && i < l; i++) {
		if (i == 0 || i == (numRows - 1)) {
			for (j = i; j < l; j += k)
				res[p++] = s[j];
			continue;
		}
		step1 = k - i * 2;
		step2 = k - step1;
		flag = 1;
		for (j = i; j < l;) {
			res[p++] = s[j];
			if (flag) {
				flag = 0;
				j += step1;
			} else {
				flag = 1;
				j += step2;
			}
		}
	}
	res[p] = 0;
	return(res);
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	printf("%s\n", convert(argv[1], atoi(argv[2])));
	return(0);
}
