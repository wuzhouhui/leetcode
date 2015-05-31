/*
 * letter combinations of a phone number
 */

#include <stdlib.h>
#include <string.h>

static struct {
	int	len;
	char	*letters;
} tables[] = {
	{ 1, " " }, { 0, "" }, { 3, "abc" }, { 3, "def" }, { 3, "ghi" }, { 3, "jkl" },
	{ 3, "mno"}, { 4, "pqrs" }, { 3, "tuv" }, { 4, "wxyz" }
}, prevdigit;

char **letterCombinations(char *digits, int *returnSize)
{
	if (!digits || !digits[0]) {
		*returnSize = 0;
		return(NULL);
	}

	int	i, j, k, n, ind, digitslen;
	int	loop;
	char	**strptr, *ptr;

	n = 1;
	digitslen = 0;
	for (i = 0; digits[i] && digits[i] != '1'; i++) {
		n *= tables[digits[i] - '0'].len;
		digitslen++;
	}

	*returnSize = n;
	strptr = malloc(n * sizeof(char *));
	ptr = calloc(n, digitslen + 1); /* +1 for terminator */

	for (i = 0; i < n; i++) {
		strptr[i] = ptr;
		ptr += digitslen + 1;
	}

	for (i = strlen(digits) - 1; i >= 0; i--) {
		if (digits[i] == '1')
			continue;
		if (loop == 0)
			loop = 1;
		else 
			loop *= prevdigit.len;
		prevdigit = tables[digits[i] - '0'];
		digitslen--;

		ind = 0;
		for (j = 0; j < n; ) {
			for (k = 0; k < loop; k++)
				strptr[j++][digitslen] =
					tables[digits[i] - '0'].letters[ind];
			if (++ind == tables[digits[i] - '0'].len)
				ind = 0;
		}
	}

//	for (i = 0; digits[i] && digits[i] != '1'; i++) {
//		digitslen = 0;
//		for (j = 0; j < n; j++) {
//			strptr[j][i] = tables[digits[i] - '0'].letters[digitslen++];
//			if (digitslen == tables[digits[i] - '0'].len)
//				digitslen = 0;
//		}
//	}

	return(strptr);
}

int main(void)
{
}
