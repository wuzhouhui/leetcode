/*
 * wrong answer.
 */
#include <strings.h>
#include <stdlib.h>

static int all_cop(char *ocp, int len)
{
	while (len-- > 0)
		if (ocp[len] == 0)
			return(0);
	return(1);
}

void solve(char **board, int boardRowSize, int boardColSize)
{
	if (boardRowSize <= 1 || boardColSize <= 1)
		return;

	int	i, j, len;
	int	up, down, left, right;
	char	*ocp;

	len = boardRowSize > boardColSize ? boardRowSize : boardColSize;
	ocp = malloc(len);
	up = down = left = right = -1;

	bzero(ocp, len);
	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] == 'X')
				ocp[j] = 1;
		}
		if (all_cop(ocp, boardColSize)) {
			up = i;
			break;
		}
	}
	bzero(ocp, len);
	for (i = boardRowSize - 1; i >= 0; i--) {
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] == 'X')
				ocp[j] = 1;
		}
		if (all_cop(ocp, boardColSize)) {
			down = i;
			break;
		}
	}
	bzero(ocp, len);
	for (i = 0; i < boardColSize; i++) {
		for (j = 0; j < boardRowSize; j++) {
			if (board[j][i] == 'X')
				ocp[j] = 1;
		}
		if (all_cop(ocp, boardRowSize)) {
			left = i;
			break;
		}
	}
	bzero(ocp, len);
	for (i = boardColSize - 1; i >= 0; i--) {
		for (j = 0; j < boardRowSize; j++) {
			if (board[j][i] == 'X')
				ocp[j] = 1;
		}
		if (all_cop(ocp, boardRowSize)) {
			right = i;
			break;
		}
	}
	if (up < 0 || down < 0 || left < 0 || right < 0) {
		free(ocp);
		return;
	}
	for (i = up; i <= down; i++) {
		for (j = left; j <= right; j++)
			board[i][j] = 'X';
	}

	free(ocp);
	return;
}

#include <stdio.h>

int main(void)
{
	char	*board[] = {
		"0XX0X",
		"X00X0",
		"X0X0X",
		"0X000",
		"XX0X0",
	};
	int	i, j;
	solve(board, 5, 5);
	for (i = 0; i < 5; i++)
		printf("%s\n", board[i]);
	return(0);
}
