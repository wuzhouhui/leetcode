static int rep(char *s, int left, int right)
{
	for (; left < right; left++)
		if (s[left] == s[right])
			return(left);
	return(-1);
}

int lengthOfLongestSubstring(char *s)
{
	if (!s || !s[0])
		return(0);
	int	maxlen, left, right, start;

	maxlen = 1;
	for (left = 0, right = 1; s[right]; right++) {
		if ((start = rep(s, left, right))< 0) {
			if ((right - left + 1) > maxlen)
				maxlen = right - left + 1;
		} else {
			left = start + 1;
		}
	}
	if ((right - left) > maxlen)
		maxlen = right - left;
	return(maxlen);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", lengthOfLongestSubstring(argv[1]));
	return(0);
}
