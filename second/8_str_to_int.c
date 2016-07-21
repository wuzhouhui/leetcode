#include <ctype.h>
#include <limits.h>

int myAtoi(char *s)
{
	long res = 0;
	int sign = 1;
	while (*s && isblank(*s))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-') {
		sign = -1;
		s++;
	}
	while (*s && isdigit(*s)) {
		res = res * 10 + *s - '0';
		long t = res * sign;
		if (t < INT_MIN || t > INT_MAX)
			break;
		else
			s++;
	}
	res *= sign;
	if (res < INT_MIN)
		return(INT_MIN);
	else if (res > INT_MAX)
		return(INT_MAX);
	else
		return((int)res);
}

main(){}
