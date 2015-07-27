#include <stdlib.h>
#define STEP 16
struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int *flatten;
static int p, maxp;

static void in_order(struct TreeNode *root, int k)
{
	if (root == NULL)
		return;
	in_order(root->left, k);
	if (maxp == 0) {
		maxp = STEP;
		p = 0;
		flatten = malloc(maxp * sizeof(flatten[0]));
	}
	if (p >= maxp) {
		maxp += STEP;
		flatten = realloc(flatten, maxp * sizeof(flatten[0]));
	}
	flatten[p++] = root->val;
	if (p == k)
		return;
	else
		in_order(root->right, k);
}

int kthSmallest(struct TreeNode *root, int k)
{
	if (root == NULL)
		return(0);
	maxp = 0;
	in_order(root, k);
	p = flatten[k - 1];
	free(flatten);
	return(p);
}

#include <stdio.h>

int main(void)
{
	struct TreeNode node = { 1, NULL, NULL };
	printf("%d\n", kthSmallest(&node, 1));
	return(0);
}
