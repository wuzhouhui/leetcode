#include <string.h>

static int seg(const char *s, char **dict, int dict_size)
{
	if (!s || !s[0])
		return(1);

	int	slen, i, l;

	slen = strlen(s);
	for (i = 0; i < dict_size; i++) {
		l = strlen(dict[i]);
		if (slen < l || strncmp(s, dict[i], l))
			continue;
		if (seg(s + l, dict, dict_size))
			return(1);
	}
	return(0);
}

int segmentation(const char *s, char **dict, int dict_size)
{
	if (!s || !s[0])
		return(1);

	/* s.len > 0 */

	if (!dict_size)
		return(0);
	return(seg(s, dict, dict_size));
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", segmentation(argv[1], argv + 2, argc - 2));
	return(0);
}
