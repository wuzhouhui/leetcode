struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int lheight(struct TreeNode *root)
{
	int	h = 0;
	while (root) {
		h++;
		root = root->left;
	}
	return(h);
}

static int rheight(struct TreeNode *root)
{
	if (!root)
		return(0);
	int	h = 0;
	while (root) {
		h++;
		root = root->right;
	}
	return(h);
}

int countNodes(struct TreeNode *root)
{
	if (!root)
		return(0);
	int lh = lheight(root);
	int rh = rheight(root);
	if (lh == rh)
		return((1 << lh) - 1);
	return(countNodes(root->left) + countNodes(root->right) + 1);
}

int main(void)
{

}
