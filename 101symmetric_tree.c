#include <stdlib.h>
#include <string.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool 
#define bool int 
#endif

#define STEP 16

static int *left1st;
static int *right1st;
static int p, maxsz;

static void left_inorder(struct TreeNode *);
static void right_inorder(struct TreeNode *);
static void left_preorder(struct TreeNode *);
static void right_preorder(struct TreeNode *);

bool isSymmetric(struct TreeNode *root)
{
	if (!root)
		return(1);

	maxsz = STEP;
	left1st = malloc(maxsz * sizeof(int));
	p = 0;
	left_inorder(root);

	right1st = malloc(maxsz * sizeof(int));
	p = 0;
	right_inorder(root);

	maxsz = memcmp(left1st, right1st, p * sizeof(int));
	if (!maxsz) {
		bzero(left1st, maxsz * sizeof(int));
		bzero(right1st, maxsz * sizeof(int));
		p = 0;
		left_preorder(root);
		p = 0;
		right_preorder(root);
		maxsz = memcmp(left1st, right1st, p * sizeof(int));
	}
	free(left1st);
	free(right1st);

	return(!maxsz);
}

static void left_inorder(struct TreeNode *root)
{
	if (!root)
		return;

	left_inorder(root->left);
	if (p >= maxsz) {
		maxsz += STEP;
		left1st = realloc(left1st, maxsz * sizeof(int));
	}
	left1st[p++] = root->val;
	left_inorder(root->right);
}

static void right_inorder(struct TreeNode *root)
{
	if (!root)
		return;
	right_inorder(root->right);
	right1st[p++] = root->val;
	right_inorder(root->left);
}

static void left_preorder(struct TreeNode *root)
{
	if (!root)
		return;
	left1st[p++] = root->val;
	left_preorder(root->left);
	left_preorder(root->right);
}

static void right_preorder(struct TreeNode *root)
{
	if (!root)
		return;
	right1st[p++] = root->val;
	right_preorder(root->right);
	right_preorder(root->left);
}

int main(void)
{}
