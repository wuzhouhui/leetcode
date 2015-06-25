/*
 * time limit exceeded.
int candy(int *ratings, int ratingsSize)
{
	if (!ratingsSize || ratingsSize == 1)
		return(ratingsSize);

	int	candynum[ratingsSize], i, j;

	for (i = 0; i < ratingsSize; i++) {
		if (i == 0) {
			candynum[i] = 1;
			continue;
		}
		if (ratings[i] == ratings[i - 1]) {
			candynum[i] = candynum[i - 1];
			continue;
		}
		if (ratings[i] > ratings[i - 1]) {
			candynum[i] = candynum[i - 1] + 1;
			continue;
		}

		if (candynum[i] = candynum[i - 1] - 1)
			continue;
		candynum[i] = 1;
		for (j = i - 1; j >= 0; j--) {
			candynum[j]++;
			if (j == 0 || ratings[j - 1] < ratings[j])
				break;
		}
	}

	for (i = 1; i < ratingsSize; i++)
		candynum[0] += candynum[i];
	return(candynum[0]);
}
*/

int candy(int *ratings, int ratingsSize)
{
	if (!ratingsSize || ratingsSize == 1)
		return(ratingsSize);

	int	candynum[ratingsSize], i;

	candynum[0] = 1;
	for (i = 1; i < ratingsSize; i++) {
		if (ratings[i] > ratings[i - 1])
			candynum[i] = candynum[i - 1] + 1;
		else 
			candynum[i] = 1;
	}

	for (i = ratingsSize - 2; i >= 0; i--) {
		if (ratings[i] > ratings[i + 1]
				&& candynum[i] <= candynum[i + 1])
			candynum[i] = candynum[i + 1] + 1;
	}
	for (i = 1; i < ratingsSize; i++)
		candynum[0] += candynum[i];
	return(candynum[0]);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 1, 2, 2, };
	printf("%d\n", candy(x, sizeof(x) / sizeof(int)));
	return(0);
}
