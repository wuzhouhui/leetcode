#include <string.h>

static int dist[512][512];

int minDistance(char *word1, char *word2)
{
	int	l1, l2, i, j;
	int	ins, del, rep;

	if (!word1 && !word2)
		return(0);
	if (!word1)
		return(strlen(word2));
	if (!word2)
		return(strlen(word1));
	l1 = strlen(word1);
	l2 = strlen(word2);

	for (i = 0; i <= l1; i++)
		dist[i][0] = i;
	for (j = 0; j <= l2; j++)
		dist[0][j] = j;
	for (i = 0; i < l1; i++) {
		for (j = 0; j < l2; j++) {
			if (word1[i] == word2[j]) {
				dist[i+1][j+1] = dist[i][j];
			} else {
				ins = dist[i+1][j] + 1;
				del = dist[i][j+1] + 1;
				rep = dist[i][j] + 1;
				dist[i+1][j+1] = (ins < del ? ins : del);
				dist[i+1][j+1] = (dist[i+1][j+1] < rep ?
					dist[i+1][j+1] : rep);
			}
		}
	}
	return(dist[l1][l2]);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", minDistance(argv[1], argv[2]));
	return(0);
}
