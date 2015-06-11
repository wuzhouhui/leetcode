#include <stdlib.h>

struct stack_node {
	int	val;
	struct stack_node *next;
};

static struct stack_node *stack;

static void push(int i)
{
	struct stack_node *tmp = malloc(sizeof(struct stack_node));
	tmp->val = i;
	tmp->next = stack;
	stack = tmp;
}

static int pop(void)
{
	struct stack_node *tmp = stack;
	int	n = tmp->val;
	stack = stack->next;
	free(tmp);
	return(n);
}

static int top(void)
{
	return(stack->val);
}

int largestRectangleArea(int *height, int heightSize)
{
	if (!heightSize)
		return(0);
	if (heightSize == 1)
		return(height[0]);

	int	i, left, tp, t, max;

	i = 0;
	max = -1;
	stack = 0;
	while (i < heightSize) {
		if (!stack || height[i] >= height[top()]) {
			push(i++);
			continue;
		}

		tp = pop();
		t = (!stack ? i : i - top() - 1) * height[tp];
		if (t > max)
			max = t;
	}
	while (stack) {
		tp = pop();
		t = (!stack ? i : i - top() -1) * height[tp];
		if (t > max)
			max = t;
	}
	return(max);
}

#include <stdio.h>

int main(void)
{
	int x[] = { 6, 2, 5, 4, 5, 1, 6 };
	printf("%d\n", largestRectangleArea(x, sizeof(x) / sizeof(int)));
	return(0);
}
