struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int depth(struct TreeNode *);

int minDepth(struct TreeNode *root)
{
	if (!root)
		return(0);
	return(depth(root));
}

static int depth(struct TreeNode *root)
{
	if (!root)
		return(0);
	if (!root->left && !root->right)
		return(1);

	int	h1, h2;

	h1 = depth(root->left);
	h2 = depth(root->right);
	if (h1 && h2)
		return((h1 < h2 ? h1 : h2) + 1);
	return((h1 > h2 ? h1 : h2) + 1);
}

int main(void)
{}
