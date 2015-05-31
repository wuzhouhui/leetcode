#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *build_tree(int *nums, int l, int u)
{
	if (l > u)
		return(NULL);
	int	m;
	struct TreeNode *root;

	m = (l + u) / 2;
	root = malloc(sizeof(struct TreeNode));
	root->val = nums[m];
	root->left = build_tree(nums, l, m - 1);
	root->right = build_tree(nums, m + 1, u);
	return(root);
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
	if (!numsSize)
		return(NULL);
	return(build_tree(nums, 0, numsSize - 1));
}

int main(void)
{}
