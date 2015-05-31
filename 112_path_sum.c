struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool int 
#endif

#ifndef NULL 
#define NULL ((struct TreeNode *)0)
#endif

static int pre_trav(struct TreeNode *, int, int);

bool hasPathSum(struct TreeNode *root, int sum)
{
	if (!root)
		return(0);
	if (!root->left && !root->right && root->val != sum)
		return(0);
	return(pre_trav(root, 0, sum));
}

static int pre_trav(struct TreeNode *root, int curr_sum, int sum)
{
	if (!root)
		return(0);
	if ((curr_sum += root->val) == sum && !root->left && !root->right)
		return(1);
	if (pre_trav(root->left, curr_sum, sum))
		return(1);
	return(pre_trav(root->right, curr_sum, sum));
}

int main(void)
{}
