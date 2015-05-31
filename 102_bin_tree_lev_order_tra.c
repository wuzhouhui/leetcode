#include <stdlib.h>

#define STEP	16

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct qnode {
	struct TreeNode *val;
	struct qnode *next;
};

static struct qnode *q1head, *q1tail;
static struct qnode *q2head, *q2tail;
static int **ret, *colsize;
static int maxretlen, maxcollen;

#define init() \
	do { \
		q1head = q1tail = q2head = q2tail = NULL; \
		ret = NULL; colsize = NULL; \
		maxretlen = maxcollen = 0; \
	} while (0)

static void enq1(struct TreeNode *node)
{
	if (!node)
		return;
	struct qnode *t = malloc(sizeof(struct qnode));
	t->val = node;
	t->next = NULL;
	if (!q1tail) {
		q1head = q1tail = t;
		return;
	}
	q1tail->next = t;
	q1tail = t;
}

static struct TreeNode *deq1()
{
	struct qnode *t = q1head;
	struct TreeNode *n = t->val;
	q1head = q1head->next;
	if (!q1head)
		q1tail = NULL;
	free(t);
	return(n);
}

static void enq2(struct TreeNode *node)
{
	if (!node)
		return;
	struct qnode *t = malloc(sizeof(struct qnode));
	t->val = node;
	t->next = NULL;
	if (!q2tail) {
		q2head = q2tail = t;
		return;
	}
	q2tail->next = t;
	q2tail = t;
}

static void setval(int level, int p, int val)
{
	if (ret == NULL) {
		maxretlen = STEP;
		ret = calloc(maxretlen, sizeof(int *));
		colsize = calloc(maxretlen, sizeof(int));
	}
	if (level >= maxretlen) {
		maxretlen += STEP;
		ret = realloc(ret, sizeof(int *) * maxretlen);
		colsize = realloc(colsize, sizeof(int) * maxretlen);
	}
	if (p == 0) {
		maxcollen = STEP;
		ret[level] = malloc(maxcollen * sizeof(int));
		colsize[level] = 0;
	}
	if (p >= maxcollen) {
		maxcollen += STEP;
		ret[level] = realloc(ret[level], sizeof(int) * maxcollen);
	}
	ret[level][p] = val;
	colsize[level]++;
}

int **levelOrder(struct TreeNode *root, int **columnSizes, int *returnSize)
{
	if (!root) {
		*columnSizes = NULL;
		*returnSize = 0;
		return(NULL);
	}

	int	level, p;
	struct TreeNode *node;
	
	init();

	enq1(root);
	level = -1;
	while (q1head) {
		level++;
		p = 0;
		while (q1head) {
			node = deq1();
			setval(level, p++, node->val);
			enq2(node->left);
			enq2(node->right);
		}
		q1head = q2head;
		q1tail = q2tail;
		q2head = q2tail = NULL;
	}
	*columnSizes = colsize;
	*returnSize = level + 1;
	return(ret);
}

int main(void)
{}
