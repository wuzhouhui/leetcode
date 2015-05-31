#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *head, *tmp;

	head = NULL;
	while (l1 && l2) {
		if (!head) {
			head = tmp = calloc(1, sizeof(struct ListNode));
		} else {
			tmp->next = calloc(1, sizeof(struct ListNode));
			tmp = tmp->next;
		}
		if (l1->val < l2->val) {
			tmp->val = l1->val;
			l1 = l1->next;
		} else if (l1->val > l2->val) {
			tmp->val = l2->val;
			l2 = l2->next;
		} else {
			tmp->val = l1->val;
			tmp->next = calloc(1, sizeof(struct ListNode));
			tmp = tmp->next;
			tmp->val = l1->val;
			l1 = l1->next;
			l2 = l2->next;
		}
	}

	while (l1) {
		if (!head) {
			head = tmp = calloc(1, sizeof(struct ListNode));
		} else {
			tmp->next = calloc(1, sizeof(struct ListNode));
			tmp = tmp->next;
		}
		tmp->val = l1->val;
		l1 = l1->next;
	}
	while (l2) {
		if (!head) {
			head = tmp = calloc(1, sizeof(struct ListNode));
		} else {
			tmp->next = calloc(1, sizeof(struct ListNode));
			tmp = tmp->next;
		}
		tmp->val = l2->val;
		l2 = l2->next;
	}

	return(head);
}

int main(void)
{}
