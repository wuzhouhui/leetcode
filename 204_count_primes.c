int countPrimes(int n)
{
	if (n < 2)
		return(0);

	int	count, i, j;
	char	x[n];

	for (i = 2; i < n; i++) 
		x[i] = 1;
	for (i = 2; i * i < n; i++) {
		if (!x[i])
			continue;
		for (j = i * i; j < n; j += i)
			x[j] = 0;
	}
	for (count = 0, i = 2; i < n; i++)
		if (x[i])
			count++;
	return(count);
}
int main(void)
{

}
