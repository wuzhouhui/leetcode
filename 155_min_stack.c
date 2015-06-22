#include <stdlib.h>

struct node {
	int	val;
	struct node *next;
};

typedef struct {
	struct node *stack;
	struct node *minstack;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize)
{
	if (!stack)
		return;
	stack->stack = 0;
	stack->minstack = 0;
}

void minStackPush(MinStack *stack, int element)
{
	struct node *t;

	if (!stack)
		return;

	t = malloc(sizeof(struct node));
	t->val = element;
	t->next = stack->stack;
	stack->stack = t;

	if (!stack->minstack || element <= stack->minstack->val) {
		t = malloc(sizeof(struct node));
		t->val = element;
		t->next = stack->minstack;
		stack->minstack = t;
	}
}

void minStackPop(MinStack *stack)
{
	if (!stack || !stack->stack)
		return;

	struct node *t;
	int	val;
	
	t = stack->stack;
	stack->stack = stack->stack->next;
	val = t->val;
	free(t);

	if (stack->minstack->val == val) {
		t = stack->minstack;
		stack->minstack = stack->minstack->next;
		free(t);
	}
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
	return(stack->minstack->val);
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
	}

	while (stack->minstack) {
		t = stack->minstack;
		stack->minstack = stack->minstack->next;
		free(t);
	}
}

int main(void)
{

}
