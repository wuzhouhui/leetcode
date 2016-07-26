#include <stdlib.h>

#ifndef bool
#define bool int
#endif

struct stack {
	int	val;
	struct stack *next;
} *stack;

static void push(int c)
{
	struct stack *t = malloc(sizeof(*t));
	t->val = c;
	t->next = stack;
	stack = t;
}

static int pop(void)
{
	if (stack == NULL)
		return(0);
	struct stack *p = stack;
	stack = stack->next;
	int v = p->val;
	free(p);
	return(v);
}

bool isValid(char *s)
{
	stack = NULL;
	int c;

	while (*s) {
		switch (*s) {
		case '(':
		case '[':
		case '{':
			push(*s);
			break;
		case ')':
			c = pop();
			if (c != '(')
				return(0);
			break;
		case ']':
			c = pop();
			if (c != '[')
				return(0);
			break;
		case '}':
			c = pop();
			if (c != '{')
				return(0);
			break;
		}
		s++;
	}
	return(stack == NULL);
}

main(){}
