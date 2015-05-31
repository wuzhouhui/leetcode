#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
	if (!head)
		return(NULL);

	struct ListNode *p1, *p2;

	while (head && head->val == val) {
		p1 = head;
		head = head->next;
		free(p1);
	}

	if (!head)
		return(NULL);

	p1 = head;
	p2 = head->next;
	while (p2) {
		if (p2->val == val) {
			p1->next = p2->next;
			free(p2);
			p2 = p1->next;
			continue;
		}
		p1 = p2;
		p2 = p2->next;
	}

	return(head);
}

int main(void)
{}
