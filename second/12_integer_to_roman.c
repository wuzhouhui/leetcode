#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

static struct {
	int	val;
	char	*str;
} table[] = {
	1, "I",
	4, "IV",
	5, "V",
	9, "IX",
	10, "X",
	40, "XL",
	50, "L",
	90, "XC",
	100, "C",
	400, "CD",
	500, "D",
	900, "CM",
	1000, "M",
};

char *intToRoman(int num)
{
	char *roman = malloc(16 * sizeof(*roman));
	int i, p = 0;

	for (i = ARRAY_SIZE(table) - 1; i >= 0; i--) {
		while (num >= table[i].val) {
			num -= table[i].val;
			p += sprintf(&roman[p], "%s", table[i].str);
		}
	}
	return(roman);
}

main()
{
	printf("%s\n", intToRoman(1));
	printf("%s\n", intToRoman(234));
}
