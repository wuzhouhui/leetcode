#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define STEP	16

static int *list_to_arr(struct ListNode *head, int *size)
{
	int	p, maxp, *res;

	maxp	= STEP;
	p	= 0;
	res = malloc(maxp * sizeof(int));
	while (head) {
		if (p >= maxp) {
			maxp += STEP;
			res = realloc(res, maxp * sizeof(int));
		}
		res[p++] = head->val;
		head = head->next;
	}
	*size = p;
	return(res);
}

static struct TreeNode *build_tree(int *num, int l, int u)
{
	if (l > u)
		return(NULL);

	int	m;
	struct TreeNode *root;

	m = (l + u) / 2;
	root = malloc(sizeof(struct TreeNode));
	root->val = num[m];
	root->left = build_tree(num, l, m - 1);
	root->right = build_tree(num, m + 1, u);
	return(root);
}

struct TreeNode *sortedListToBST(struct ListNode *head)
{
	if (!head)
		return(NULL);
	
	int	*num, size;
	struct TreeNode *root;

	num = list_to_arr(head, &size);

	root = build_tree(num, 0, size - 1);
	free(num);
	return(root);
}

int main(void)
{}
