#include <stdlib.h>

#define STEP 8

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode **trave;
static int p, maxp;

static void in_order(struct TreeNode *root)
{
	if (!root) 
		return;
	in_order(root->left);
	if (!trave) {
		maxp = STEP;
		p = 0;
		trave = malloc(maxp * sizeof(struct TreeNode *));
	}
	if (p >= maxp) {
		maxp += STEP;
		trave = realloc(trave, maxp * sizeof(struct TreeNode *));
	}
	trave[p++] = root;
	in_order(root->right);
}

void recoverTree(struct TreeNode *root)
{
	if (!root)
		return;

	int	i;
	struct TreeNode *first, *second;

	trave = 0;
	first = second = 0;
	in_order(root);
	for (i = 1; i < p; i++) {
		if (trave[i]->val < trave[i - 1]->val) {
			if (!first) {
				first = trave[i - 1];
				second = trave[i];
			} else {
				second = trave[i];
				break;
			}
		}
	}

	if (first) {
		i = first->val;
		first->val = second->val;
		second->val = i;
	}
	if (trave)
		free(trave);
	return;
}

int main(void)
{

}
