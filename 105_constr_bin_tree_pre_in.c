#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *buildTree(int *preorder, int preorderSize, 
		int *inorder, int inorderSize)
{
	if (!preorderSize || !inorderSize)
		return(NULL);

	struct TreeNode *root;
	int	i;

	root = malloc(sizeof(struct TreeNode));
	root->val = preorder[0];
	for (i = 0; i < preorderSize && inorder[i] != preorder[0]; i++)
		;
	root->left = buildTree(preorder + 1, i, inorder, i);
	root->right = buildTree(preorder + i + 1, inorderSize - i - 1,
			inorder + i + 1, inorderSize - i - 1);
	return(root);
}

int main(void)
{
}
