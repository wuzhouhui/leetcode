#include <string.h>

int numDecodings(char *s)
{
	if (!s || !(*s) || *s == '0')
		return(0);

	int	i, x[strlen(s) + 1];

	for (i = 0; s[i]; i++) {
		if (i == 0) {
			x[0] = 1;
			continue;
		}
		if (i == 1) {
			if (s[1] == '0') {
				if (s[0] <= '2')
					x[1] = 1;
				else 
					return(0);
				continue;
			}
			if (s[0] == '1') {
				x[1] = 2;
				continue;
			}
			if (s[0] == '2') {
				if (s[1] <= '6') 
					x[1] = 2;
				else 
					x[1] = 1;
				continue;
			}
			x[1] = 1;
			continue;
		}
		if (s[i] == '0') {
			if (s[i - 1] == '0')
				return(0);
			if (s[i - 1] <= '2')
				x[i] = x[i - 2];
			else 
				return(0);
			continue;
		}
		if (s[i - 1] == '0') {
			x[i] = x[i - 1];
			continue;
		}
		if (s[i - 1] == '1') {
			x[i] = x[i - 2] + x[i - 1];
			continue;
		}
		if (s[i - 1] == '2') {
			if (s[i] <= '6')
				x[i] = x[i - 2] + x[i - 1];
			else 
				x[i] = x[i - 1];
			continue;
		}
		x[i] = x[i - 1];
	}
	return(x[i - 1]);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", numDecodings("123"));
	return(0);
}
