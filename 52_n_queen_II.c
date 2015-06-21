#define MAXN	512
#include <stdio.h>
#include <strings.h>

static int	res;
static char	m[MAXN][MAXN];
static char	col_ocp[MAXN];

static void print_m(int n)
{
	int	i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (m[i][j])
				printf("1 ");
			else 
				printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

static int avail(int n, int lev)
{
	int	i, j, k, l;

	for (i = 0; i <= lev; i++) {
		for (j = 0; j < n; j++) {
			if (!m[i][j])
				continue;
			for (k = i + 1, l = j - 1;
					k <= lev && l >= 0; k++, l--) {
				if (m[k][l])
					return(0);
			}
			for (k = i + 1, l = j + 1;
					k <= lev && l < n; k++, l++) {
				if (m[k][l])
					return(0);
			}
		}
	}
	return(1);
}

static void nqueen(int n, int lev)
{
	int	i;

	if (lev == 0) {
		for (i = 0; i < n; i++) {
			m[0][i] = 1;
			col_ocp[i] = 1;
			nqueen(n, 1);
			m[0][i] = 0;
			col_ocp[i] = 0;
		}
		return;
	}
	if (lev == (n - 1)) {
		for (i = 0; i < n; i++) {
			if (!col_ocp[i])
				break;
		}
		m[lev][i] = 1;
		if (avail(n, lev)) {
			res++;
		}
		m[lev][i] = 0;
		return;
	}
	for (i = 0; i < n; i++) {
		if (col_ocp[i])
			continue;
		m[lev][i] = 1;
		col_ocp[i] = 1;
		if (avail(n, lev))
			nqueen(n, lev + 1);
		m[lev][i] = 0;
		col_ocp[i] = 0;
	}
}

int totalNQueens(int n) 
{
	if (!n || n == 1)
		return(n);

	bzero(m, sizeof(m));
	bzero(col_ocp, sizeof(col_ocp));
	res = 0;

	nqueen(n, 0);
	return(res);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", totalNQueens(4));
	return(0);
}
