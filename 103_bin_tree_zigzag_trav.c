///*
// * runtime error.
// */
///*
// * binary tree zigzag level order traversal
// */
//#include <stdlib.h>
//
//#define STEP	16
//
//struct TreeNode {
//	int	val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//};
//
//struct Node {
//	struct TreeNode *tree_node;
//	struct Node	*next;
//};
//
//static int maxlevel, maxp;
//static int **res, *colsize;
//static struct Node *stack, *qhead, *qtail;
//
//static void put(int level, int p, int val) 
//{
//	if (level >= maxlevel) {
//		maxlevel += STEP;
//		res = realloc(res, maxlevel * sizeof(int *));
//		colsize = realloc(colsize, maxlevel * sizeof(int));
//		colsize[level] = 0;
//	}
//	if (p >= maxp) {
//		maxp += STEP;
//		res[level] = realloc(res[level], maxp * sizeof(int));
//	}
//	res[level][p] = val;
//	(*(colsize + level))++;
//}
//
//static void push(struct TreeNode *tree_node) 
//{
//	if (!tree_node) 
//		return;
//	
//	struct Node *tmp;
//
//	tmp = malloc(sizeof(struct Node));
//	tmp->tree_node = tree_node;
//	tmp->next = stack;
//	stack = tmp;
//}
//
//static struct TreeNode *pop()
//{
//	struct Node	*tmp;
//	struct TreeNode	*tree_node;
//
//	tmp = stack;
//	stack = stack->next;
//	tree_node = tmp->tree_node;
//	free(tmp);
//	return(tree_node);
//}
//
//static int is_semp(void)
//{
//	return(stack == NULL);
//}
//
//static void enque(struct TreeNode *tree_node)
//{
//	if (!tree_node)
//		return;
//	if (!qhead) {
//		qhead = qtail = malloc(sizeof(struct Node));
//		qhead->tree_node = tree_node;
//		qhead->next = NULL;
//		return;
//	}
//	qtail->next = malloc(sizeof(struct Node));
//	qtail = qtail->next;
//	qtail->tree_node = tree_node;
//	qtail->next = NULL;
//}
//
//static struct TreeNode *deque()
//{
//	struct Node	*tmp;
//	struct TreeNode	*tree_node;
//
//	tmp = qhead;
//	qhead = qhead->next;
//	tree_node = tmp->tree_node;
//	free(tmp);
//	return(tree_node);
//}
//
//static int is_qemp(void)
//{
//	return(qhead == NULL);
//}
//
//static void myinit(void)
//{
//	qhead = qtail = stack = NULL;
//	maxlevel = maxp = 0;
//	colsize = NULL;
//	res = NULL;
//}
//
//int **zigzagLevelOrder(struct TreeNode *root, int **columnSizes,
//		int *returnSize)
//{
//	if (!root) {
//		*columnSizes = NULL;
//		*returnSize = 0;
//		return(NULL);
//	}
//
//	myinit();
//
//	struct TreeNode *node;
//	int	left2right, level, p;
//
//	left2right = 0;
//	level = -1;
//	enque(root);
//	while (!is_qemp()) {
//		left2right = !left2right;
//		level++;
//		maxp = p = 0;
//		while (!is_qemp()) {
//			node = deque();
//			put(level, p++, node->val);
//			if (left2right) {
//				push(node->left);
//				push(node->right);
//			} else {
//				push(node->right);
//				push(node->left);
//			}
//		}
//		while (!is_semp()) {
//			enque(pop());
//		}
//	}
//
//	*returnSize = level + 1;
//	*columnSizes = colsize;
//	return(res);
//}
//
//int main(void)
//{
//	struct TreeNode *root;
//	int	*colsize, retsz;
//	int	**res;
//
//	root = calloc(1, sizeof(struct TreeNode));
//	root->val = 2;
//	root->right = calloc(1, sizeof(struct TreeNode));
//	root->right->val = 3;
//	root->right->right = calloc(1, sizeof(struct TreeNode));
//	root->right->right->val = 4;
//	root->right->right->right = calloc(1, sizeof(struct TreeNode));
//	root->right->right->right->val = 5;
//	root->right->right->right->right = calloc(1, sizeof(struct TreeNode));
//	root->right->right->right->right->val = 6;
//	res = zigzagLevelOrder(root, &colsize, &retsz);
//	while (retsz-- > 0)
//		free(res[retsz]);
//	free(res);
//	free(colsize);
//	return(0);
//}

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
