/*
 * runtime error, maybe stack overflow.
static void border(char **board, int r, int c, int row, int col)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return;
	if (board[r][c] == 'X' || board[r][c] == '#')
		return;
	board[r][c] = '#';
	border(board, r - 1, c, row, col);
	border(board, r + 1, c, row, col);
	border(board, r, c - 1, row, col);
	border(board, r, c + 1, row, col);
}

void solve(char **board, int boardRowSize, int boardColSize)
{
	if (boardRowSize <= 1 || boardColSize <= 1)
		return;

	int	i, j;

	for (i = 0; i < boardColSize; i++) {
		if (board[0][i] == 'O')
			border(board, 0, i, boardRowSize, boardColSize);
		if (board[boardRowSize - 1][i] == 'O')
			border(board, boardRowSize - 1, i, boardRowSize,
					boardColSize);
	}
	for (i = 0; i < boardRowSize; i++) {
		if (board[i][0] == 'O')
			border(board, i, 0, boardRowSize, boardColSize);
		if (board[i][boardColSize - 1] == 'O')
			border(board, i, boardColSize - 1, boardRowSize,
					boardColSize);
	}
	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] == 'X')
				continue;
			if (board[i][j] == 'O') {
				board[i][j] = 'X';
				continue;
			}
			if (board[i][j] == '#')
				board[i][j] = 'O';
		}
	}
	return;
}
*/

#include <stdlib.h>

struct node {
	int	row;
	int	col;
	struct node *next;
};

static struct node *queue, *tail;

static void enq(int row, int col)
{
	struct node *node = malloc(sizeof(struct node));
	node->row = row;
	node->col = col;
	node->next = 0;
	if (!queue) {
		queue = tail = node;
		return;
	}
	tail->next = node;
	tail = node;
	return;
}

static void deq(int *row, int *col)
{
	struct node *node = queue;
	queue = queue->next;
	*row = node->row;
	*col = node->col;
	free(node);
}

void solve(char **board, int boardRowSize, int boardColSize)
{
	if (boardRowSize <= 1 || boardColSize <= 1)
		return;

	int	i, j, r, c;

	queue = tail = 0;
	for (i = 0; i < boardColSize; i++) {
		if (board[0][i] == 'O')
			enq(0, i);
		if (board[boardRowSize - 1][i] == 'O')
			enq(boardRowSize - 1, i);
	}
	for (i = 0; i < boardRowSize; i++) {
		if (board[i][0] == 'O')
			enq(i, 0);
		if (board[i][boardColSize - 1] == 'O')
			enq(i, boardColSize - 1);
	}
	while (queue) {
		deq(&r, &c);
		if (r < 0 || r >= boardRowSize || c < 0 || c >= boardColSize)
			continue;
		if (board[r][c] == 'X' || board[r][c] == '#')
			continue;
		board[r][c] = '#';
		enq(r - 1, c);
		enq(r + 1, c);
		enq(r, c - 1);
		enq(r, c + 1);
	}
	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] == 'X')
				continue;
			if (board[i][j] == 'O') {
				board[i][j] = 'X';
				continue;
			}
			if (board[i][j] == '#')
				board[i][j] = 'O';
		}
	}
	return;
}

#include <stdio.h>

int main(int argc, char **argv)
{
	int	i;
	char	r1[] = "XXX";
	char	r2[] = "XOX";
	char	r3[] = "XXX";
	char	*b[] = { r1, r2, r3 };
	solve(b, 3, 3);
	for (i = 0; i < 3; i++)
		printf("%s\n", b[i]);
	return(0);
}
