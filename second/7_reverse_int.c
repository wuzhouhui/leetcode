#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int reverse(int x)
{
	static char buf[32];
	int i, j;

	sprintf(buf, "%d", x);
	i = (x < 0 ? 1 : 0);
	j = strlen(buf) - 1;
	while (i < j) {
		int t = buf[i];
		buf[i] = buf[j];
		buf[j] = t;
		i++, j--;
	}
	long t = atol(buf);
	if (t < 0 && t < INT_MIN || t > 0 && t > INT_MAX)
		t = 0;
	return((int)t);
}

int main(int argc, char *argv[])
{
	printf("%d\n", reverse(atoi(argv[1])));
	return(0);
}
