static double do_pow(double x, int n);

double myPow(double x, int n)
{
	int	t;
	double res;

	t = n;
	if (t < 0)
		t = -t;
	res = do_pow(x, t);
	if (n < 0)
		return(1.0 / res);
	return(res);
}
static double do_pow(double x, int n)
{
	if (n == 0)
		return(1.0);
	if (n == 1)
		return(x);
	if (n % 2)
		return(x * myPow(x, n - 1));

	/* n is even */
	double t = myPow(x, n / 2);
	return(t * t);
}

#include <stdio.h>

int main(void)
{
	printf("%lf\n", myPow(2.0, -3));
	return(0);
}
