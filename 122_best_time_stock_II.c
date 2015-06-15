
int maxProfit(int *prices, int pricesSize)
{
	if (!pricesSize || pricesSize == 1)
		return(0);

	int	profit, i, buy, sell;

	profit = 0;
	buy = 0;
	sell = 0;
	for (i = 1; i < pricesSize; i++) {
		if (prices[i] >= prices[sell]) {
			sell++;
		} else {
			profit += prices[sell] - prices[buy];
			buy = sell = i;
		}
	}
	profit += prices[sell] - prices[buy];
	return(profit);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 1, 2, };
	printf("%d\n", maxProfit(x, sizeof(x)/sizeof(int)));
	return(0);
}
