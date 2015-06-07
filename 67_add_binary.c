#include <string.h>
#include <stdlib.h>

char *addBinary(char *a, char *b)
{
	if (!a && !b)
		return(strdup("0"));
	if (!a)
		return(strdup(b));
	if (!b)
		return(strdup(a));

	int	la, lb, i, j, c;
	char	*longer, *shorter, *res;

	la = strlen(a);
	lb = strlen(b);

	if (!la && !lb)
		return(strdup("0"));
	if (!la)
		return(strdup(b));
	if (!lb)
		return(strdup(a));

	if (la >= lb) {
		longer = a;
		shorter = b;
	} else {
		longer = b;
		shorter = a;
	}

	i = (la >= lb ? la : lb) - 1;
	j = (la >= lb ? lb : la) - 1;
	c = 0;
	while (j >= 0) {
		longer[i] += shorter[j] - '0' + c;
		if (longer[i] >= '2') {
			longer[i] -= 2;
			c = 1;
		} else {
			c = 0;
		}
		i--;
		j--;
	}

	if (i < 0) {
		/* la == lb */
		if (c) {
			res = calloc(la + 2, sizeof(char));
			memcpy(res + 1, longer, la * sizeof(char));
			res[0] = '1';
			return(res);
		} else {
			return(strdup(longer));
		}
	}

	if (c)
		longer[i] += 1;
	while (i > 0 && longer[i] >= '2') {
		longer[i] -= 2;
		i--;
		longer[i] += 1;
	}

	if (longer[0] >= '2') {
		longer[0] -= 2;
		la = strlen(longer) + 2;
		res = calloc(la, sizeof(char));
		memcpy(res + 1, longer, la * sizeof(char));
		res[0] = '1';
		return(res);
	}
	return(strdup(longer));
}

int main(void)
{

}
