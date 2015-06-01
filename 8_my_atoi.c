#include <limits.h>

int myAtoi(char *str)
{
	if (!str || !str[0])
		return(0);

	long long res = 0;
	int	signe = 0;

	while (*str && (*str == ' ' || *str == '\t' || *str == '\r'
			|| *str == '\n'))
		str++;
	if (*str == 0)
		return(0);

	if (str[0] == '-') {
		signe = 1;
		str++;
	} else if (str[0] == '+') {
		str++;
	}
	while (*str && *str >= '0' && *str <= '9') {
		res = res * 10 + *str++ - '0';
		if (res > INT_MAX)
			break;
	}
	if (signe) {
		res = -res;
		if (res <= INT_MIN)
			res = INT_MIN;
	} else {
		if (res >= INT_MAX)
			res = INT_MAX;
	}
	return((int)res);
}

int main(void)
{}
