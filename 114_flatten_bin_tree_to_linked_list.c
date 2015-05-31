///*
// * memory limit exceeded
// */
//#include <stdlib.h>
//
//struct TreeNode {
//	int	val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//};
//
//static struct TreeNode *head = NULL;
//static struct TreeNode *tail = NULL;
//
//static void my_flatten(struct TreeNode *);
//
//void flatten(struct TreeNode *root)
//{
//	if (!root)
//		return;
//
//	my_flatten(root->left);
//	my_flatten(root->right);
//	root->left = NULL;
//	root->right = head;
//}
//
//static void my_flatten(struct TreeNode *root)
//{
//	if (!root)
//		return;
//
//	struct TreeNode *ptr;
//
//	ptr = calloc(1, sizeof(struct TreeNode));
//	ptr->val = root->val;
//	if (!head) {
//		head = tail = ptr;
//	} else {
//		tail->right = ptr;
//		tail = tail->right;
//	}
//	flatten(root->left);
//	flatten(root->right);
//	free(root);
//}

/*
 * time limit exceeded
 */
#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static void my_flatten(struct TreeNode *);

static struct TreeNode *head = NULL;

void flatten(struct TreeNode *root)
{
	if (!root)
		return;
	my_flatten(root->right);
	my_flatten(root->left);
	root->left = NULL;
	root->right = head;
}

static void my_flatten(struct TreeNode *root)
{
	if (!root)
		return;
	my_flatten(root->right);
	my_flatten(root->left);
	root->left = NULL;
	root->right = head;
	head = root;
}

int main(void)
{}
