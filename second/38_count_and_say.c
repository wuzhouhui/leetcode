#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *countAndSay(int n)
{
	static char *buf1, *buf2;
	int cnt, i, j, p, maxp = 512;
	char next;

	buf1 = malloc(maxp * sizeof(*buf1));
	buf2 = malloc(maxp * sizeof(*buf2));
	strcpy(buf1, "1");
	for (i = 2; i <= n; i++) {
		p = j = 0;
		while (buf1[j]) {
			cnt = 1;
			next = buf1[j++];
			while (buf1[j] && buf1[j] == next) {
				cnt++;
				j++;
			}
			if (p >= maxp / 2) {
				maxp *= 2;
				buf1 = realloc(buf1, maxp * sizeof(*buf1));
				buf2 = realloc(buf2, maxp * sizeof(*buf2));
			}
			p += sprintf(buf2 + p, "%d%c", cnt, next);
		}
		strcpy(buf1, buf2);
	}
	free(buf2);
	return(buf1);
}

main(){}
