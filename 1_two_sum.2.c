#include <stdlib.h>

struct valind {
	int val, ind;
};

static int cmp(const void *a, const void *b)
{
	const struct valind *p1 = a;
	const struct valind *p2 = b;
	return(p1->val - p2->val);
}

int *twoSum(int *nums, int numsSize, int target)
{
	int *res = malloc(sizeof(int) + sizeof(int));
	struct valind valind[numsSize];
	int i;
	for (i = 0; i < numsSize; i++) {
		valind[i].val = nums[i];
		valind[i].ind = i;
	}
	qsort(valind, numsSize, sizeof(valind[0]), cmp);
	numsSize--;
	i = 0;
	while (1) {
		int t = valind[i].val + valind[numsSize].val;
		if (t == target) {
			res[0] = valind[i].ind;
			res[1] = valind[numsSize].ind;
			return(res);
		} else if (t > target) {
			numsSize--;
		} else {
			i++;
		}
	}
}

main(){}
