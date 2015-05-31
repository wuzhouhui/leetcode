#include <stdlib.h>

struct StringArray {
	char **elements;
	int  size;
};
struct stack {
	int	val;
	struct stack *next;
};

static struct stack *stackptr = NULL;

static void push(int);
static int pop();

int evalRPN(struct StringArray *tokens) 
{
	if (!tokens || !tokens->elements || !tokens->size)
		return(0);

	int	i;
	int	op2;

	for (i = 0; i < tokens->size; i++) {
		switch (tokens->elements[i][0]) {
		case '+':
			push(pop() + pop());
			break;
		case '/':
			op2 = pop();
			push(pop() / op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			if (tokens->elements[i][1]) {
				push(atoi(tokens->elements[i]));
			} else {
				op2 = pop();
				push(pop() - op2);
			}
			break;
		default:
			push(atoi(tokens->elements[i]));
			break;
		}
	}

	i = stackptr->val;
	free(stackptr);
	return(i);
}

static void push(int val)
{
	struct stack *tmpptr;

	tmpptr = malloc(sizeof(struct stack));
	tmpptr->val = val;
	tmpptr->next = stackptr;
	stackptr = tmpptr;
}

static int pop()
{
	struct stack *ptr;
	int	val;

	ptr = stackptr;
	stackptr = stackptr->next;
	val = ptr->val;
	free(ptr);
	return(val);
}

#include <stdio.h>

int main(void)
{
	char *token[] = { "4", "13", "5", "/", "+" };
	struct StringArray sa;
	sa.elements = token;
	sa.size = sizeof(token) / sizeof(char *);
	printf("%d\n", evalRPN(&sa));
	return(0);
}
