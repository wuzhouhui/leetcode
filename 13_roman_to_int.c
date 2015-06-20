
static int num_to_roman_2(char *s) 
{
	if (!strncmp("CM", s, 2))
		return(900);
	if (!strncmp("CD", s, 2))
		return(400);
	if (!strncmp("XC", s, 2))
		return(90);
	if (!strncmp("XL", s, 2))
		return(40);
	if (!strncmp("IX", s, 2))
		return(9);
	if (!strncmp("IV", s, 2))
		return(4);
	return(0);
}

static int num_to_roman(char c)
{
	switch (c) {
	case 'I': return(1);
	case 'V': return(5);
	case 'X': return(10);
	case 'L': return(50);
	case 'C': return(100);
	case 'D': return(500);
	case 'M': return(1000);
	}
	return(0);
}

int romanToInt(char *s)
{
	int	res;
	int	i, r1, r2;

	i = res = 0;
	while (s[i]) {
		r1 = num_to_roman(s[i]);
		if (s[i + 1]) {
			r2 = num_to_roman(s[i + 1]);
			if (r1 < r2) {
				res += num_to_roman_2(s + i);
				i += 2;
			} else {
				res += r1;
				i++;
			}
		} else {
			res += r1;
			i++;
		}
	}
	return(res);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", romanToInt(argv[1]));
	return(0);
}
