
int majorityElement(int num[], int n)
{
	if (n == 1)
		return num[0];

	int	i, c, ind;

	for (ind = 0, c = 1, i = 1; i < n; i++) {
		if (num[ind] == num[i])
			c++;
		else
			c--;
		if (c == 0) {
			ind = i;
			c = 1;
		}
	}

	return num[ind];
}
