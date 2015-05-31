struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool 
#define bool int 
#endif

#ifndef NULL 
#define NULL ((void *)0)
#endif 

static int isvalid(struct TreeNode *root, int *max, int *min)
{
	/*
	 * precondition: root not empty.
	 */
	int lmax, lmin, rmax, rmin;

	if (root->left) {
		if (!isvalid(root->left, &lmax, &lmin) || root->val <= lmax)
			return(0);
		*min = lmin;
	} else {
		*min = root->val;
	}
	if (root->right) {
		if (!isvalid(root->right, &rmax, &rmin) || root->val >= rmin)
			return(0);
		*max = rmax;
	} else {
		*max = root->val;
	}
	return(1);
}

bool isValidBST(struct TreeNode *root)
{
	if (!root)
		return(1);
	
	int	lmax, lmin, rmax, rmin;

	if (root->left)
		if (!isvalid(root->left, &lmax, &lmin) || root->val <= lmax)
			return(0);
	if (root->right)
		if (!isvalid(root->right, &rmax, &rmin) || root->val >= rmin)
			return(0);
	return(1);
}

int main(void)
{}
