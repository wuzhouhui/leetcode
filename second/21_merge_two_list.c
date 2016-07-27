#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *newhead;
	struct ListNode **pprev = &newhead;
	struct ListNode *t;

	while (l1 && l2) {
		t = malloc(sizeof(*t));
		if (l1->val < l2->val) {
			t->val = l1->val;
			l1 = l1->next;
		} else {
			t->val = l2->val;
			l2 = l2->next;
		}
		*pprev = t;
		pprev = &t->next;
	}

	while (l1) {
		t = malloc(sizeof(*t));
		t->val = l1->val;
		l1 = l1->next;
		*pprev = t;
		pprev = &t->next;
	}

	while (l2) {
		t = malloc(sizeof(*t));
		t->val = l2->val;
		l2 = l2->next;
		*pprev = t;
		pprev = &t->next;
	}
	*pprev = 0;
	return(newhead);
}

main(){}
