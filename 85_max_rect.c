#include <stdlib.h>
#include <strings.h>

struct stack_node {
	int	val;
	struct stack_node *next;
};

static struct stack_node *stack;

static  int pop(void)
{
	struct stack_node *t = stack;
	int	r = t->val;
	stack = stack->next;
	free(t);
	return(r);
}

static int top(void)
{
	return(stack->val);
}

static void push(int n)
{
	struct stack_node *t = malloc(sizeof(struct stack_node));
	t->val = n;
	t->next = stack;
	stack = t;
}

static int max_rect(int *h, int n)
{
	if (n == 1)
		return(h[0]);
	int	i, t, max, tp;

	i = 0;
	max = -1;
	stack = 0;
	while (i < n) {
		if (!stack || h[i] >= h[top()]) {
			push(i++);
			continue;
		}
		tp = pop();
		t = h[tp] * (!stack ? i : i - top() - 1);
		if (t > max)
			max = t;
	}

	while (stack) {
		tp = pop();
		t = h[tp] * (!stack ? i : i - top() - 1);
		if (t > max)
			max = t;
	}

	return(max);
}

int maximalRectangle(char **matrix, int matrixRowSize, int matrixColSize)
{
	if (!matrixRowSize || !matrixColSize)
		return(0);
	int	h[matrixColSize], i, j;
	int	t, max;

	bzero(h, sizeof(h));
	max = -1;
	for (i = 0; i < matrixRowSize; i++) {
		for (j = 0; j < matrixColSize; j++) {
			if (matrix[i][j] == '0')
				h[j] = 0;
			else
				h[j]++;
		}
		t = max_rect(h, matrixColSize);
		if (t > max)
			max = t;
	}
	return(max);
}

#include <stdio.h>

int main(void)
{
	char *x[] = { "1" };
	printf("%d\n", maximalRectangle(x, 1, 1));
	return(0);
}
