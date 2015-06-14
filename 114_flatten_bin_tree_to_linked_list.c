struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *tail;

static void do_flatten(struct TreeNode *root)
{
	if (!root) {
		tail->right = 0;
		return;
	}
	struct TreeNode *left = root->left;
	struct TreeNode *right = root->right;
	root->left = 0;
	tail->right = root;
	tail = root;
	do_flatten(left);
	do_flatten(right);
}

void flatten(struct TreeNode *root)
{
	if (!root)
		return;
	struct TreeNode *left = root->left;
	struct TreeNode *right = root->right;
	tail = root;
	root->left = 0;
	do_flatten(left);
	do_flatten(right);
}

int main(void)
{

}
