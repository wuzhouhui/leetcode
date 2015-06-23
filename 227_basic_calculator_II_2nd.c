int calculate(char *s)
{
	if (!s || !s[0])
		return(0);

	int	sum, term, prev, op;
	int	i;

	sum = term = i = 0;
	prev = '+';
	while (s[i]) {
		if (s[i] == ' ') {
			i++;
			continue;
		}
		switch (s[i]) {
		case '+':
		case '-':
			sum += term;
			term = 0;
			prev = s[i];
			i++;
			break;
		case '*':
		case '/':
			prev = s[i];
			i++;
			break;
		default:
			op = 0;
			while (s[i] >= '0' && s[i] <= '9')
				op = op * 10 + s[i++] - '0';
			switch (prev) {
			case '+':
				term += op;
				break;
			case '-':
				term += (-op);
				break;
			case '*':
				term *= op;
				break;
			case '/':
				term /= op;
				break;
			}
		}
	}
	return(sum + term);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", calculate(argv[1]));
	return(0);
}
