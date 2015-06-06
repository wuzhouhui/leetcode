#include <stdlib.h>

#define STEP	8

struct Interval {
	int	start;
	int	end;
};

static struct Interval *ans;
static int p, maxp;

static void do_init(void)
{
	ans = 0;
	p = maxp = 0;
}

static struct Interval *add_ans(const struct Interval *v)
{
	if (!ans) {
		maxp = STEP;
		p = 0;
		ans = malloc(maxp * sizeof(struct Interval));
	}
	if (p >= maxp) {
		maxp += STEP;
		ans = realloc(ans, maxp * sizeof(struct Interval));
	}
	ans[p].start = v->start;
	ans[p].end = v->end;
	return(&ans[p++]);
}

static int cmpfun(const void *a, const void *b)
{
	struct Interval *ia = (struct Interval *)a;
	struct Interval *ib = (struct Interval *)b;
	return((ia->start - ib->start) == 0 ? ia->end - ib->end :
			ia->start - ib->start);
}

struct Interval *merge(struct Interval *intervals, int intervalsSize,
		int *returnSize)
{
	if (!intervalsSize) {
		*returnSize = 0;
		return(0);
	}

	int	i, j;
	struct Interval *ptr;
	 do_init(); 

	qsort(intervals, intervalsSize, sizeof(struct Interval),
			cmpfun);

	ptr = add_ans(&intervals[0]);
	for (i = 1; i < intervalsSize; i++) {
		if (ptr->end >= intervals[i].start) {
			if (intervals[i].end > ptr->end)
				ptr->end = intervals[i].end;
		} else {
			ptr = add_ans(&intervals[i]);
		}
	}
	*returnSize = p;
	return(ans);
}

int main(void)
{
	struct Interval x[] = {
		{ 1, 3}, {7, 9}, {4, 6}, {10, 13},
	};

	int	i;
	struct Interval *res = merge(x, 4, &i);
	return(0);
}
