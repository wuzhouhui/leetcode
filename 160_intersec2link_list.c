#include <stdio.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, 
		struct ListNode *headB)
{
	if (!headA || !headB)
		return(NULL);
	int	a_cnt, b_cnt;
	struct ListNode *a_tmp, *b_tmp;

	for (a_tmp = headA, a_cnt = 0; a_tmp; a_tmp = a_tmp->next)
		a_cnt++;
	for (b_tmp = headB, b_cnt = 0; b_tmp; b_tmp = b_tmp->next)
		b_cnt++;
	if (a_cnt > b_cnt) {
		a_cnt -= b_cnt;
		while (a_cnt > 0) {
			headA = headA->next;
			a_cnt--;
		}
	} else if (a_cnt < b_cnt) {
		b_cnt -= a_cnt;
		while (b_cnt > 0) {
			headB = headB->next;
			b_cnt--;
		}
	}

	while (headA && headB) {
		if (headA == headB)
			return(headA);

		headA = headA->next;
		headB = headB->next;
	}

	return(NULL);
}
