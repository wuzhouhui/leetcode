#include <stdlib.h>

#define STEP	16

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
static struct q_node *qhead, *qtail;
static struct q_node *stack;

static void do_init(void)
{
	res = 0;
	col = 0;
	p = maxp = colp = maxcolp = 0;
	qhead = qtail = 0;
	stack = 0;
}

static void enque(struct TreeNode *tree_node)
{
	if (!tree_node)
		return;

	struct q_node *node = malloc(sizeof(struct q_node));
	node->val = tree_node;
	node->next = 0;
	if (!qhead) {
		qhead = qtail = node;
	} else {
		qtail->next = node;
		qtail = node;
	}
}

static struct TreeNode *deque(void)
{
	struct q_node *t = qhead;
	struct TreeNode *val = t->val;
	qhead = qhead->next;
	free(t);
	return(val);
}

static void push(struct TreeNode *tree_node)
{
	if (!tree_node)
		return;

	struct q_node *qnode = malloc(sizeof(struct q_node));
	qnode->val = tree_node;
	qnode->next = stack;
	stack = qnode;
}

static struct TreeNode *pop(void)
{
	struct q_node *t = stack;
	struct TreeNode *val = t->val;
	stack = stack->next;
	free(t);
	return(val);
}

static void add_ans(const struct TreeNode *node)
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
	res[p][colp++] = node->val;
	col[p]++;
}

int **zigzagLevelOrder(struct TreeNode *root, int **columnSizes, 
		int *returnSize)
{
	if (!root) {
		*columnSizes = 0;
		*returnSize = 0;
		return(0);
	}

	struct TreeNode *node;
	int	left2right;

	do_init();
	enque(root);
	left2right = 1;
	while (qhead) {
		while (qhead) {
			node = deque();
			if (left2right) {
				push(node->left);
				push(node->right);
			} else {
				push(node->right);
				push(node->left);
			}
			add_ans(node);
		}
		p++;
		maxcolp = 0;
		left2right = !left2right;
		while (stack) {
			enque(pop());
		}
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


	res = zigzagLevelOrder(root, &colsize, &retsz);
	return(0);
}
