#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *buildTree(int *inorder, int inorderSize, 
		int *postorder, int postorderSize)
{
	if (!inorderSize)
		return(NULL);

	struct TreeNode *root;
	int	i;

	for (i = 0; i < inorderSize; i++)
		if (inorder[i] == postorder[postorderSize - 1])
			break;
	root = malloc(sizeof(struct TreeNode));
	root->val = inorder[i];
	root->left = buildTree(inorder, i, postorder, i);
	root->right = buildTree(inorder + i + 1, inorderSize - i - 1,
			postorder + i, inorderSize - i - 1);
	return(root);
}

int main(void)
{}
