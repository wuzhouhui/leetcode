#include <stdlib.h>

struct node {
	int	val;
	struct node *next;
};

static void push(struct node **stack, int val)
{
	struct node *node = malloc(sizeof(struct node));
	node->val = val;
	node->next = *stack;
	*stack = node;
}

static int pop(struct node **stack)
{
	if (!(*stack))
		return(0);
	struct node *node = *stack;
	int	val = node->val;
	*stack = (*stack)->next;
	free(node);
	return(val);
}

static int peek(struct node **stack)
{
	return(*stack ? (*stack)->val : 0);
}

int calculate(char *s)
{
	if (!s || !s[0])
		return(0);

	int	result, i, a, b;
	struct node *oprators, *oprands;

	oprators = oprands = 0;
	i = 0;
	while (s[i]) {
		if (s[i] == ' ') {
			i++;
			continue;
		}

		switch (s[i]) {
		case '+':
		case '-':
			if (peek(&oprators) == 0) {
				push(&oprators, s[i]);
				i++;
				break;
			}
			b = pop(&oprands);
			a = pop(&oprands);
			switch (peek(&oprators)) {
			case '-':
				push(&oprands, a - b);
				break;
			case '/':
				push(&oprands, a / b);
				break;
			case '*':
				push(&oprands, a * b);
				break;
			case '+':
				push(&oprands, a + b);
				break;
			}
			pop(&oprators);
			break;
		case '*':
		case '/':
			switch (peek(&oprators)) {
			case '*':
			case '/':
				b = pop(&oprands);
				a = pop(&oprands);
				if (peek(&oprators) == '*')
					push(&oprands, a * b);
				else 
					push(&oprands, a / b);
				pop(&oprators);
				break;
			default:
				push(&oprators, s[i]);
				i++;
				break;
			}
			break;
		default:	/* digits */
			b = 0;
			while (s[i] >= '0' && s[i] <= '9')
				b = b * 10 + s[i++] - '0';
			switch (peek(&oprators)) {
			case '+':
			case '-':
				push(&oprands, b);
				break;
			case '*':
			case '/':
				a = pop(&oprands);
				if (peek(&oprators) == '/')
					push(&oprands, a / b);
				else 
					push(&oprands, a * b);
				pop(&oprators);
				break;
			default:
				push(&oprands, b);
				break;
			}
		}
	}

	result = pop(&oprands);
	if (oprators) {
		a = pop(&oprands);
		if (pop(&oprators) == '-')
			result = a - result;
		else
			result = a + result;
	}
	return(result);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", calculate(argv[1]));
	return(0);
}
