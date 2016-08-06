static void inline initarr(int *arr)
{
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 1;
	arr[5] = 1;
	arr[6] = 1;
	arr[7] = 1;
	arr[8] = 1;
}

static int valid(char **board, int row, int col)
{
	static int arr[9];
	int i, j;
	initarr(arr);
	for (i = 0; i < 9; i++)
		if (board[i][col] == '.')
			continue;
		else if (--arr[board[i][col] - '1'] < 0)
			return(0);
	initarr(arr);
	for (i = 0; i < 9; i++)
		if (board[row][i] == '.')
			continue;
		else if (--arr[board[row][i] - '1'] < 0)
			return(0);
	row /= 3; row *= 3;
	col /= 3; col *= 3;
	initarr(arr);
	for (i = row; i < row + 3; i++)
		for (j = col; j < col + 3; j++)
			if (board[i][j] == '.')
				continue;
			else if (--arr[board[i][j] - '1'] < 0)
				return(0);
	return(1);
}

static int do_solve(char **board, int start)
{
	int r, c, i;
	for (; start < 81; start++)
		if (board[start / 9][start % 9] == '.')
			break;
	if (start >= 81)
		return(1);
	r = start / 9;
	c = start % 9;
	for (i = '1'; i <= '9'; i++) {
		board[r][c] = i;
		if (valid(board, r, c) && do_solve(board, start + 1))
			return(1);
	}
	board[r][c] = '.';
	return(0);
}

void solveSudoku(char **board, int boardRowSize, int boardColSize)
{
	do_solve(board, 0);
}

main(){}
