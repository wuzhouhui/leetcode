#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);

	struct ListNode *newhead, *prev, *p;
	struct ListNode *p2;

	newhead = head;
	head = head->next;
	newhead->next = NULL;
	while (head) {
		p = head;
		head = head->next;
		if (p->val <= newhead->val) {
			p->next = newhead;
			newhead = p;
			continue;
		}
		
		prev = newhead;
		p2 = newhead->next;
		while (p2 && p2->val < p->val) {
			prev = p2;
			p2 = p2->next;
		}
		p->next = p2;
		prev->next = p;
	}

	return(newhead);
}

int main(void)
{
	return(0);
}
