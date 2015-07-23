/*
 * too slow, but correct
 */
#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct link_node {
	struct TreeNode *data;
	struct link_node *next;
	struct link_node *prev;
};

static struct link_node *path, *path_tail, *pathp, *pathq;

static void init(void)
{
	path = path_tail = pathp = pathq = NULL;
}
static void clean(struct link_node *head)
{
	struct link_node *tmp;

	while (head) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

static void path_add(struct TreeNode *data)
{
	struct link_node *nodep = malloc(sizeof(struct link_node));
	nodep->data = data;
	nodep->next = nodep->prev = NULL;
	if (path == NULL) {
		path = path_tail = nodep;
	} else {
		path_tail->next = nodep;
		nodep->prev = path_tail;
		path_tail = nodep;
	}
}

static void path_rm(void)
{
	struct link_node *tail_bak;

	tail_bak = path_tail;
	path_tail = path_tail->prev;
	if (path_tail == NULL)
		path = NULL;
	else
		path_tail->next = NULL;
	free(tail_bak);
}

static struct link_node *path_cpy(void)
{
	struct link_node *newpath, *newtail, *tmp1, *tmp2;

	newpath = NULL;
	for (tmp1 = path; tmp1; tmp1 = tmp1->next) {
		tmp2 = malloc(sizeof(struct link_node));
		tmp2->next = NULL;
		tmp2->data = tmp1->data;
		if (newpath == NULL) {
			newpath = newtail = tmp2;
		} else {
			newtail->next = tmp2;
			newtail = tmp2;
		}
	}
	return(newpath);
}

static void trav(struct TreeNode *root, struct TreeNode *p,
		struct TreeNode *q)
{
	if (root == NULL)
		return;
	path_add(root);
	if (root == p)
		pathp = path_cpy();
	if (root == q)
		pathq = path_cpy();
	trav(root->left, p, q);
	trav(root->right, p, q);
	path_rm();
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root,
		struct TreeNode *p, struct TreeNode *q)
{
	struct TreeNode *ance;
	struct link_node *tmp1, *tmp2;

	init();
	trav(root, p, q);
	if (pathp == NULL || pathq == NULL) {
		ance = NULL;
		goto out;
	}

	for (tmp1 = pathp, tmp2 = pathq; tmp1 && tmp2; tmp1 = tmp1->next,
			tmp2 = tmp2->next) {
		if (tmp1->data != tmp2->data)
			break;
		ance = tmp1->data;
	}
out:
	clean(pathp);
	clean(pathq);
	return ance;
}

int main(void)
{
}
