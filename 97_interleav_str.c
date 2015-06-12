#include <string.h>
#include <strings.h>

#ifndef bool 
#define bool int 
#endif

bool isInterleave(char *s1, char *s2, char *s3)
{
	int	l1 = strlen(s1);
	int	l2 = strlen(s2);
	char	n[l2 + 1];
	int	i, j;

	if ((l1 + l2) != strlen(s3))
		return(0);

	bzero(n, sizeof(n));
	for (i = 0; i <= l1; i++) {
		for (j = 0; j <= l2; j++) {
			if (!i && !j)
				n[j] = 1;
			else if (!i && s3[j - 1] == s2[j - 1])
				n[j] = n[j -1];
			else if (!j && s3[i - 1] == s1[i - 1])
				n[j] = n[j];
			else if (s3[i + j - 1] == s1[i - 1] &&
					s3[i + j - 1] != s2[j - 1])
				n[j] = n[j];
			else if (s3[i + j - 1] != s1[i - 1] &&
					s3[i + j - 1] == s2[j - 1])
				n[j] = n[j - 1];
			else if (s3[i + j - 1] == s1[i - 1] &&
					s3[i + j - 1] == s2[j - 1])
				n[j] = (n[j] || n[j - 1]);
			else 
				n[j] = 0;
		}
	}
	return(n[l2]);
}

#include <stdio.h>

int main(void)
{
	printf("%d, %d, %d\n", isInterleave("aabcc", "dbbca", "aadbbcbcac"),
			isInterleave("aabcc", "dbbca", "aadbbbaccc"),
			isInterleave("a", "", "c"));
	return(0);
}
