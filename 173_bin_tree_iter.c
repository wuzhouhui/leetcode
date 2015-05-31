#include <stdlib.h>

#ifndef bool 
#define bool int 
#endif

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct linked_node {
	struct TreeNode	*val;
	struct linked_node	*next;
};
struct BSTIterator {
	struct linked_node	*stack;
};

struct BSTIterator *bstIteratorCreate(struct TreeNode *root)
{
	struct linked_node		*tmp;
	struct BSTIterator	*i;

	i = malloc(sizeof(struct BSTIterator));
	i->stack = NULL;
	if (!root)
		return(i);
	while (root) {
		tmp = malloc(sizeof(struct linked_node));
		tmp->val = root;
		root = root->left;
		tmp->next = i->stack;
		i->stack = tmp;
	}
	return(i);
}

int bstIteratorNext(struct BSTIterator *iter)
{
	if (!iter || !iter->stack)
		return(0);

	struct linked_node *list_node, *tmp;
	struct TreeNode *tree_node;
	int	ret;

	list_node = iter->stack;
	iter->stack = iter->stack->next;
	ret = list_node->val->val;

	tree_node = list_node->val->right;
	while (tree_node) {
		tmp = malloc(sizeof(struct linked_node));
		tmp->val = tree_node;
		tmp->next = iter->stack;
		iter->stack = tmp;
		tree_node = tree_node->left;
	}

	free(list_node);
	return(ret);
}

bool bstIteratorHasNext(struct BSTIterator *iter)
{
	if (!iter)
		return(0);
	return(iter->stack != NULL);
}

int bstIteratorFree(struct BSTIterator *iter)
{
	if (!iter)
		return;

	struct linked_node *tmp;

	while (iter->stack) {
		tmp = iter->stack;
		iter->stack = iter->stack->next;
		free(tmp);
	}
	free(iter);
}

/**
 * your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */

int main(void)
{

}
