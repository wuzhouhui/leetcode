/*
 * time limit exceeded.
 */
#include <stdlib.h>

struct node {
	int	val;
	struct node *next;
};

typedef struct {
	struct node *stack;
	struct node *ordered;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize)
{
	stack->stack = 0;
	stack->ordered = 0;
}

void minStackPush(MinStack *stack, int element)
{
	struct node *t;
	struct node **pp;

	t = malloc(sizeof(struct node));
	t->val = element;
	t->next = stack->stack;
	stack->stack = t;

	t = malloc(sizeof(struct node));
	t->val = element;
	pp = &stack->ordered;
	while (*pp && t->val > (*pp)->val)
		pp = &(*pp)->next;
	t->next = *pp;
	*pp = t;
}

void minStackPop(MinStack *stack)
{
	if (!stack || !stack->stack)
		return;

	struct node *t, **pp;

	t = stack->stack;
	stack->stack = stack->stack->next;

	pp = &stack->ordered;
	while ((*pp)->val != t->val)
		pp = &(*pp)->next;
	free(t);
	t = *pp;
	*pp = (*pp)->next;
	free(t);
}

int minStackTop(MinStack *stack)
{
	if (!stack || !stack->stack)
		return(0);
	return(stack->stack->val);
}

int minStackGetMin(MinStack *stack)
{
	if (!stack || !stack->stack)
		return(0);
	return(stack->ordered->val);
}

void minStackDestroy(MinStack *stack)
{
	if (!stack || !stack->stack)
		return;
	struct node *t;

	while (stack->stack) {
		t = stack->stack;
		stack->stack = stack->stack->next;
		free(t);
		t = stack->ordered;
		stack->ordered = stack->ordered->next;
		free(t);
	}
}

int main(void)
{

}
