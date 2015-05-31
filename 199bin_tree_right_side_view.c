struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct qnode {
	int	layer;
	struct TreeNode *tree_node;
	struct qnode *next;
};

#include <stdlib.h>

#define STEP 8

int *rightSideView(struct TreeNode *root, int *n)
{
	int	nr, *buf, bufsz;
	struct qnode *head, *tail;
	struct qnode *tmp;

	if (!root) {
		*n = 0;
		return NULL;
	}

	nr	= 0;
	bufsz	= STEP;
	buf	= malloc(bufsz * sizeof(int));

	/* put tree root into queue */
	head = tail = malloc(sizeof(struct qnode));
	head->tree_node = root;
	head->layer	= 0;
	head->next	= NULL;

	/* while queue not empty */
	while (head) {
		tmp = head;

		/* put sons into queue */
		if (tmp->tree_node->left) {
			tail->next = malloc(sizeof(struct qnode));
			tail = tail->next;
			tail->layer = tmp->layer + 1;
			tail->tree_node = tmp->tree_node->left;
			tail->next = NULL;
		}
		if (tmp->tree_node->right) {
			tail->next = malloc(sizeof(struct qnode));
			tail = tail->next;
			tail->layer = tmp->layer + 1;
			tail->tree_node = tmp->tree_node->right;
			tail->next = NULL;
		}

		/* dequeue */
		head = head->next;
		if (!head)
			tail = NULL;

		if (!head || tmp->layer != head->layer) {
			if (bufsz <= nr) {
				bufsz += STEP;
				buf = realloc(buf, bufsz * sizeof(int));
			}
			buf[nr++] = tmp->tree_node->val;
		}
		free(tmp);
	}

	*n = nr;
	return buf;
}
