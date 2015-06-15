int maxProfit(int *prices, int pricesSize)
{
	if (!pricesSize || pricesSize == 1)
		return(0);
	
	int min, maxdiff, i, t;

	maxdiff = min = 0;
	for (i = 1; i < pricesSize; i++) {
		if (prices[i] < prices[min])
			min = i;
		t = prices[i] - prices[min];
		if (t > maxdiff)
			maxdiff = t;
	}
	return(maxdiff);
}

int main(void)
{

}
