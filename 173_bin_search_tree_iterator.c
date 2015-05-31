/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#include <stdlib.h>

struct BSTIterator {
	int	val;
	struct BSTIterator *next;
};

static struct BSTIterator *curr;

struct BSTIterator *bstIteratorCreate(struct TreeNode *root) {
	if (!root)
		return NULL;

	struct BSTIterator *head = NULL;
	struct BSTIterator *tmp  = NULL;
	struct BSTIterator *tmp2 = NULL;

	head = bstIteratorCreate(root->right);

	tmp = malloc(sizeof(struct BSTIterator));
	tmp->val = root->val;
	tmp->next = head;
	head = tmp;

	tmp = bstIteratorCreate(root->left);
	if (tmp) {
		for (tmp2 = tmp; tmp2->next != NULL; tmp2 = tmp2->next)
			;
		tmp2->next = head;
		head = tmp;
	}

	curr = head;
	return(head);
}

/** @return whether we have a next smallest number */
int bstIteratorHasNext(struct BSTIterator *iter) {
	return(curr != NULL);
}

/** @return the next smallest number */
int bstIteratorNext(struct BSTIterator *iter) {
	int	val;

	val = curr->val;
	curr = curr->next;
	return val;
}

/** Deallocates memory previously allocated for the iterator */
void bstIteratorFree(struct BSTIterator *iter) {
	struct BSTIterator *tmp;

	while ((tmp = iter) != NULL) {
		iter = iter->next;
		free(tmp);
	}
}

/**
 * Your BSTIterator will be called like this:
 * struct BSTIterator *i = bstIteratorCreate(root);
 * while (bstIteratorHasNext(i)) printf("%d\n", bstIteratorNext(i));
 * bstIteratorFree(i);
 */
