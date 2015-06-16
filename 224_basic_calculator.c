
#include <stdlib.h>

struct stack {
	int	val;
	struct stack *next;
};

static void push(struct stack **s, int val)
{
	struct stack *t = malloc(sizeof(struct stack));
	t->val = val;
	t->next = *s;
	*s = t;
}

static int pop(struct stack **s)
{
	struct stack *t = *s;
	int	val = t->val;
	*s = (*s)->next;
	free(t);
	return(val);
}

static int top(struct stack *s)
{
	return(s->val);
}

int calculate(char *s)
{
	if (!s || !s[0])
		return(0);

	struct stack *oprands, *oprators;
	int	op, preoprator;

	oprators = oprands = 0;
	preoprator = 0;
	while (*s) {
		switch (*s) {
		case ' ':
			s++;
			break;
		case '(':
			push(&oprators, '(');
			s++;
			preoprator = 0;
			break;
		case '+':
			push(&oprators, '+');
			s++;
			preoprator = 0;
			break;
		case '-':
			push(&oprators, '-');
			s++;
			preoprator = '-';
			break;
		case ')':
			op = pop(&oprands);
			while (pop(&oprators) != '(')
				op += pop(&oprands);
			if (oprators && top(oprators) == '-') {
				pop(&oprators);
				push(&oprands, pop(&oprands) - op);
			} else {
				push(&oprands, op);
			}
			s++;
			break;
		default:
			op = 0;
			while (*s >= '0' && *s <= '9') {
				op = op * 10 + *s - '0';
				s++;
			}
			if (preoprator == '-') {
				pop(&oprators);
				push(&oprands, pop(&oprands) - op);
				preoprator = 0;
			} else {
				push(&oprands, op);
			}
		}
	}

	op = pop(&oprands);
	while (oprators) {
		op += pop(&oprands);
		pop(&oprators);
	}
	return(op);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", calculate(argv[1]));
	return(0);
}
