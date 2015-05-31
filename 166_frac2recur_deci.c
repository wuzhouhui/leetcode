/* runtime_error */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STEP	128

char *fractionToDecimal(int numerator, int denominator)
{
	char	*buf;
	int	r;
	int	*hash;
	int	bufsz, p;

	if (!numerator) {
		buf = malloc(2);
		buf[0] = '0';
		buf[1] = 0;
		return(buf);
	}
	if (!denominator)
		return(NULL);

	bufsz = STEP;
	p = 0;
	buf = malloc(bufsz + 1);

	if (numerator * denominator < 0)
		*(buf + p++) = '-';
	if (numerator < 0)
		numerator = -numerator;
	if (denominator < 0)
		denominator = -denominator;
	r = numerator % denominator;
	numerator /= denominator;
	sprintf(buf + p, "%d", numerator);
	p = strlen(buf);
	if (!r)
		return(buf);
	*(buf + p++) = '.';
	hash = malloc(sizeof(int) * denominator);
	memset(hash, 0xff, sizeof(int) * denominator);

	while (1) {
		numerator = (r *= 10);
		numerator /= denominator;
		if (p >= (bufsz - 1)) {
			bufsz += STEP;
			buf = realloc(buf, bufsz);
		}
		*(buf + p++) = '0' + numerator;
		r %= denominator;
		if (!r)
			break;
		if (hash[r] < 0) {
			hash[r] = p - 1;
		} else {
			p--;
			*(buf + p++) = ')';
			*(buf + p) = 0;
			while (p >= hash[r]) {
				*(buf + p + 1) = *(buf + p);
				p--;
			}
			*(buf + p + 1) = '(';
			free(hash);
			return(buf);
		}
	}
	*(buf + p++) = 0;
	free(hash);
	return(buf);
}

int main(void)
{
	int	n, m;
	char	*p;
	n = 1;
	m = 214748364;
	printf("%s\n", p = fractionToDecimal(n, m));
	free(p);
	return(0);
}
