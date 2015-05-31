#include <string.h>
#include <stdlib.h>

#ifndef bool 
#define bool int 
#endif

struct node {
	char	val;
	struct node *next;
};

static struct node *stack;

static void push(char ch)
{
	struct node *tmp = malloc(sizeof(struct node));
	tmp->val = ch;
	tmp->next = stack;
	stack = tmp;
}

static char pop()
{
	if (!stack)
		return('\0');
	struct node *tmp = stack;
	char	ch = tmp->val;
	stack = stack->next;
	free(tmp);
	return(ch);
}

static void free_stack()
{
	struct node *tmp;
	while (stack) {
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

bool isValid(char *s)
{
	if (!s)
		return(1);
	if (strlen(s) % 2)
		return(0);

	int	i, c, res;

	for (i = 0, res = 1; s[i]; i++) {
		if (!res)
			break;
		switch (s[i]) {
		case '(':
		case '{':
		case '[':
			push(s[i]);
			break;
		case ')':
		case '}':
		case ']':
			c = pop();
			switch (c) {
			case '(': c = ')'; break;
			case '{': c = '}'; break;
			case '[': c = ']'; break;
			}
			if (c != s[i])
				res = 0;
			break;
		}
	}
	if (stack)
		res = 0;
	free_stack();
	return(res);
}

int main(void)
{}
