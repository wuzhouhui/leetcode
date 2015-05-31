/* time limit exceeded */
#include <string.h>

#define SPACE	' '

void reverseWords(char *s)
{
	int	left, right, tmp, i, j;

	if (!s || s[1] == 0)
		return;

	right = strlen(s);
	left = 0;
	while (left <= right) {
		for (right--; right >= left && s[right] == SPACE; right--)
			;
		for (i = left; i <= right; i++) {
			if (s[i] == SPACE)
				break;
		}
		if (i > right)
			break;
		j = 0;
		while (right > left && s[right] != SPACE) {
			tmp = s[right];
			for (i = right; i > left; i--) {
				s[i] = s[i - 1];
			}
			s[left] = tmp;
			j++;
		}
		left += j;
		if (s[left] && s[left] != SPACE) {
			if (s[right] != SPACE)
				right++;
			for (i = right; i > left; i--)
				s[i] = s[i - 1];
			s[left] = SPACE;
			left++;
		}
	}
	right = strlen(s);
	while (s[--right] == SPACE)
		s[right] = 0;
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	reverseWords(argv[1]);
	printf("%s\n", argv[1]);
	return(0);
}
