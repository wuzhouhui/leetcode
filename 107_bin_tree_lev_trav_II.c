#include <stdlib.h>
#define STEP	8
struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct q_node {
	struct TreeNode *val;
	struct q_node *next;
};

static int **res, *col, p, maxp, colp, maxcolp;
static struct q_node *q_head1, *q_tail1, *q_head2, *q_tail2;

static void do_init(void)
{
	res	= 0;
	col	= 0;
	p = maxp = colp = maxcolp = 0;
	q_head1 = q_tail1 = q_head2 = q_tail2 = 0;
}

static void enque1(struct TreeNode *val)
{
	if (!val)
		return;

	struct q_node *t = malloc(sizeof(struct q_node));
	t->val	= val;
	t->next	= 0;
	if (!q_head1) {
		q_head1 = q_tail1 = t;
	} else {
		q_tail1->next = t;
		q_tail1	= t;
	}
}

static struct TreeNode *deque1(void)
{
	struct q_node	*t = q_head1;
	struct TreeNode *val = t->val;
	q_head1 = q_head1->next;
	free(t);
	return(val);
}

static void enque2(struct TreeNode *val)
{
	if (!val)
		return;
	struct q_node *t = malloc(sizeof(struct q_node));
	t->val	= val;
	t->next	= 0;
	if (!q_head2) {
		q_head2 = q_tail2 = t;
	} else {
		q_tail2->next = t;
		q_tail2	= t;
	}
}

static void add_ans(struct TreeNode *val)
{
	if (!res) {
		maxp = STEP;
		p = 0;
		res = malloc(maxp * sizeof(int *));
		col = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(int *));
		col = realloc(col, maxp * sizeof(int));
	}
	if (!maxcolp) {
		maxcolp = STEP;
		colp = 0;
		res[p] = malloc(maxcolp * sizeof(int));
		col[p] = 0;
	}
	if (colp >= maxcolp) {
		maxcolp += STEP;
		res[p] = realloc(res[p], maxcolp * sizeof(int));
	}
	res[p][colp++] = val->val;
	col[p]++;
}

int **levelOrderBottom(struct TreeNode *root, int **columnSizes,
		int *returnSize)
{
	if (!root) {
		*columnSizes = 0;
		*returnSize = 0;
		return(0);
	}

	int	i, t, *tptr;
	struct TreeNode *tree_node;

	do_init();
	enque1(root);
	while (q_head1) {
		while (q_head1) {
			tree_node = deque1();
			add_ans(tree_node);
			enque2(tree_node->left);
			enque2(tree_node->right);
		}
		maxcolp = 0;
		p++;
		q_head1 = q_head2;
		q_tail1 = q_tail2;
		q_head2 = q_tail2 = 0;
	}
	
	for (i = 0; i <= (p / 2 - 1); i++) {
		tptr = res[i];
		res[i] = res[p - i - 1];
		res[p - i - 1] = tptr;
	}
	for (i = 0; i <= (p / 2 - 1); i++) {
		t = col[i];
		col[i] = col[p - i - 1];
		col[p - i - 1] = t;
	}
	*columnSizes = col;
	*returnSize = p;
	return(res);
}

int main(void)
{
	struct TreeNode *root;
	int	*colsize, retsz;
	int	**res;

	root = malloc(sizeof(struct TreeNode));
	root->val = 3;
	root->left = malloc(sizeof(struct TreeNode));
	root->left->val = 9;
	root->left->left = root->left->right = 0;
	root->right = malloc(sizeof(struct TreeNode));
	root->right->val = 20;
	root->right->left = malloc(sizeof(struct TreeNode));
	root->right->left->val = 15;
	root->right->left->left = root->right->left->right = 0;
	root->right->right = malloc(sizeof(struct TreeNode));
	root->right->right->val = 7;
	root->right->right->left = root->right->right->right = 0;


	res = levelOrderBottom(root, &colsize, &retsz);
	return(0);
}
