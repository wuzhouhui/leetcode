#include <stdlib.h>
#include <string.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int	*res, i;

	res = malloc((digitsSize + 1) * sizeof(int));
	if (!digitsSize) {
		*returnSize = 1;
		res[0] = 1;
		return(res);
	}

	i = digitsSize - 1;
	digits[i]++;
	while (i > 0 && digits[i] >= 10) {
		digits[i] -= 10;
		i--;
		digits[i]++;
	}

	if (digits[0] >= 10) {
		digits[0] -= 10;
		memcpy(res + 1, digits, digitsSize * sizeof(int));
		res[0] = 1;
		*returnSize = digitsSize + 1;
		return(res);
	}

	memcpy(res, digits, digitsSize * sizeof(int));
	*returnSize = digitsSize;
	return(res);
}

int main(void)
{

}
