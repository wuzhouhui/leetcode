struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool	int
#endif

static int height(struct TreeNode *, int *);

bool isBalanced(struct TreeNode *root)
{
	if (!root)
		return(1);
	
	int is_bal, h1, h2;

	is_bal = 1;
	h1 = height(root->left, &is_bal);
	if (!is_bal)
		return(0);
	h2 = height(root->right, &is_bal);
	if (!is_bal)
		return(0);
	h1 -= h2;
	if (h1 < -1 || h1 > 1)
		return(0);
	return(1);
}

static int height(struct TreeNode *root, int *is_bal)
{
	if (!root)
		return(0);

	int	h1, h2, diff;

	h1 = height(root->left, is_bal);
	if (!is_bal)
		return(0);
	h2 = height(root->right, is_bal);
	if (!is_bal)
		return(0);
	diff = h1 - h2;
	if (diff < -1 || diff > 1) {
		*is_bal = 0;
		return(0);
	}
	return((h1 > h2 ? h1 : h2) + 1);
}

int main(void)
{}
