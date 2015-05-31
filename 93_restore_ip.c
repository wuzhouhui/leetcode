#include <string.h>
#include <stdlib.h>

#define STEP 16

struct answer {
	int	start;
	int	len;
};

static char **ips;
static int p, maxp;

static void addans(struct answer *ans, char *s)
{
	int	i, l1, l2;
	if (!ips) {
		maxp = STEP;
		p = 0;
		ips = malloc(maxp * sizeof(char *));
	}
	if (p >= maxp) {
		maxp += STEP;
		ips = realloc(ips, maxp * sizeof(char *));
	}
	
	ips[p] = malloc(strlen(s) + 4);
	for (l1 = l2 = i = 0; i < 4; i++) {
		strncpy(ips[p] + l1, s + l2, ans[i].len);
		l1 += ans[i].len;
		l2 += ans[i].len;
		*(ips[p] + l1++) = '.';
	}
	*(ips[p] + l1 - 1) = 0;
	p++;
}

static void dig(char *s, struct answer *ans, int lev)
{
	int	t, l;
	char	buf[4];

	if (lev == 3) {
		ans[3].start = ans[2].start + ans[2].len;
		ans[3].len = strlen(s + ans[3].start);
		if (ans[3].len > 1 && s[ans[3].start] == '0')
			return;
		t = atoi(s + ans[3].start);
		if (ans[3].len >= 1 && ans[3].len <= 3
				&& t >= 0 && t <= 255)
			addans(ans, s);
		return;
	}
	if (!lev)
		ans[lev].start = 0;
	else 
		ans[lev].start = ans[lev - 1].start + ans[lev - 1].len;
	for (ans[lev].len = 1; s[ans[lev].start + ans[lev].len] && 
			ans[lev].len <= 3; ans[lev].len++) {
		if (ans[lev].len > 1 && s[ans[lev].start] == '0')
			continue;
		strncpy(buf, s + ans[lev].start, ans[lev].len);
		buf[ans[lev].len] = 0;
		t = atoi(buf);
		l = strlen(s + ans[lev].start + ans[lev].len);
		if (t >= 0 && t <= 255 && l >= (3 - lev) && 
				l <= (3 * (3 - lev)))
			dig(s, ans, lev + 1);
	}
}

char **restoreIpAddresses(char *s, int *returnSize)
{
	if (!s || strlen(s) < 4 || strlen(s) > 12) {
		*returnSize = 0;
		return(NULL);
	}

	struct answer ans[4];

	ips = NULL;
	maxp = p = 0;
	dig(s, ans, 0);
	*returnSize = p;
	return(ips);
}

int main(void)
{
	char s[] = "19216811";
	int ret = 0;
	restoreIpAddresses(s, &ret);
	return(0);
}
