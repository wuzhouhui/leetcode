#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareVersion(char *version1, char *version2)
{
	int	i1, i2, j1, j2, l1, l2;
	long long res;

	l1 = strlen(version1);
	l2 = strlen(version2);
	i1 = 0;
	i2 = 0;
	while (1) {
		for (j1 = i1; version1[i1] && version1[i1] != '.'; i1++)
			if (version1[j1] == '0')
				j1++;
		for (j2 = i2; version2[i2] && version2[i2] != '.'; i2++)
			if (version2[j2] == '0')
				j2++;

		version1[i1] = version2[i2] = 0;
		res = atoll(version1 + j1) - atoll(version2 + j2);
		/* res = strcmp(version1 + j1, version2 + j2); */
		if (res > 0)
			return(1);
		if (res < 0)
			return(-1);
		if (i1 == l1 && i2 == l2)
			break;
		if (i1 != l1)
			i1++;
		if (i2 != l2)
			i2++;
	}
	return(0);
}

int main(void)
{
	char	v1[] = "1";
	char	v2[] = "1.1";
	printf("%d\n", compareVersion(v1, v2));
	return(0);
}
