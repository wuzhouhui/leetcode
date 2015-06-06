#include <stdlib.h>
#include <string.h>

struct node {
	int	val;
	struct node *next;
};

static struct node *get_node(struct node **head, int n)
{
	struct node **ptrptr, *ptr;
	int	i;

	if (n == 0) {
		ptr = *head;
		*head = (*head)->next;
		return(ptr);
	}

	ptrptr = head;
	for (i = 1; i <= n; i++)
		ptrptr = &(*ptrptr)->next;

	ptr = *ptrptr;
	*ptrptr = ptr->next;
	return(ptr);
}

char *getPermutation(int n, int k)
{
	int	i, t, p, j;
	char	*res;
	struct node *head, *tmp;

	t = 1;
	for (i = 1; i <= n; i++)
		t *= i;

	if (k < 1 || k > t)
		return(strdup(""));

	head = 0;
	for (i = 1; i <= n; i++) {
		if (!head) {
			head = tmp = malloc(sizeof(struct node));
			head->val = i;
			head->next = 0;
		} else {
			tmp->next = malloc(sizeof(struct node));
			tmp = tmp->next;
			tmp->val = i;
			tmp->next = 0;
		}
	}

	k--;
	t /= n;
	p = 0;
	res = malloc(n + 1);
	for (i = n - 1; i >= 1; i--) {
		j = k / t;
		tmp = get_node(&head, j);
		res[p++] = tmp->val + '0';
		free(tmp);
		k %= t;
		t /= i;
	}

	tmp = get_node(&head, 0);
	res[p++] = tmp->val + '0';
	free(tmp);
	res[p] = 0;
	return(res);
}

#include <stdio.h>
int main(void)
{
	printf("%s\n", getPermutation(3, 5));
	return(0);
}
