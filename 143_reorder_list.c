#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

void reorderList(struct ListNode *head)
{
	if (!head || !head->next || !head->next->next)
		return;
	
	struct ListNode *head2;
	struct ListNode *p, *p2;
	int	i, n;

	head2 = head;
	n = 0;
	while (head2 != NULL) {
		n++;
		head2 = head2->next;
	}

	if (n % 2 == 0)
		n--;

	for (head2 = head, i = n / 2; i > 0; i--)
		head2 = head2->next;

	p = head2->next;
	head2->next = NULL;

	head2 = NULL;
	while (p) {
		p2 = p;
		p = p->next;
		p2->next = head2;
		head2 = p2;
	}

	p = head;
	while (p) {
		if (head2) {
			p2 = head2;
			head2 = head2->next;
			p2->next = p->next;
			p->next = p2;
			p = p2->next;
		} else {
			break;
		}
	}
}

int main(void)
{
	return(0);
}
