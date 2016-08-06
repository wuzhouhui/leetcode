#ifndef bool
#define bool int
#endif

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
	arr[9] = 1;
}

bool isValidSudoku(char **board, int boardRowSize, int boardColSize)
{
	static int arr[9];
	int i, j, k, l;

	for (i = 0; i < 9; i++) {
		initarr(arr);
		for (j = 0; j < 9; j++)
			if (board[i][j] == '.')
				continue;
			else if (--arr[board[i][j] - '0'] < 0)
				return(0);
	}
	for (i = 0; i < 9; i++) {
		initarr(arr);
		for (j = 0; j < 9; j++)
			if (board[j][i] == '.')
				continue;
			else if (--arr[board[j][i] - '0'] < 0)
				return(0);
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			initarr(arr);
			for (k = 3 * i; k < 3 * i + 3; k++) {
				for (l = 3 * j; l < 3 * j + 3; l++)
					if (board[k][l] == '.')
						continue;
					else if (--arr[board[k][l] - '0'] < 0)
						return(0);
			}
		}
	}
	return(1);
}
main(){}
