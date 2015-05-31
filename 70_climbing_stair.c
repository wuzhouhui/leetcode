
int climbStairs(int n)
{
	if (!n || n == 1 || n == 2)
		return(n);

	int	x[n + 1], i;

	for (i = 1; i <= n; i++) {
		if (i == 1 || i == 2) {
			x[i] = i;
			continue;
		}
		x[i] = x[i - 1] + x[i - 2];
	}
	return(x[n]);
}

int main(void)
{}
