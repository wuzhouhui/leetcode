#include <string.h>
#include <stdlib.h>

static char *rev_str(const char *str, int l)
{
	int	i;
	char	*str_r = malloc(l);

	i = 0;
	l--;
	while (l >= 0)
		str_r[i++] = str[l--];
	return(str_r);
}

char *multiply(char *num1, char *num2)
{
	if (!num1 || !num2)
		return(0);

	int	l1, l2, i, j, t, c, max;
	char	*num1_r, *num2_r, *res_r;

	if (!(l1 = strlen(num1)) || !(l2 = strlen(num2)))
		return(0);
	num1_r = rev_str(num1, l1);
	num2_r = rev_str(num2, l2);
	res_r = calloc(l1 + l2, sizeof(char));
	
	c	= 0;
	max	= 0;
	for (i = 0; i < l1; i++) {
		for (j = 0; j < l2; j++) {
			t = (num1_r[i] - '0') * (num2_r[j] - '0');
			t += c;
			res_r[i + j] += t;
			c = res_r[i + j] / 10;
			res_r[i + j] %= 10;
		}
		if (c) {
			max = i + j;
			res_r[max] += c;
			c = 0;
		} else {
			max = i + j - 1;
		}
	}

	free(num1_r);
	free(num2_r);
	num1_r = calloc(max + 2, sizeof(char));
	i = max;
	j = 0;
	while (i >= 0)
		num1_r[j++] = res_r[i--] + '0';
	free(res_r);
	if (num1_r[0] == '0')
		num1_r[1] = 0;
	return(num1_r);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%s\n", multiply(argv[1], argv[2]));
	return(0);
}
