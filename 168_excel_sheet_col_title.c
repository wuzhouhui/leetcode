#include <string.h>
#include <stdlib.h>

char *convertToTitle(int n)
{
	char *buf;

	if (n <= 0)
		return NULL;
	if (n <= 26) {
		buf = malloc(2);
		buf[0] = 'A' + n - 1;
		buf[1] = 0;
		return buf;
	}

	int	p, r, l;
	buf = malloc(1);
	buf = 0;
	p   = 0;
	while (n > 0) {
		r = n % 26;
		n = (n - 1) / 26;

		buf = realloc(buf, sizeof(buf) + 1);
		if (r == 0)
			buf[p++] = 'Z';
		else 
			buf[p++] = 'A' + r - 1;
	}
	buf[p] = 0;

	for (l = strlen(buf), r = 0; r < l / 2; r++) {
		p = buf[l - 1 - r];
		buf[l - 1 - r] = buf[r];
		buf[r] = p;
	}

	return buf;
}

#include <stdio.h>

int main(void)
{
	char	*ptr;

	printf("%s\n", (ptr = convertToTitle(701)));
	free(ptr);
	return 0;
}
