#include <string.h>

int lengthOfLongestSubstring(char *s)
{
	static char chcnt[256] = { 0 };
	int max = 0;
	int left = 0, right = 0;
	int t;
	memset(chcnt, 0, sizeof(chcnt));
	while (s[right]) {
		chcnt[s[right]]++;
		if (chcnt[s[right]] < 2) {
			right++;
			continue;
		}
		t = right - left;
		if (t > max)
			max = t;
		while (1) {
			chcnt[s[left]]--;
			if (chcnt[s[left]] == 0) {
				left++;
				continue;
			}
			left++;
			break;
		}
		right++;
	}
	t = right - left;
	if (t > max)
		max = t;
	return(max);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", lengthOfLongestSubstring(argv[1]));
	return(0);
}
