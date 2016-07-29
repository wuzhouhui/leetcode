#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

static struct ListNode *merge(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *newhead, *t;
	struct ListNode **pprev = &newhead;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			t = l1;
			l1 = l1->next;
		} else {
			t = l2;
			l2 = l2->next;
		}
		*pprev = t;
		pprev = &t->next;
	}
	while (l1) {
		t = l1;
		l1 = l1->next;
		*pprev = t;
		pprev = &t->next;
	}
	while (l2) {
		t = l2;
		l2 = l2->next;
		*pprev = t;
		pprev = &t->next;
	}
	*pprev = 0;
	return(newhead);
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	if (listsSize <= 0)
		return(0);
	if (listsSize <= 1)
		return(lists[0]);
	int t = listsSize / 2;
	struct ListNode *l1 = mergeKLists(lists, t);
	struct ListNode *l2 = mergeKLists(lists + t, listsSize - t);
	return(merge(l1, l2));
}

main(){}
