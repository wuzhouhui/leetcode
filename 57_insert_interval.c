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

struct Interval *insert(struct Interval *intervals, int intervalsSize,
		struct Interval newInterval, int *returnSize)
{

	int	i, j, flag;
	struct Interval *ptr;
	do_init(); 

	if (!intervalsSize) {
		add_ans(&newInterval);
		*returnSize = 1;
		return(ans);
	}

	if (newInterval.start < intervals[0].start) {
		ptr = add_ans(&newInterval);
		flag = 0;
		i = 0;
	} else {
		ptr = add_ans(&intervals[0]);
		flag = 1;
		i = 1;
	}

	for (; i < intervalsSize; i++) {
		if (flag && intervals[i].start >= newInterval.start) {
			if (ptr->end >= newInterval.start) {
				if (newInterval.end > ptr->end)
					ptr->end = newInterval.end;
			} else {
				ptr = add_ans(&newInterval);
			}
			flag = 0;
		}
		if (ptr->end >= intervals[i].start) {
			if (intervals[i].end > ptr->end)
				ptr->end = intervals[i].end;
		} else {
			ptr = add_ans(&intervals[i]);
		}
	}
	if (flag) {
		if (ptr->end >= newInterval.start) {
			if (newInterval.end > ptr->end) {
				ptr->end = newInterval.end;
			}
		} else {
			ptr = add_ans(&newInterval);
		}
		flag = 0;
	}
	*returnSize = p;
	return(ans);
}

int main(void)
{
	struct Interval x[] = { {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
	struct Interval *res;
	struct Interval newInterval = {4,9};
	int	i;
	res = insert(x, 5, newInterval, &i);
	return(0);
}
