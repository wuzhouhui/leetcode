#include <limits.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int do_maxsum(struct TreeNode *root, int *sum)
{
	if (!root)
		return(0);
	int	left, right, cur, t, path;

	left = do_maxsum(root->left, sum);
	right = do_maxsum(root->right, sum);

	cur = root->val;
	if ((t = root->val + left) > cur)
		cur = t;
	if ((t = root->val + right) > cur)
		cur = t;
	path = cur;
	if ((t = root->val + left + right) > cur)
		cur = t;
	if (cur > *sum)
		*sum = cur;
	return(path);
}

int maxPathSum(struct TreeNode *root)
{
	if (!root)
		return(0);
	int	sum = INT_MIN;
	do_maxsum(root, &sum);
	return(sum);
}

int main(void)
{

}
