#include <stdlib.h>

#ifndef bool 
#define bool int 
#endif 

struct node {
	int	val;
	int	ind;
};

static int nodecmp(const void *x, const void *y)
{
	return(((struct node *)x)->val - ((struct node *)y)->val);
}

static int binsrc(const struct node *key, int t, int l, int u,
		const struct node *nodes)
{
	if (l > u)
		return(-1);

	long long k = (long long)(key->val) + (long long)t;
	int	l1, m;

	l1 = l - 1;
	u++;
	while ((l1 + 1) != u) {
		m = (l1 + u) / 2;
		if (nodes[m].val > k)
			u = m;
		else 
			l1 = m;
	}
	if (l1 < l || (nodes[l1].val > k))
		return(-1);
	return(l1);
}

bool containsNearbyAlmostDuplicate(int *nums, int numsSize, int k, int t)
{
	if (numsSize < 2)
		return(0);

	int	i, j;
	struct node nodes[numsSize];

	for (i = 0; i < numsSize; i++) {
		nodes[i].val = nums[i];
		nodes[i].ind = i;
	}

	qsort(nodes, numsSize, sizeof(struct node), nodecmp);

	for (i = 0; i < (numsSize - 1); i++) {
		j = binsrc(&nodes[i], t, i + 1, numsSize - 1, nodes);
		for (; j > i; j--) {
			if (abs(nodes[i].ind - nodes[j].ind) <= k)
				return(1);
		}
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { -1, 2147483647 };
	printf("%d\n", containsNearbyAlmostDuplicate(x, 2, 1, 2147483647));
	return(0);
}
