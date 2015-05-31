#include <limits.h>

#ifndef bool 
#define bool int 
#endif

bool isPalindrome(int x)
{
	if (x < 0)
		return(0);

	long long longx;
	int	n;

	for (n = x, longx = 0; n > 0; n /= 10)
		longx = longx * 10 + n % 10;
	if (longx > INT_MAX || longx != x)
		return(0);
	return(1);
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", isPalindrome(1231));
	return(0);
}
