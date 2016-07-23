#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

static struct {
	int	val;
	char	*str;
	int	len;
} table[] = {
	4, "IV", 2,
	9, "IX", 2, 
	40, "XL", 2, 
	90, "XC", 2, 
	400, "CD", 2, 
	900, "CM", 2, 
	1, "I", 1,
	5, "V", 1,
	10, "X", 1,
	50, "L", 1,
	100, "C", 1,
	500, "D", 1,
	1000, "M", 1,
};

int romanToInt(char *s)
{
	int res = 0;
	int i, j;

	for (i = 0; s[i];) {
		for (j = 0; j < ARRAY_SIZE(table); j++) {
			if (strncmp(&s[i], table[j].str, table[j].len))
				continue;
			res += table[j].val;
			i += table[j].len;
			break;
		}
	}
	return(res);
}
main(){}
