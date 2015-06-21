#include <string.h>
#include <stdlib.h>

struct node {
	int	pos;
	char	c;
	struct node *next;
};

static struct node *stack;

static void push(int pos, char c)
{
	struct node *t = malloc(sizeof(struct node));
	t->pos = pos;
	t->c = c;
	t->next = stack;
	stack = t;
}

static void peek(int *pos, char *c)
{
	if (!stack) {
		*pos = 0;
		*c = 0;
		return;
	}

	*pos = stack->pos;
	*c = stack->c;
}

static void pop(int *pos, char *c)
{
	if (!stack) {
		*pos = 0;
		*c = 0;
		return;
	}

	struct node *t = stack;
	stack = stack->next;
	*pos = t->pos;
	*c = t->c;
	free(t);
}

int longestValidParentheses(char *s)
{
	if (strlen(s) < 2)
		return(0);

	int	i, pos, len, maxlen;
	char	c;
	struct node *t;

	stack = 0;
	maxlen = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '(') {
			push(i, '(');
			continue;
		}

		peek(&pos, &c);
		if (!stack || c == ')') {
			push(i, ')');
		} else {
			len = 0;
			pop(&pos, &c);
			if (!stack) {
				len = i + 1;
			} else {
				peek(&pos, &c);
				len = i - pos;
			}
			if (len > maxlen)
				maxlen = len;
		}
	}
	while (stack) {
		t = stack;
		stack = stack->next;
		free(t);
	}
	return(maxlen);
}

#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d\n", longestValidParentheses(argv[1]));
	return(0);
}
