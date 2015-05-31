/*
 * runtime error.
 */
/*
 * binary tree zigzag level order traversal
 */
#include <stdlib.h>

#define STEP	16

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct Node {
	struct TreeNode *tree_node;
	struct Node	*next;
};

static int maxlevel, maxp;
static int **res, *colsize;
static struct Node *stack, *qhead, *qtail;

static void put(int level, int p, int val) 
{
	if (level >= maxlevel) {
		maxlevel += STEP;
		res = realloc(res, maxlevel * sizeof(int *));
		colsize = realloc(colsize, maxlevel * sizeof(int));
		colsize[level] = 0;
	}
	if (p >= maxp) {
		maxp += STEP;
		res[level] = realloc(res[level], maxp * sizeof(int));
	}
	res[level][p] = val;
	(*(colsize + level))++;
}

static void push(struct TreeNode *tree_node) 
{
	if (!tree_node) 
		return;
	
	struct Node *tmp;

	tmp = malloc(sizeof(struct Node));
	tmp->tree_node = tree_node;
	tmp->next = stack;
	stack = tmp;
}

static struct TreeNode *pop()
{
	struct Node	*tmp;
	struct TreeNode	*tree_node;

	tmp = stack;
	stack = stack->next;
	tree_node = tmp->tree_node;
	free(tmp);
	return(tree_node);
}

static int is_semp(void)
{
	return(stack == NULL);
}

static void enque(struct TreeNode *tree_node)
{
	if (!tree_node)
		return;
	if (!qhead) {
		qhead = qtail = malloc(sizeof(struct Node));
		qhead->tree_node = tree_node;
		qhead->next = NULL;
		return;
	}
	qtail->next = malloc(sizeof(struct Node));
	qtail = qtail->next;
	qtail->tree_node = tree_node;
	qtail->next = NULL;
}

static struct TreeNode *deque()
{
	struct Node	*tmp;
	struct TreeNode	*tree_node;

	tmp = qhead;
	qhead = qhead->next;
	tree_node = tmp->tree_node;
	free(tmp);
	return(tree_node);
}

static int is_qemp(void)
{
	return(qhead == NULL);
}

static void myinit(void)
{
	qhead = qtail = stack = NULL;
	maxlevel = maxp = 0;
	colsize = NULL;
	res = NULL;
}

int **zigzagLevelOrder(struct TreeNode *root, int **columnSizes,
		int *returnSize)
{
	if (!root) {
		*columnSizes = NULL;
		*returnSize = 0;
		return(NULL);
	}

	myinit();

	struct TreeNode *node;
	int	left2right, level, p;

	left2right = 0;
	level = -1;
	enque(root);
	while (!is_qemp()) {
		left2right = !left2right;
		level++;
		maxp = p = 0;
		while (!is_qemp()) {
			node = deque();
			put(level, p++, node->val);
			if (left2right) {
				push(node->left);
				push(node->right);
			} else {
				push(node->right);
				push(node->left);
			}
		}
		while (!is_semp()) {
			enque(pop());
		}
	}

	*returnSize = level + 1;
	*columnSizes = colsize;
	return(res);
}

int main(void)
{
	struct TreeNode *root;
	int	*colsize, retsz;
	int	**res;

	root = calloc(1, sizeof(struct TreeNode));
	root->val = 2;
	root->right = calloc(1, sizeof(struct TreeNode));
	root->right->val = 3;
	root->right->right = calloc(1, sizeof(struct TreeNode));
	root->right->right->val = 4;
	root->right->right->right = calloc(1, sizeof(struct TreeNode));
	root->right->right->right->val = 5;
	root->right->right->right->right = calloc(1, sizeof(struct TreeNode));
	root->right->right->right->right->val = 6;
	res = zigzagLevelOrder(root, &colsize, &retsz);
	while (retsz-- > 0)
		free(res[retsz]);
	free(res);
	free(colsize);
	return(0);
}
