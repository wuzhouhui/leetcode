#include <stdlib.h>

#define STEP 16

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static void post_trav(struct TreeNode *, int **p, int *, int *);

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
	if (!root) {
		*returnSize = 0;
		return(NULL);
	}
	int	*p;
	int	bufsz, currsz;

	if (!root->left && !root->right) {
		p = malloc(sizeof(int));
		p[0] = root->val;
		*returnSize = 1;
		return(p);
	}

	bufsz = STEP;
	currsz = 0;
	p = malloc(bufsz * sizeof(int));

	post_trav(root, &p, &bufsz, &currsz);

	*returnSize = currsz;
	return(p);
}

static void post_trav(struct TreeNode *root, int **p,
		int *bufsz, int *currsz)
{
	if (!root)
		return;
	post_trav(root->left, p, bufsz, currsz);
	post_trav(root->right, p, bufsz, currsz);
	(*p)[(*currsz)++] = root->val;
	if (*currsz == *bufsz) {
		*bufsz += STEP;
		*p = realloc(*p, *bufsz * sizeof(int));
	}
}

int main(void)
{
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	int	n;
	root->val = 1;
	root->left = malloc(sizeof(struct TreeNode));
	root->left->val = 2;
	root->left->left = NULL;
	root->left->right = NULL;
	root->right = NULL;
	/*
	root->right = malloc(sizeof(struct TreeNode));
	root->right->val = 3;
	root->right->left = NULL;
	root->right->right = NULL;
	*/
	postorderTraversal(root, &n);
	return(0);
}
