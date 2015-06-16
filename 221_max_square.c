int maximalSquare(char **matrix, int matrixRowSize, int matrixColSize)
{
    if (!matrixRowSize || !matrixColSize)
        return(0);

    int	area[matrixRowSize][matrixColSize];
    int	max, i, j, t;

    max = 0;
    for (i = 0; i < matrixRowSize; i++) {
        for (j = 0; j < matrixColSize; j++) {
            if (!i || !j) {
                area[i][j] = (matrix[i][j] == '1' ? 1 : 0);
            } else {
                if (matrix[i][j] == '0')
                    area[i][j] = 0;
                else if (matrix[i-1][j] == '1' && matrix[i][j-1] == '1') {
                    /*
                    t = matrix[i-1][j-1] < matrix[i-1][j] ?
                            matrix[i-1][j-1] : matrix[i-1][j];
                    if (matrix[i][j-1] < t)
                        t = matrix[i][j-1];
                    area[i][j] = t + 1;
                    */
                    t = area[i-1][j-1];
                    if (area[i-1][j] < t)
                        t = area[i-1][j];
                    if (area[i][j-1] < t)
                        t = area[i][j-1];
                    area[i][j] = t + 1;
                    //area[i][j] = area[i-1][j-1] + 1;
                } else 
                    area[i][j] = 1;
            }
            if ((t = area[i][j] * area[i][j]) > max)
                max = t;
        }
    }
    return(max);
}

#include <stdio.h>

int main(void)
{
    char *m[] = {
        "11111111",
        "11111110",
        "11111110",
        "11111000",
        "01111000",
    };
    printf("%d\n", maximalSquare(m, 5, 8));
    return(0);
}

/*
 * vim: ts=4 sts=4 sw=4 et
 */
