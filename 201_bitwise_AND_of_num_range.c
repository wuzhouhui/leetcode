int rangeBitwiseAnd(int m, int n)
{
	if (m == n || !m)
		return(m);

	int	res, i, t;

	res = 0;
	n -= m;
	for (i = 0; i < 31; i++) {
		t = 1 << i;   /* t = 2^i */
		res |= m & t;
		if (n / (t - (m & (t - 1))))
			res &= ~t;
	}
	return(res);
}

int main(void)
{}
