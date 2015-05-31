struct ListNode {
	int	val;
	struct ListNode *next;
};

#include <stdlib.h>

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *res, *tail, *tmp;
	int	c;

	if (!l1 && !l2) {
		res = calloc(1, sizeof(struct ListNode));
		return(res);
	}
	res = 0;
	c = 0;
	while (l1 && l2) {
		tmp = malloc(sizeof(struct ListNode));
		tmp->next = 0;
		tmp->val = l1->val + l2->val + c;
		if (tmp->val >= 10) {
			tmp->val -= 10;
			c = 1;
		} else {
			c = 0;
		}
		if (!res) {
			res = tail = tmp;
		} else {
			tail->next = tmp;
			tail = tmp;
		}
		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1) {
		tmp = malloc(sizeof(struct ListNode));
		tmp->next = 0;
		tmp->val = l1->val + c;
		if (tmp->val >= 10) {
			tmp->val -= 10;
			c = 1;
		} else {
			c = 0;
		}
		if (!res) {
			res = tail = tmp;
		} else {
			tail->next = tmp;
			tail = tmp;
		}
		l1 = l1->next;
	}

	while (l2) {
		tmp = malloc(sizeof(struct ListNode));
		tmp->next = 0;
		tmp->val = l2->val + c;
		if (tmp->val >= 10) {
			tmp->val -= 10;
			c = 1;
		} else {
			c = 0;
		}
		if (!res) {
			res = tail = tmp;
		} else {
			tail->next = tmp;
			tail = tmp;
		}
		l2 = l2->next;
	}

	if (c) {
		tmp = malloc(sizeof(struct ListNode));
		tmp->next = 0;
		tmp->val = c;
		tail->next = tmp;
	}

	return(res);
}

int main(void)
{}
