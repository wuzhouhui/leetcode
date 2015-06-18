
struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int sum, path;

static void do_sum(struct TreeNode *root)
{
	path = path * 10 + root->val;

	if (!root->left && !root->right) {
		sum += path;
		path /= 10;
		return;
	}
	
	if (root->left)
		do_sum(root->left);
	if (root->right)
		do_sum(root->right);
	path /= 10;
	return;
}

int sumNumbers(struct TreeNode *root)
{
	if (!root)
		return(0);
	sum = 0;
	path = 0;
	do_sum(root);
	return(sum);
}

int main(void)
{

}
