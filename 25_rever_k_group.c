#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	if (!head || !head->next || !k || k == 1)
		return(head);

	struct ListNode *newhead, *newtail, *start, *end, *t1, *t2;
	int	i;

	newhead = newtail = NULL;
	while (head) {
		end = start = head;
		i = 1;
		while (end && i < k) {
			end = end->next;
			i++;
		}
		if (!end) {
			if (!newhead)
				newhead = head;
			else 
				newtail->next = head;
			break;
		}
		head = end->next;
		t1 = end->next = NULL;
		end = start;
		while (start) {
			t2 = start;
			start = start->next;
			t2->next = t1;
			t1 = t2;
		}
		if (!newhead)
			newhead = t1;
		else
			newtail->next = t1;

		newtail = end;
	}
	return(newhead);
}

int main(void)
{
	struct ListNode *head;

	head = malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = malloc(sizeof(struct ListNode));
	head->next->next->val = 3;
	head->next->next->next = NULL;
	reverseKGroup(head, 2);
	return(0);
}
