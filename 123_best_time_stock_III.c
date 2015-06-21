
int maxProfit(int *prices, int pricesSize)
{
	if (pricesSize <= 1)
		return(0);
	int	i, max_to_i[pricesSize], max_from_i[pricesSize];
	int	min_max, t;

	min_max = max_to_i[0] = 0;
	for (i = 1; i < pricesSize; i++) {
		if (prices[i] < prices[min_max])
			min_max = i;
		t = prices[i] - prices[min_max];
		max_to_i[i] = (max_to_i[i-1] > t ? max_to_i[i-1] : t);
	}
	max_from_i[pricesSize - 1] = 0;
	min_max = pricesSize - 1;
	for (i = pricesSize - 2; i >= 0; i--) {
		if (prices[i] > prices[min_max])
			min_max = i;
		t = prices[min_max] - prices[i];
		max_from_i[i] = (max_from_i[i+1] > t ? max_from_i[i+1] : t);
	}

	min_max = 0;
	for (i = 0; i < pricesSize; i++) {
		t = max_to_i[i] + max_from_i[i];
		if (t > min_max)
			min_max = t;
	}
	return(min_max);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 3, 3, 5, 0, 0, 3, 1, 4 };
	printf("%d\n", maxProfit(x, sizeof(x)/sizeof(x[0])));
	return(0);
}
