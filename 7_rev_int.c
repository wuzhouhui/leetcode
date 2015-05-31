#include <limits.h>

int reverse(int x)
{
	long long longx = (x >= 0 ? x : -((long long)x));
	long long longres = 0;

	while (longx) {
		longres = longres * 10 + longx % 10;
		longx /= 10;
	}
	if (x < 0)
		longres = -longres;
	if (longres > INT_MAX || longres < INT_MIN)
		return(0);
	return((int)longres);
}

int main(void)
{

}
