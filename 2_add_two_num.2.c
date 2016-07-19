#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *head;
	struct ListNode **pp = &head;
	struct ListNode *p1, *p2;
	int c = 0;

	while (l1 && l2) {
		p1 = l1;
		l1 = l1->next;
		p2 = l2;
		l2 = l2->next;
		int t = p1->val + p2->val + c;
		c = 0;
		if (t > 9) {
			c = 1;
			t -= 10;
		}
		*pp = malloc(sizeof(**pp));
		(*pp)->val = t;
		pp = &(*pp)->next;
	}
	while (l1) {
		p1 = l1;
		l1 = l1->next;
		int t = p1->val + c;
		c = 0;
		if (t > 9) {
			c = 1;
			t -= 10;
		}
		*pp = malloc(sizeof(**pp));
		(*pp)->val = t;
		pp = &(*pp)->next;
	}
	while (l2) {
		p1 = l2;
		l2 = l2->next;
		int t = p1->val + c;
		c = 0;
		if (t > 9) {
			c = 1;
			t -= 10;
		}
		*pp = malloc(sizeof(**pp));
		(*pp)->val = t;
		pp = &(*pp)->next;
	}
	if (c) {
		*pp = malloc(sizeof(**pp));
		(*pp)->val = c;
		pp = &(*pp)->next;
	}
	*pp = NULL;
	return(head);
}

main(void){}
