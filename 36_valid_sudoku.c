#include <strings.h>

#ifndef bool 
#define bool 
#endif

bool isValidSudoku(char **board, int boardRowSize, int boardColSize)
{
	static char nums[9];
	int	i, j, k, l;

	for (i = 0; i < 9; i++) {
		bzero(nums, sizeof(nums));
		for (j = 0; j < 9; j++) {
			if (board[i][j] == '.')
				continue;
			if (board[i][j] < '1' || board[i][j] > '9')
				return(0);
			if (nums[board[i][j] - '1'])
				return(0);
			nums[board[i][j] - '1'] = 1;
		}
	}
	for (i = 0; i < 9; i++) {
		bzero(nums, sizeof(nums));
		for (j = 0; j < 9; j++) {
			if (board[j][i] == '.')
				continue;
			if (board[j][i] < '1' || board[j][i] > '9')
				return(0);
			if (nums[board[j][i] - '1'])
				return(0);
			nums[board[j][i] - '1'] = 1;
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			bzero(nums, sizeof(nums));
			for (k = i * 3; k < i * 3 + 3; k++) {
				for (l = j * 3; l < j * 3 + 3; l++) {
					if (board[k][l] == '.')
						continue;
					if (board[k][l] < '1' || board[k][l] > '9')
						return(0);
					if (nums[board[k][l] - '1'])
						return(0);
					nums[board[k][l] - '1'] = 1;
				}
			}
		}
	}
	return(1);
}

int main(void)
{

}
