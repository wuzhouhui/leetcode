#include <strings.h>

#ifndef bool 
#define bool 
#endif

static char occupy[512][512];

int do_exist(char **board, int row, int col, int r, int c, char *word)
{
	if (!*word)
		return(1);
	if (r < 0 || r >= row || c < 0 || c >= col)
		return(0);
	if (occupy[r][c])
		return(0);
	if (board[r][c] != *word)
		return(0);
	occupy[r][c] = 1;
	if (do_exist(board, row, col, r - 1, c, word + 1))
		return(1);
	if (do_exist(board, row, col, r + 1, c, word + 1))
		return(1);
	if (do_exist(board, row, col, r, c - 1, word + 1))
		return(1);
	if (do_exist(board, row, col, r, c + 1, word + 1))
		return(1);
	occupy[r][c] = 0;
	return(0);
}

bool exist(char **board, int boardRowSize, int boardColSize, char *word)
{
	if (!word || !word[0])
		return(1);
	if (!boardRowSize || !boardColSize)
		return(0);
	int	i, j;

	bzero(occupy, sizeof(occupy));
	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			if (!do_exist(board, boardRowSize, boardColSize,
					i, j, word))
				continue;
			return(1);
		}
	}

	return(0);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", exist(argv + 2, argc - 2, sizeof(argv[2]), argv[1]));
	return(0);
}
